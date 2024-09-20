#pragma once

#include "ppm/PPMMotor.h"
#include "motorcontrol/PPMFlipsky.h"
#include <frc/Joystick.h>
#include <frc/XboxController.h>

#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/angular_velocity.h>

struct TankConfig {
  PPMFlipsky leftFront;
  PPMFlipsky leftBack;
  PPMFlipsky rightFront;
  PPMFlipsky rightBack;
  double trackWidth;
};


class TankDrivebase {
 public:
  TankDrivebase(TankConfig *tankConfig, frc::XboxController *joystick);
  
  void UpdateSpeeds();
  void Halt();


 private:
  TankConfig *_config;
  frc::XboxController *_joystick;

  double _halvedWheelDistance;

  double driveDeadzone = 0.05;
  double twistDeadzone = 0.01;

  double maxSpeed = 0.5;

  const double maxForwardSpeed = 10; // * 0.66 for children safety factor
  double maxRotationSpeed = 24;

  double accelerationPerTick = maxForwardSpeed / 50;

  double rightMotorSpeed = 0;
  double leftMotorSpeed = 0;

  double maxMotorSpeed = maxForwardSpeed + _halvedWheelDistance * maxRotationSpeed;
};