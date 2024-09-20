#pragma once

#include <iostream>

#include <frc/Joystick.h>
#include <frc/Servo.h>

#include "motorcontrol/MotorController.h"
#include "motorcontrol/PPMFlipsky.h"

#include "TankDrive.h"
#include "ElevatorLift.h"

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>


#include <units/length.h>
#include <units/time.h>
#include <units/voltage.h>

struct RobotMap {
  struct Controllers {
    frc::XboxController primary{0};
  };
  Controllers controllers;

  TankConfig tankConfig {
    PPMFlipsky{9},
    PPMFlipsky{1},
    PPMFlipsky{8},
    PPMFlipsky{0},
    0.64
  };

  ElevatorConfig elevatorConfig {
    // std::nullptr_t,
  };

};