/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013, 
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

bool Robot::instanceFlag =false; 
Robot* Robot::single=NULL; 
using namespace boost::python;

Robot::Robot() {
	// the whole setup is initialized with in the constructor
	youBotBase = new youbot::YouBotBase("youbot-base");
	this->youBotBase->doJointCommutation();
	std::cout<<"RESETING ENCODER TO ZERO"<<std::endl;
	for (unsigned int i=1;i<=4;i++)
		youBotBase->getBaseJoint(i).setEncoderToZero();
	this->youBotArm = new youbot::YouBotManipulator("youbot-manipulator");
	this->youBotArm->doJointCommutation();
	this->youBotArm->calibrateManipulator();
	this->nrofJoints=5;


}
bool Robot::startcalib(){
	std::vector<youbot::JointAngleSetpoint> jointSetAngle;
	jointSetAngle.resize(this->nrofJoints);
	jointSetAngle[0].angle =  2.96244 * radian;
	jointSetAngle[1].angle = 1.04883 * radian;
	jointSetAngle[2].angle =-2.43523* radian;
	jointSetAngle[3].angle = 1.73184  * radian;
	jointSetAngle[4].angle =  2.91062 * radian;
	youBotArm->setJointData(jointSetAngle);
	SLEEP_SEC(5);
	for (unsigned int i=1;i<=5;i++)
		youBotArm->getArmJoint(i).setEncoderToZero();
	return true;
}
object Robot::GetArmJointValues(){
	youbot::JointSensedAngle angle;
	std::vector<double> JointAngles;
	JointAngles.resize(this->nrofJoints);
	for(std::size_t i=0;i<this->nrofJoints;i++){
		this->youBotArm->getArmJoint(i+1).getData(angle);
		JointAngles[i] = (double)angle.angle.value();
	}
	numeric::array::set_module_and_type("numpy", "ndarray"); 
	return stdVecToNumpyArray(JointAngles);

}
bool Robot::SetBaseVelocity(const object& o){
	quantity<si::velocity> x_vel;
	quantity<si::velocity> y_vel;
	quantity<si::angular_velocity> z_vel;
	std::vector<double> velocity;
	velocity.resize(3);
	velocity = ExtractArray<double>(o);
	x_vel = velocity[0]*si::meters/si::second;
	y_vel = velocity[1]*si::meters/si::second;
        z_vel = velocity[2]*si::radian/si::second;
	this->youBotBase->setBaseVelocity(x_vel,y_vel,z_vel);
	return true;
}

bool Robot::SetArmJointValues(const object& o){
	youbot::JointSensedAngle angle;
	std::vector<double> JointAngles;
	JointAngles.resize(this->nrofJoints);
	JointAngles = ExtractArray<double>(o);
	std::vector<youbot::JointAngleSetpoint> jointSetAngle;
	jointSetAngle.resize(this->nrofJoints);
	for(std::size_t i=0;i<this->nrofJoints;i++){
		jointSetAngle[i].angle = JointAngles[i]*radian;
	}
	youBotArm->setJointData(jointSetAngle);
        return true;

}

Robot::~Robot() {
	instanceFlag = false;

}
Robot* Robot::getInstance(){

	if(! instanceFlag)
	{
		single = new Robot();
		instanceFlag = true;
		return single;
	}
	else
	{
		return single;
	}
}

BOOST_PYTHON_MODULE(youbot)
{
    using namespace boost::python;
    numeric::array::set_module_and_type("numpy", "ndarray"); 
    import_array();
    class_<Robot>("robot",init<>())
	.def("Calibrate", &Robot::startcalib)
	.def("GetArmJointValues", &Robot::GetArmJointValues)
	.def("SetArmJointValues", &Robot::SetArmJointValues)
	.def("SetBaseVelocity", &Robot::SetBaseVelocity)
	//.def("Destroy", &Robot::~Robot)
	.def_readonly("GetJoints", &Robot::nrofJoints);
    //def("init_robot", &RobotHardware::RobotHardware);
}

} /* namespace YOUBOTPY */
