#pragma once

#include <math.h>
#include <units/velocity.h>
#include <units/acceleration.h>
#include <units/voltage.h>
#include <units/angular_velocity.h>
#include "string"
#include "frc/I2C.h"
#include <frc/Filesystem.h>
#include <frc/controller/RamseteController.h>

using namespace std;

#define M_PI 3.14159265358979323846 //for simulation

namespace GeneralConstants{
    const double TICKS_PER_ROTATION = 4096.0;
    const double TICKS_PER_RADIAN = TICKS_PER_ROTATION/(2*M_PI);
}

namespace InputConstants{
    const int XBOX_PORT = 2;
    const int XBOX_LJOY_X = 0;
    const int XBOX_LJOY_Y = 1;
    const int XBOX_LTRIGGER = 2;
    const int XBOX_RTRIGGER = 3;
    const int XBOX_RJOY_X = 4;
    const int XBOX_RJOY_Y = 5;
}

namespace ArmConstants{
    const int BASE_MOTOR_ID = 6;
    const int BASE_MOTOR_ID2 = 15;
    const int TOP_MOTOR_ID = 8;
    const int TOP_MOTOR_ID2 = 1;

    const int BASE_BRAKE_ID = 4;
    const int TOP_BRAKE_ID = 5;

    const double BASE_MIN_ANG = -2.0943951;
	const double BASE_MAX_ANG = 2.0943951;

    const double TOP_MIN_ANG = 0.0;
	const double TOP_MAX_ANG = 3.4906585;

    const double BASE_ARM_LENGTH = 0.762;
    const double TOP_ARM_LENGTH = 0.762;
    const double PIVOT_HEIGHT = 0.508;

    const double BASE_OFFSET = 0.0; //Radians
    const double TOP_OFFSET = 0.0; //Radians

    const double BASE_PID[3] = {0.0, 0.0, 0.0}; //Error in radians
    const double BASE_KGRAVITY = 0;
    const double TOP_PID[3] = {0.0, 0.0, 0.0}; //Error in radians
    const double TOP_KGRAVITY = 0.0;

    const double BOT_ARM_SLACK = 1.2217302;
    const double TOP_ARM_SLACK = -1.2217302;

    const double MAX_VOLTS = 5;
}
