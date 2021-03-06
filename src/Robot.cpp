#include "Robot.h"

Robot* Robot::m_instance;

Robot::Robot() {
    CORELog::LogInfo("Starting up Robot!");
    m_instance = this;
}

void Robot::teleop() {}

void Robot::robotInit() {}

void Robot::teleopInit() {}

void Robot::test() {}

void Robot::testInit() {}

Robot * Robot::GetInstance() {
    return m_instance;
}

#ifndef RUNNING_FRC_TESTS
int main() {
    return frc::StartRobot<Robot>();
}
 #endif