#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include "string"
#include "frc/Filesystem.h"

using namespace std;

#define pi 3.1415

namespace GeneralConstants
{
    const double g = 9.81;

    const int MAX_RPM = 6380;
    const int TICKS_PER_ROTATION = 2048;

    const double FREE_SPEED = 6380;
    const double FREE_CURRENT = 1.5;
    const double STALL_CURRENT = 257;
    const double MAX_VOLTAGE = 12;

    const double RESISTANCE = MAX_VOLTAGE/STALL_CURRENT;
    const double Kv = ((FREE_SPEED * 2 * pi) / 60 ) / (MAX_VOLTAGE - FREE_CURRENT * RESISTANCE);

    const double CONE_M = 0.652;

}

namespace FieldConstants
{
    const double FIELD_WIDTH = 8.2296;
    const double FIELD_LENGTH = 16.4592;
    // const double LEFT_TAG_X = 1.05283; //41.45 in
    // const double MIDDLE_TAG_X = 2.72923; //107.45 in
    // const double RIGHT_TAG_X = 4.40563; //173.45;

    /**
     * Tag Positions in the form of 
     * TAG_XY[TagID -1] = {x, y}
    */
    const double TAG_XY[8][2] = {
    {15.513558, 1.071626}, 
    {15.513558, 2.748026}, 
    {15.513558, 4.424426}, 
    {16.178784, 6.749796}, 
    {0.36195, 6.749796}, 
    {1.02743, 4.424426}, 
    {1.02743, 2.748026}, 
    {1.02743, 1.071626}};

    const double BOTTOM_CONE_Y = 0.513;
    const double TOP_CONE_Y = 4.977;
    const double BOTTOM_CUBE_Y = 1.072;
    const double TOP_CUBE_Y = 4.424;

    const double BLUE_SCORING_X = 1.923; //1.823
    const double RED_SCORING_X = 14.617; //14.718

    const double AUTO_DOCK_Y = 2.748;
    const double BLUE_AUTO_DOCK_X = 2.412;
    const double RED_AUTO_DOCK_X = 14.130;

    const double BOTTOM_PIECE_Y = 0.919;
    const double BOTTOM_MID_PIECE_Y = 2.138;
    const double TOP_MID_PIECE_Y = 3.358;
    const double TOP_PIECE_Y = 4.577;

    const double BLUE_PIECE_X = 7.068;
    const double RED_PIECE_X = 9.474;
}

namespace InputConstants
{
    const int LJOY_PORT = 0;
    const int LJOY_X = 0;
    const int LJOY_Y = 1;

    const int RJOY_PORT = 1;
    const int RJOY_X = 0;
    const int RJOY_Y = 1;

    const int XBOX_PORT = 2;
    const int XBOX_LJOY_X = 0;
    const int XBOX_LJOY_Y = 1;
    const int XBOX_LTRIGGER = 2;
    const int XBOX_RTRIGGER = 3;
    const int XBOX_RJOY_X = 4;
    const int XBOX_RJOY_Y = 5;

    const int OUTAKE_BUTTON = 3;
    const int INTAKE_BUTTON = 4;
    
    const int A_BUTTON = 1;
    const int B_BUTTON = 2;
    const int X_BUTTON = 3;
    const int Y_BUTTON = 4; 
    const int L_BUMPER = 5;
    const int R_BUMPER = 6; 
    const int CLIMB_MODE_TOGGLE_BUTTON = 7;
    const int FIELD_ORIENT_BUTTON = 8;

    const int BUTTON_BOARD_PORT = 3;
    const int B1 = 1;
    const int B2 = 2;
    const int B3 = 3;
    const int B4 = 4;
    const int B5 = 5;
    const int B6 = 6;
    const int B7 = 7;
    const int B8 = 8;
    const int B9 = 9;

}

namespace SwerveConstants
{
    const double WIDTH = 29; //Change to 22 
    const double LENGTH = 29;
    const double WHEEL_DIAGONAL = 0.8128;
    const double TREAD_RADIUS = 0.0508; 
    const double DRIVE_GEAR_RATIO = 1/6.12; 

    //const double trPosAngle = atan2((SwerveConstants::WIDTH/2), (SwerveConstants::LENGTH/2));
    //const double tlPosAngle = -trPosAngle;
    //const double brPosAngle = 180 - trPosAngle;
    //const double blPosAngle = trPosAngle - 180;

    const int TR_DRIVE_ID = 4; //13, 3
    const int TL_DRIVE_ID = 23; //11, 1
    const int BR_DRIVE_ID = 1; //18, 4
    const int BL_DRIVE_ID = 22; //15, 22

    const int TR_TURN_ID = 10; //14, 5
    const int TL_TURN_ID = 5; //12, 7
    const int BR_TURN_ID = 7; //17, 10
    const int BL_TURN_ID = 19; //16, 19

    const int TR_CANCODER_ID = 8; //62, 2
    const int TL_CANCODER_ID = 2; //10, 9
    const int BR_CANCODER_ID = 9; //8, 8
    const int BL_CANCODER_ID = 6; //42, 6
    
    const double TR_CANCODER_OFFSET = 173.75; //172.7
    const double TL_CANCODER_OFFSET = 175.8; //177.02
    const double BR_CANCODER_OFFSET = 74.26; //75.85
    const double BL_CANCODER_OFFSET = 41.6; //43.2

    const double MAX_LA = 2;//3
    const double MAX_LV = 3;//4
    const double MAX_AA = 360;//270
    const double MAX_AV = 540;//450

    const double klV = 0.495; //If you increase pd, check auto lineup
    const double klVI = -0.328;
    const double klA = 4.11;
    const double klP = 0.2; //0.05 (0.2, 0.2?)
    const double klD = 0.2;

    const double kaV = 34.2064;
    const double kaVI = -25.4095;
    const double kaA = 0;
    const double kaP = 0.06; //0.008
    const double kaD = 0;

}

namespace TwoJointArmConstants
{
	const double UPPER_ARM_LENGTH = 0.7239; //0.635 for prototype, 0.7239 for real
	const double FOREARM_LENGTH = 0.6985; //0.7112 for prototype, 0.6985 for real
    const double EE_LENGTH = 0.3683;
    const double MOUNTING_HEIGHT = 0.4318;
	
	const double SHOULDER_MIN_ANG = -90;
	const double SHOULDER_MAX_ANG = 90;
	const double ELBOW_MIN_ANG = 0;
	const double ELBOW_MAX_ANG = 360;

	const double SHOULDER_ARM_MAX_VEL = 180;
	const double ELBOW_ARM_MAX_VEL = 180*5;
	const double SHOULDER_ARM_MAX_ACC = 180;
	const double ELBOW_ARM_MAX_ACC = 180*5;

    const int SHOULDER_MASTER_ID = 6;
    const int SHOULDER_SLAVE_ID = 15;
    const int ELBOW_MASTER_ID = 8;
    const int ELBOW_SLAVE_ID = 1;
    const int SHOULDER_BRAKE_ID = 4;
    const int ELBOW_BRAKE_ID = 5;
    const int SHOULDER_ENCODER_ID = 0;
    const double SHOULDER_ENCODER_OFFSET = 0;

    const double UPPER_ARM_I = 0.19;
    const double FOREARM_I = 0.15;

    const double UPPER_ARM_M = 2.53; //2.53, 0.114
    const double FOREARM_M = 1.41; //1.41, 0.114

    const double UPPER_ARM_COM_DIST = 0.304; //0.304, 0.381
    const double FOREARM_COM_DIST = 0.26; //0.26, 0.381

    const double SHOULDER_I = UPPER_ARM_I + UPPER_ARM_M * UPPER_ARM_COM_DIST * UPPER_ARM_COM_DIST;
    const double ELBOW_I = FOREARM_I + FOREARM_M * FOREARM_COM_DIST * FOREARM_COM_DIST;

    const double SHOULDER_KV = 13.0357;
    const double SHOULDER_KVI = -13.1786;
    const double ELBOW_KV = 42.352;
    const double ELBOW_KVI = -30.8963;

    const double skD_ = 0.05;
    const double skP_ = 0.05;
    const double ekD_ = 0;
    const double ekP_ = 0.15;

    const double SHOULDER_TO_ELBOW_RATIO = 30.0 / 54.0; //30:54
    const double MOTOR_TO_SHOULDER_RATIO = 1.0 / 243.911; // 1:194.4 (243.911), 1:100
    const double MOTOR_TO_ELBOW_RATIO = 1.0 / 43.556; //1:40.5 (43.556) for motor to shoulder area, 1:72.9 for motor to elbow joint

    const double HIGH_CUBE_OUTAKE_VOLTS = -1;
    const double MID_CUBE_OUTAKE_VOLTS = -1;

    // //stowed
	// const double sX = 0.17136;
	// const double sY = -0.33516;
	// const double sTheta = 8.22;
	// const double sPhi = 167.95;

	// //cube intake
	// const double ciX = 0.531859;
	// const double ciY = -0.330244;
	// const double ciTheta = 19.73;
	// const double ciPhi = 144;

	// //player station
	// const double psX = 0.58348;
	// const double psY = 0.391336;
	// const double psTheta = -38.74;
	// const double psPhi = 137.76;

	// //mid
	// const double mX = 1.17477;
	// const double mY = 0.3640;
	// const double mTheta = 15.05;
	// const double mPhi = 93.01;

	// //high
	// const double hX = 1.5710;
	// const double hY = 0.73798;
	// const double hTheta = 55.2;
	// const double hPhi = 16.2;

    // //cube mid
	// const double cmX = 0.8245;
	// const double cmY = 0.27752;
	// const double cmTheta = -10.32;
	// const double cmPhi = 124.24;

	// //cube high
	// const double chX = 1.2543;
	// const double chY = 0.53706;
	// const double chTheta = 18.2;
	// const double chPhi = 79.44;

	// //cone intake
	// const double iX = 0.531859;
	// const double iY = -0.330244;
	// const double iTheta = 19.73;
	// const double iPhi = 144;

    const double ARM_POSITIONS[8][4] = 
    {
        {0.181286, -0.35166, 9.72, 167.11}, //stowed
        {0.52316, -0.31130, 14.72, 146.74}, //cube intake
        {0.74178, 0.32868, -21.74, 130.54}, //player station
        {1.15245, 0.3682, 11.3, 97.38}, //mid
        {1.6045, 0.7533, 54.93, 16.63}, //high
        {0.82036, 0.2747, -12.35, 126.27}, //cube mid
        {1.26966, 0.5426368, 17.14, 80.9}, //cube high
        {0.52316, -0.31130, 14.72, 146.74} //cone intake
    };

    const int STOWED_NUM = 0;
    const int CUBE_INTAKE_NUM = 1;
    const int PLAYER_STATION_NUM = 2;
    const int MID_NUM = 3;
    const int HIGH_NUM = 4;
    const int CUBE_MID_NUM = 5;
    const int CUBE_HIGH_NUM = 6;
    const int CONE_INTAKE_NUM = 7;

    const double ANGLE_ERROR_THRESHOLD = 5; //TODO check value

}

namespace ClawConstants
{
    const int PNEUMATIC_ID = 0; //TODO get value
    const int WHEEL_MOTOR_ID = 11;
    const double INTAKING_SPEED = 0.5;
    const double OUTAKING_SPEED = -0.1;
}

namespace CubeIntakeConstants {
    const int DEPLOYER_MOTOR_ID = 0; // TODO get value
    const int ROLLER_MOTOR_ID = 0; // TODO get value

    const double ENCODER_DEPLOYED_TARGET = 512;

    const double DEPLOYER_MAX_VOLTAGE = 0;    // TODO measure capped voltage for deployer
    const double ROLLER_MAX_VOLTAGE = 0;      // TODO measure voltage for cube to actually pass through

    const double kP = 0; // TODO tune
    const double kI = 0; // TODO tune
    const double kD = 0; // TODO tune

    const double MAX_VELOCITY = M_PI / 2;   // TODO tune - radians per second
    const double MAX_ACCELERATION = M_PI;   // TODO tune - radians per second squared

    const double POS_ERR_TOLERANCE = 0.01;  // TODO tune - error tolerance, in radians
    const double VEL_ERR_TOLERANCE = 0.1;   // TODO tune - error tolerance, in radians/s
} // namespace CubeIntakeConstants