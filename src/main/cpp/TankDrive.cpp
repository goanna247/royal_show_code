#include "TankDrive.h"
#include <iostream>
#include <frc/smartdashboard/smartdashboard.h>

TankDrivebase::TankDrivebase(TankConfig *tankConfig, frc::XboxController *joystick) : _config(tankConfig), _joystick(joystick) {
  _halvedWheelDistance = tankConfig->trackWidth / 2;
}


void TankDrivebase::UpdateSpeeds() {
  double joystickYValue = _joystick->GetLeftY();
  double joystickRightYValue = _joystick->GetRightY();
  // // double twistValue = _joystick->GetTwist();

  if (_joystick->GetAButtonPressed()) {
    maxSpeed += 0.1;
  }

  if (_joystick->GetYButtonPressed()) {
    maxSpeed -= 0.1;
  }

  frc::SmartDashboard::PutNumber("Max speed", maxSpeed);

  double leftWheelVelocity = joystickYValue;
  leftWheelVelocity *= maxSpeed;
  double rightWheelVelocity = joystickRightYValue;
  rightWheelVelocity *= maxSpeed;
  rightWheelVelocity *= -1;
  
  
  // joystickYValue = std::abs(joystickYValue) > driveDeadzone ? joystickYValue : 0;
  // twistValue = std::abs(twistValue) > twistDeadzone ? -twistValue : 0;

  // double forwardSpeed = joystickYValue * maxForwardSpeed;
  // if (forwardSpeed < 0.05) {maxRotationSpeed = 36; } else {maxRotationSpeed = 24;}
  
  // double rotationSpeed = twistValue * maxRotationSpeed;


  // double leftWheelVelocity = forwardSpeed + _halvedWheelDistance * rotationSpeed;
  // double rightWheelVelocity = -(forwardSpeed - _halvedWheelDistance * rotationSpeed);

  // double maxLeftRequested = leftWheelVelocity / maxMotorSpeed; 
  // double maxRightRequested = rightWheelVelocity / maxMotorSpeed;

  // // if (maxLeftRequested > abs(leftMotorSpeed)) {
  // //   int leftSign = leftMotorSpeed != 0 ? leftMotorSpeed/abs(leftMotorSpeed) : (leftWheelVelocity != 0 ? leftWheelVelocity / abs(leftWheelVelocity) : 1);
  // //   int rightSign = rightMotorSpeed != 0 ? rightMotorSpeed/abs(rightMotorSpeed) : (rightWheelVelocity != 0 ? rightWheelVelocity / abs(rightWheelVelocity) : 1);
  // //   leftMotorSpeed = leftSign * std::max(0, std::min(accelerationPerTick + abs(leftMotorSpeed), abs(maxLeftRequested)));
  // //   rightMotorSpeed = rightSign * std::max(0, std::min(accelerationPerTick + abs(rightMotorSpeed), abs(maxRightRequested)));
  // // }
  // // else {
  // //   leftMotorSpeed = leftWheelVelocity / maxMotorSpeed;
  // //   rightMotorSpeed = rightWheelVelocity / maxMotorSpeed; 
  // // }
  

  std::cout << "LEFT: " << leftWheelVelocity << std::endl;
  std::cout << "RIGHT: " << rightWheelVelocity << std::endl;
  _config->leftFront.set(leftWheelVelocity);
  _config->leftBack.set(leftWheelVelocity);
  _config->rightFront.set(-rightWheelVelocity);
  _config->rightBack.set(-rightWheelVelocity);

}

void TankDrivebase::Halt() {
  _config->leftFront.set(0);
  _config->leftBack.set(0);
  _config->rightFront.set(0);
  _config->rightBack.set(0);
}