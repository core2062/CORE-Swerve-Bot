#pragma once

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/AnalogInput.h>
#include <ctre/Phoenix.h>
#include <ctre/phoenix/motorcontrol/TalonFXSensorCollection.h>
#include <AHRS.h>
#include <CORERobotLib.h>
#include <COREFramework/COREScheduler.h>
#include <COREUtilities/CORETimer.h>
#include "Config.h"

using namespace CORE;
using namespace frc;

enum class DriveSide{LEFT = 1, RIGHT = 2, BOTH = 3};

class DriveSubsystem : public CORESubsystem {
public:
	DriveSubsystem();
	void robotInit() override;
	void teleopInit() override;
	void teleop() override;
	
	void initTalons();
	void resetEncoder();
	AHRS ahrs;

private:
	//m_analogSupplyVoltage used in calculation to get current PSI
	AnalogInput m_analogPressureInput, m_analogSupplyVoltage;

	TalonFX m_leftFrontDrive, m_leftFrontAngle, m_leftBackDrive, m_leftBackAngle, m_rightBackDrive, m_rightBackAngle, m_rightFrontDrive, m_rightFrontAngle;

    COREConstant<double> m_ticksPerInch, m_wheelBase, m_trackWidth;
    Compressor m_compressor;
};
