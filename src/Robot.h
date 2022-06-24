#pragma once

#include <string>
#include <iostream>
#include <frc/TimedRobot.h>
#include <CORERobotLib.h>
#include <COREFramework/COREScheduler.h>

#include "DriveSubsystem.h"
#include "Config.h"

// #include "Auton/TestRoutine.h"
// #include "Auton/DriveRoutine.h"

using namespace CORE;
using namespace std;

class Robot : public CORERobot {
    public:
        Robot();
        void robotInit() override;
        void teleopInit() override;
        void teleop() override;
        void test() override;
        void testInit() override;
        static Robot * GetInstance();
        DriveSubsystem driveSubsystem;
    private:
        static Robot * m_instance;
};
