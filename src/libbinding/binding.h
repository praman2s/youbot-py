

#include <youbot_driver/youbot/YouBotBase.hpp>
#include <youbot_driver/youbot/YouBotManipulator.hpp>
#include "youbot_int.h"

namespace YOUBOTPYTHON{
using namespace boost::python;


class Robot {

public:
	Robot();
	bool startcalib();
	bool SetArmJointValues(const object& o);
	object GetArmJointValues();
	bool SetBaseVelocity(const object& o);
	unsigned int nrofJoints;
	static bool instanceFlag;     // Instance Flag to check if the hardware was setup atleast once
	static Robot *single;
	static Robot* getInstance();  
	youbot::YouBotManipulator *youBotArm;  
	youbot::YouBotBase *youBotBase;       
	virtual ~Robot();
};

} /* namespace YOUBOTPYTHON */

