/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013-2014, 
 *  Author : Praveen Ramanujam (praveen.ramanujam@locomotec.com) 
 *  Hocschule Bonn-Rhein-Sieg
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redstributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Hochschule Bonn-Rhein-Sieg nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

#include "binding.h"
#include <boost/python.hpp>

namespace YOUBOTPYTHON{
using namespace boost::python;

Base::Base(){
	this->youBotBase = new youbot::YouBotBase("youbot-base");
	this->youBotBase->doJointCommutation();

}

Base::~Base() {
	

}

bool Base::setVelocity(const object& o){
	
	std::vector<double> BaseVelocity;
	BaseVelocity = ExtractArray<double>(o);	
	quantity<si::velocity> velx,vely;
	quantity<si::angular_velocity> omega;
	BaseVelocity.resize(3);
	
	velx = BaseVelocity[0]*meters_per_second;
	vely = BaseVelocity[1]*meters_per_second;
	omega = BaseVelocity[2]*radians_per_second;
	
	this->youBotBase->setBaseVelocity(velx,vely,omega);
	return true;
}

object Base::Odometry(){
	
	std::vector<double> odom;
	odom.resize(3);
	quantity<si::length> longitudinalPosition;
	quantity<si::length> transversalPosition;
	quantity<plane_angle> orientation;
	this->youBotBase->getBasePosition(longitudinalPosition,transversalPosition,orientation);
	odom[0] = longitudinalPosition.value();
	odom[1] = transversalPosition.value();
	odom[2] = orientation.value();
 	return PyArray(odom);

	
}

bool Base::setWheelVelocities(const object& o){
	
	std::vector<double> JointVel;
	JointVel.resize(4);
	JointVel = ExtractArray<double>(o);
	std::vector<youbot::JointVelocitySetpoint> jointSetVel;
	jointSetVel.resize(4);
	for(std::size_t i=0;i<4;i++){
		jointSetVel[i].angularVelocity = JointVel[i]*radians_per_second;
	}
	this->youBotBase->setJointData(jointSetVel);

	
	return true;
}

object Base::getWheelVelocities(){

	youbot::JointSensedVelocity vel;
	std::vector<double> JointVelocities;
	JointVelocities.resize(4);
	for(std::size_t i=0;i<3;i++){
		this->youBotBase->getBaseJoint(i+1).getData(vel);
		JointVelocities[i] = (double)vel.angularVelocity.value();
	}
	return PyArray(JointVelocities);
	
}

bool Base::setRelativePose(const object& o){

	std::vector<double> pose = ExtractArray<double>(o);		
	quantity<si::length> longitudinalPosition;
	quantity<si::length> transversalPosition;
	quantity<plane_angle> orientation;	
	longitudinalPosition = pose[0]*meters;
	transversalPosition = pose[1]*meters;
	orientation = pose[2]*radians;
	this->youBotBase->setBasePosition(longitudinalPosition, transversalPosition, orientation);
	
	return true;
}



object Base::getVelocity(){
	
	std::vector<double> vel;
	vel.resize(3);
	quantity<si::velocity> longitudinalVelocity; 
	quantity<si::velocity> transversalVelocity; 
	quantity<si::angular_velocity> angularVelocity;
	this->youBotBase->getBaseVelocity(longitudinalVelocity,transversalVelocity,angularVelocity);
	vel[0] = longitudinalVelocity.value();
	vel[1] = transversalVelocity.value();
	vel[2] = angularVelocity.value();
	return PyArray(vel);

}

object Base::getJointTorques(){
	
	youbot::JointSensedTorque torque;
	std::vector<double> JointTorques;
	JointTorques.resize(4);
	for(std::size_t i=0;i<3;i++){
		this->youBotBase->getBaseJoint(i+1).getData(torque);
		JointTorques[i] = (double)torque.torque.value();
	}
	return PyArray(JointTorques);

}

bool Base::setTorque(const object& o){

	std::vector<double> JointTorques;
	JointTorques.resize(4);
	JointTorques = ExtractArray<double>(o);
	std::vector<youbot::JointTorqueSetpoint> jointSetTorque;
	jointSetTorque.resize(4);
	for(std::size_t i=0;i<4;i++){
		jointSetTorque[i].torque = JointTorques[i]*newton_meter;
	}
	this->youBotBase->setJointData(jointSetTorque);

	return true;


}

Arm::Arm() {

	this->youBotArm = new youbot::YouBotManipulator("youbot-manipulator");
	this->youBotArm->doJointCommutation();
	this->youBotArm->calibrateManipulator();
	this->youBotArm->calibrateGripper();
	calib = 0;
	invalidate_calib = 0;
}

bool Arm::startcalib(){
	
	if (invalidate_calib != 0){
		std::cout << "Invalid sequence to calibrate" << std::endl;
		return false;
	}
	if (calib == 1){
		std::cout << "Already Calibrated to Standard Position" << std::endl;
		return false;
	}
	std::vector<youbot::JointAngleSetpoint> jointSetAngle;
	jointSetAngle.resize(5);
	SLEEP_SEC(5);
	jointSetAngle[0].angle =  2.96244 * radian;
	jointSetAngle[1].angle = 1.04883 * radian;
	jointSetAngle[2].angle =-2.43523* radian;
	jointSetAngle[3].angle = 1.73184  * radian;
	jointSetAngle[4].angle =  2.91062 * radian;
	youBotArm->setJointData(jointSetAngle);
	SLEEP_SEC(5);
	for (unsigned int i=1;i<=5;i++)
		youBotArm->getArmJoint(i).setEncoderToZero();
	
	SLEEP_SEC(2);
	calib = 1;
	return true;

}

bool Arm::startcalibHome(){
	
	if (invalidate_calib != 0){
		std::cout << "Invalid sequence to calibrate" << std::endl;
		return false;
	}
	if (calib == 0){
		std::cout << "Already Calibrated to Home Position" << std::endl;
		return false;
	}
	std::vector<youbot::JointAngleSetpoint> jointSetAngle;
	jointSetAngle.resize(5);
	SLEEP_SEC(5);
	jointSetAngle[0].angle =  -2.96244 * radian;
	jointSetAngle[1].angle = -1.04883 * radian;
	jointSetAngle[2].angle =2.43523* radian;
	jointSetAngle[3].angle = -1.73184  * radian;
	jointSetAngle[4].angle =  -2.91062 * radian;
	youBotArm->setJointData(jointSetAngle);
	SLEEP_SEC(5);
	for (unsigned int i=1;i<=5;i++)
		youBotArm->getArmJoint(i).setEncoderToZero();
	
	SLEEP_SEC(2);
	calib = 0;
	return true;

}

bool Arm::Reset(){
	
	std::vector<youbot::JointAngleSetpoint> jointSetAngle;
	jointSetAngle.resize(5);
	SLEEP_SEC(5);
	jointSetAngle[0].angle =  0.0* radian;
	jointSetAngle[1].angle = 0.0 * radian;
	jointSetAngle[2].angle = 0.0 * radian;
	jointSetAngle[3].angle = 0.0  * radian;
	jointSetAngle[4].angle =  0.0 * radian;
	youBotArm->setJointData(jointSetAngle);
	SLEEP_SEC(5);
	return true;

}

bool Arm::EnableTorqueMode(){
	
	std::vector<youbot::JointTorqueSetpoint> torqueSetpoint;
	torqueSetpoint.resize(5);
	youbot::JointSensedTorque torque;
	for(std::size_t i=0;i<5;i++){
		this->youBotArm->getArmJoint(i+1).getData(torque);
		torqueSetpoint[i] = 0.0*newton_meter;
	}
	
	youBotArm->setJointData(torqueSetpoint);
	SLEEP_SEC(2);
	
	return true;
}

object Arm::GetJointValues(){
	youbot::JointSensedAngle angle;
	std::vector<double> JointAngles;
	JointAngles.resize(5);
	for(std::size_t i=0;i<5;i++){
		this->youBotArm->getArmJoint(i+1).getData(angle);
		JointAngles[i] = (double)angle.angle.value();
	}
	numeric::array::set_module_and_type("numpy", "ndarray"); 
	return PyArray(JointAngles);

}

object Arm::GetJointTorqueValues(){

	youbot::JointSensedTorque torque;
	std::vector<double> JointTorques;
	for(std::size_t i=0;i<5;i++){
		this->youBotArm->getArmJoint(i+1).getData(torque);
		JointTorques[i] = (double)torque.torque.value();
	}
	return PyArray(JointTorques);

}


bool Arm::SetJointTorqueValues(const object& o){
	
	std::vector<double> JointTorques;
	JointTorques.resize(5);
	JointTorques = ExtractArray<double>(o);
	std::vector<youbot::JointTorqueSetpoint> jointSetTorque;
	jointSetTorque.resize(5);
	for(std::size_t i=0;i<5;i++){
		jointSetTorque[i].torque = JointTorques[i]*newton_meter;
	}
	this->youBotArm->setJointData(jointSetTorque);

	return true;


}


bool Arm::SetJointValues(const object& o){

	invalidate_calib = 1;
	youbot::JointSensedAngle angle;
	std::vector<double> JointAngles;
	JointAngles.resize(5);
	JointAngles = ExtractArray<double>(o);
	std::vector<youbot::JointAngleSetpoint> jointSetAngle;
	jointSetAngle.resize(5);
	for(std::size_t i=0;i<5;i++){
		jointSetAngle[i].angle = JointAngles[i]*radian;
	}
	youBotArm->setJointData(jointSetAngle);
        return true;

}

Arm::~Arm() {
	

}

BOOST_PYTHON_MODULE(youbot)
{
    using namespace boost::python;
    numeric::array::set_module_and_type("numpy", "ndarray"); 
    import_array();
    class_<YOUBOTPYTHON::Arm, boost::noncopyable>("arm",init<>())

	.def("CalibrateStandard", &Arm::startcalib)
	.def("CalibrateHome", &Arm::startcalibHome)
	.def("GetJointValues", &Arm::GetJointValues)
	.def("SetJointValues", &Arm::SetJointValues)
	.def("GetJointTorqueValues", &Arm::GetJointTorqueValues)
	.def("SetJointTorqueValues", &Arm::SetJointTorqueValues)
	.def("EnableTorqueMode", &Arm::EnableTorqueMode)
	.def("GripperOpen", &Arm::GripperOpen)
	.def("GripperClose", &Arm::GripperClose)
	.def("Reset", &Arm::Reset);

    class_<YOUBOTPYTHON::Base, boost::noncopyable>("base",init<>())
	
	.def("SetVelocity", &Base::setVelocity)
	.def("GetWheelVelocities", &Base::getWheelVelocities)
	.def("SetWheelVelocities", &Base::setWheelVelocities)
	.def("SetWheelTorques", &Base::setTorque)
	.def("GetWheelTorques", &Base::getJointTorques)
	.def("GetPose", &Base::Odometry)
	.def("SetRelativePose", &Base::setRelativePose)
	.def("GetVelocity", &Base::getVelocity);
	
	
}
} /* namespace YOUBOTPY */
