""" A simple example progam.

.. examplepre-block:: hello world

Description
-----------

Make sure that the robot is off the ground, since
the example code involves moving the base at a 
velocity for 0.1m/s in x direction for 5 seconds

.. examplepost-block:: helloworld

"""

from youbot import *   #exposes youbot_driver to python
import time

robot = base()    # Calls the constructor . Important to call at the begining
current = time.time()

while (time.time()-current < 5):
	robot.SetVelocity([-0.2,0,0]) #Sets the base velocity to x - 0.1 for 5 seconds

print "End of Hello World..!!!"


