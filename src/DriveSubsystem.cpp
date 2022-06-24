#include "DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() :
		ahrs(SPI::Port::kMXP),
		m_analogPressureInput(0),
		m_analogSupplyVoltage(1),

		m_leftFrontDrive(LEFT_FRONT_DRIVE_PORT),
		m_leftFrontAngle(LEFT_FRONT_ANGLE_PORT),
		m_leftBackDrive(LEFT_BACK_DRIVE_PORT),
		m_leftBackAngle(LEFT_BACK_ANGLE_PORT),
		m_rightBackDrive(RIGHT_BACK_DRIVE_PORT),
		m_rightBackAngle(RIGHT_BACK_ANGLE_PORT),
		m_rightFrontDrive(RIGHT_FRONT_DRIVE_PORT),
		m_rightFrontAngle(RIGHT_FRONT_ANGLE_PORT),
		
        m_ticksPerInch("Ticks Per Inch", (4 * 3.1415) / 1024),
        m_wheelBase("Wheel Base", 1),
        m_trackWidth("Track Width", 1),
        
		m_compressor(frc::PneumaticsModuleType::REVPH) {
}

void DriveSubsystem::robotInit() {
	// Registers joystick axis and buttons, does inital setup for talons
    initTalons();
}

void DriveSubsystem::teleopInit() {
	initTalons();
	m_compressor.EnableDigital();
}

void DriveSubsystem::teleop() {
	// Code for teleop. Sets motor speed based on the values for the joystick, runs compressor,
	// Toggles gears
    double mag = -driverJoystick->GetAxis(CORE::COREJoystick::JoystickAxis::LEFT_STICK_Y);
	double rot = driverJoystick->GetAxis(CORE::COREJoystick::JoystickAxis::RIGHT_STICK_X);

	SmartDashboard::PutNumber("Robot Heading", ahrs.GetFusedHeading());
	
	SmartDashboard::PutNumber("Pressure", (250* (m_analogPressureInput.GetVoltage()/m_analogSupplyVoltage.GetVoltage())-25));


}

void DriveSubsystem::initTalons() {
	// Sets up talons
	m_leftFrontDrive.Set(ControlMode::PercentOutput, 0);
	m_leftBackDrive.Set(ControlMode::PercentOutput, 0);
	m_rightBackDrive.Set(ControlMode::PercentOutput, 0);
	m_rightFrontDrive.Set(ControlMode::PercentOutput, 0);

	m_leftFrontAngle.Set(ControlMode::PercentOutput, 0);
	m_leftBackAngle.Set(ControlMode::PercentOutput, 0);
	m_rightBackAngle.Set(ControlMode::PercentOutput, 0);
	m_rightFrontAngle.Set(ControlMode::PercentOutput, 0);

	// Encoder Functions
    m_leftFrontDrive.SetStatusFramePeriod(StatusFrameEnhanced::Status_1_General, 10, 0);
    m_leftBackDrive.SetStatusFramePeriod(StatusFrameEnhanced::Status_1_General, 10, 0);
    m_rightBackDrive.SetStatusFramePeriod(StatusFrameEnhanced::Status_1_General, 10, 0);
    m_rightFrontDrive.SetStatusFramePeriod(StatusFrameEnhanced::Status_1_General, 10, 0);

    m_leftFrontAngle.SetStatusFramePeriod(StatusFrameEnhanced::Status_1_General, 10, 0);
    m_leftBackAngle.SetStatusFramePeriod(StatusFrameEnhanced::Status_1_General, 10, 0);
    m_rightBackAngle.SetStatusFramePeriod(StatusFrameEnhanced::Status_1_General, 10, 0);
    m_rightFrontAngle.SetStatusFramePeriod(StatusFrameEnhanced::Status_1_General, 10, 0);
    

	m_leftFrontDrive.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::IntegratedSensor, 0, 0);
    m_leftBackDrive.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::IntegratedSensor, 0, 0);
    m_rightBackDrive.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::IntegratedSensor, 0, 0);
    m_rightFrontDrive.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::IntegratedSensor, 0, 0);
    
	m_leftFrontAngle.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::IntegratedSensor, 0, 0);
    m_leftBackAngle.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::IntegratedSensor, 0, 0);
    m_rightBackAngle.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::IntegratedSensor, 0, 0);
    m_rightFrontAngle.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::IntegratedSensor, 0, 0);
}

void DriveSubsystem::resetEncoder(){
	m_leftFrontDrive.SetSelectedSensorPosition(0.0, 0, 0);
	m_leftBackDrive.SetSelectedSensorPosition(0.0, 0, 0);
	m_rightBackDrive.SetSelectedSensorPosition(0.0, 0, 0);
	m_rightFrontDrive.SetSelectedSensorPosition(0.0, 0, 0);

	m_leftFrontAngle.SetSelectedSensorPosition(0.0, 0, 0);
	m_leftBackAngle.SetSelectedSensorPosition(0.0, 0, 0);
	m_rightBackAngle.SetSelectedSensorPosition(0.0, 0, 0);
	m_rightFrontAngle.SetSelectedSensorPosition(0.0, 0, 0);

}