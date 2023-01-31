#pragma once

#include <frc/Joystick.h>
#include "Constants.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>

class Controls
{
    public:
        Controls();
        double getXStrafe();
        double getYStrafe();
        bool A_IsPressed();

    private:
        frc::Joystick xbox_;
};