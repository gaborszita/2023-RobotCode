/**
 * Motor-deployed intake, opposed to pneumatics-deployed
 */

#ifndef MOTOR_INTAKE_H
#define MOTOR_INTAKE_H

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <string>

#include <ctre/Phoenix.h>
#include <frc/controller/ProfiledPIDController.h>
#include <frc/controller/ArmFeedForward.h>
#include <frc/fmt/Units.h>
#include <frc/Timer.h>
#include <frc/trajectory/TrapezoidProfile.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <rev/CANSparkMax.h>
#include <units/angle.h>
#include <units/angular_acceleration.h>
#include <units/angular_velocity.h>
#include <units/time.h>

#include "Constants.h"
#include "Helpers.h"

/**
 * Intake that is deployed by a motor (rather than pneumatics)
 *
 * This should be used with the cone intake.
 *
 * @note The roller is stopped if the deployer is not down, so if smartdashboard says "Intake"
 * or "Outtake" even though it is not spinning, first check if the deployer is not down.
 *
 * @warning Check if IsClearForArm() is true before moving the arm!!!!!!!!!!
 */
class MotorIntake
{
public:
  // deployer state machine
  enum DeployerState
  {
    STOWED,    // if at position in frame perimeter
    GROUND,    // if currently at "ground" position (for intaking cone)
    MIDDLE,    // if currently at the middle position for intaking
    MIDDLING,  // if going to the middle position
    STOWING,   // if currently going to frame perimeter
    GROUNDING, // if currently going to the "ground" position
  };

  // roller state machine
  enum RollerState
  {
    INTAKE,   // roller spins such that it's intaking
    STOP,     // roller does not spin
    OUTTAKE,  // roller spins such that it's outtaking
    MAINTAIN, // Keep cone in roller
  };

  /// overall state machine
  /// @deprecated unused
  enum ConeIntakeState
  {
    IDLE,       // stored in the robot with no cone inside
    IDLING,     // currently stowing the cone intake without a cone
    CONSUMING,  // currently intaking the cone and stowing it
    SPITTING,   // currently lowering the intake (with cone inside)
    CONSUMED,   // cone is in the robot and stored
    INTAKE_DOWN // the intake is down and the rollers are spinning to spit out the cone
  };

  MotorIntake(bool = true, bool = false, bool = false);

  void RobotInit();
  void Periodic();
  void DisabledInit();

  void Ground();
  void Middle();
  void Stow();
  void WaitForCone();
  void Spit();
  void HandoffToArm();

  bool IsClearForArm();
  bool IsReadyForHandoff();

  DeployerState getDeployerState();
  RollerState getRollerState();

  void PutDebug();
  void PutConstants();
  void SetConstants();

  void Reset();
  void ResetStates();
  void ResetEncoderPosition();
  void ResetPID();
  void ResetAcceleration();

  // --------------------- DEPRECATED -------------------

  void Consume();
  void Idle();
  bool IsStored();
  bool IntakeDown();
  bool IsIdle();

private:
  // state machines
  DeployerState m_deployerState{STOWING};
  RollerState m_rollerState{STOP};
  ConeIntakeState m_intakeState{IDLE};

  // motors
  rev::CANSparkMax m_deployerMotor{MotorIntakeConstants::DEPLOYER_MOTOR_ID, rev::CANSparkMax::MotorType::kBrushless}; // for deploying the intake
  rev::SparkMaxRelativeEncoder m_deployerMotorEncoder{m_deployerMotor.GetEncoder()};
  // WPI_TalonFX m_deployerMotor{2};
  WPI_TalonFX m_rollerMotor{MotorIntakeConstants::ROLLER_MOTOR_ID}; // for spinning the rollers

  // motion profiled pid controller
  frc::TrapezoidProfile<units::radians>::Constraints m_constraints{
      units::radians_per_second_t{MotorIntakeConstants::MAX_VELOCITY},
      units::radians_per_second_squared_t{MotorIntakeConstants::MAX_ACCELERATION}};
  frc::ProfiledPIDController<units::radians> m_pid{
      MotorIntakeConstants::kP,
      MotorIntakeConstants::kI,
      MotorIntakeConstants::kD,
      m_constraints};

  typedef units::compound_unit<units::volts, units::inverse<units::radians_per_second>> kVUnit;
  typedef units::compound_unit<units::volts, units::inverse<units::radians_per_second_squared>> kAUnit;
  typedef units::unit_t<kVUnit> kVUnit_t;
  typedef units::unit_t<kAUnit> kAUnit_t;

  frc::ArmFeedforward m_feedForward{units::volt_t{MotorIntakeConstants::kS},
                                    units::volt_t{MotorIntakeConstants::kG},
                                    kVUnit_t{MotorIntakeConstants::kV},
                                    kAUnit_t{MotorIntakeConstants::kA}};

  // feedforward stuff
  units::radians_per_second_t m_lastSpeed{units::radians_per_second_t{0}};
  units::second_t m_lastTime{frc::Timer::GetFPGATimestamp()};

  // if info should be shown on smartdashboard or not
  bool m_showSmartDashboard;
  bool m_showConstants;
  bool m_showDebug;

  // constants
  double m_groundGoal = MotorIntakeConstants::GROUND_GOAL;
  double m_stowedGoal = MotorIntakeConstants::STOWED_GOAL;
  double m_middleGoal = MotorIntakeConstants::MIDDLE_GOAL;
  double m_deployerMaxVoltage = MotorIntakeConstants::DEPLOYER_MAX_VOLTAGE;
  double m_rollerIntakeVoltage = MotorIntakeConstants::ROLLER_INTAKE_VOLTAGE;
  double m_rollerOuttakeVoltage = MotorIntakeConstants::ROLLER_OUTTAKE_VOLTAGE;
  double m_rollerStallCurrent = MotorIntakeConstants::ROLLER_STALL_CURRENT;
  double m_kP = MotorIntakeConstants::kP;
  double m_kI = MotorIntakeConstants::kI;
  double m_kG = MotorIntakeConstants::kG;
  double m_kD = MotorIntakeConstants::kD;
  double m_kS = MotorIntakeConstants::kS;
  double m_kA = MotorIntakeConstants::kA;
  double m_kV = MotorIntakeConstants::kV;
  double m_maxVel = MotorIntakeConstants::MAX_VELOCITY;
  double m_maxAcc = MotorIntakeConstants::MAX_ACCELERATION;
  double m_posErrTolerance = MotorIntakeConstants::POS_ERR_TOLERANCE;
  double m_velErrTolerance = MotorIntakeConstants::VEL_ERR_TOLERANCE;

  // util methods
  units::radian_t m_getEncoderRadians();

  bool m_MotorsNotNeeded();

  void m_DeployerStateMachine();
  void m_RollerStateMachine();

  void m_PutCurrentDeployerState();
  void m_PutCurrentRollerState();
  void m_PutCurrentConeIntakeState();

  bool m_AtGoal(double, double, double);

  void m_SetDeployerVoltage(double);
};

#endif