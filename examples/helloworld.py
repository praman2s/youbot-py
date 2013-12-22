""" A simple example progam.

.. examplepre-block:: hello world

Description
-----------

Make sure that the robot is off the ground, since
the example code involves moving the base at a 
velocity for 0.1m/s in x direction for 5 seconds

.. examplepost-block:: helloworld

"""

from youbotpy import *   #exposes youbot_driver to python
import time

robot = robot()    # Calls the constructor . Important to call at the begining
robot.Calibrate()  # Sets the robot in candle position and sets encoder to zero
joint_values = [1,1,1,1,1] # some position that of the arm that the user demands
robot.SetArmJointValues(joint_values) # sets the joint values
time.sleep(2)
current = time.time()

while (time.time()-current < 5):
	robot.SetBaseVelocity([0.1,0,0]) #Sets the base velocity to x - 0.1 for 5 seconds

print "End of Hello World..!!!"


