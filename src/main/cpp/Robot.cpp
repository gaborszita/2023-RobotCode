#include "Robot.h"

#include <fmt/core.h>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  navx_ = new AHRS(frc::SPI::Port::kMXP);
  swerveDrive_ = new SwerveDrive(navx_, limelight_);
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  swerveDrive_->initializeAutoTraj(SwerveConstants::twoBallPath); //todo would be done with auto chooser
}

void Robot::AutonomousPeriodic() {
  swerveDrive_->setState(SwerveDrive::State::PATH_FOLLOW); //todo would be moved into auto executor
  swerveDrive_->Periodic(0_mps, 0_mps, 0_rad / 1_s, 0);
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
