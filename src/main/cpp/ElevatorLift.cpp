#include "ElevatorLift.h"


ElevatorLift::ElevatorLift( frc::XboxController *joystick) : _joystick(joystick) {}

void ElevatorLift::SetSetpoint(units::meter_t setpoint) {
  _setpoint = setpoint;
}


void ElevatorLift::OnUpdate() {
  if (_joystick->GetRightTriggerAxis() > 0.05) {
    motor->Set(0.2);
  } else if (_joystick->GetLeftTriggerAxis() > 0.05) {
    motor->Set(-0.2);
  } else {
    motor->Set(0);
  }



  // if (_joystick->GetTriggerPressed()) {
  //   _setpoint = (_config->maxHeight - _config->minHeight) * ((_joystick->GetZ() + 1) / 2) + _config->minHeight;
    
  //   double relativeDifference = (_setpoint - _currentHeight) / (_config->maxHeight - _config->minHeight);

  //   relativeDifference = relativeDifference > 1 ? 1 : relativeDifference;
  //   relativeDifference = relativeDifference < 0 ? 0 : relativeDifference;

  //   double elevatorPower = std::tanh((1.5 * std::pow(relativeDifference, 3) + 0.3 * relativeDifference));
  //   _config->motor.set(elevatorPower);
  //   _currentHeight += CalculateDisplacement(elevatorPower, dt.value());

  // } else {
  //   _config->motor.set(0);
  // }

}