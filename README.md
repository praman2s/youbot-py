youbot-py
=========

A Python Wrapper for youbot_driver to open the world of possibility for youbot.

---------------------------------------------------------------------------------

Installation Instruction :

1. Compile the youbot_driver as mentioned in https://github.com/youbot/youbot_driver.
2. ROS framework is "not" required.
3. Set the environment variables.

                export LD_LIBRARY_PATH=/path_to_youbot_driver/lib/
                export YOUBOT_HOME=/path_to_youbot_driver
4. Build and Install.

                git clone https://github.com/praman2s/youbot-py.git
                cd youbot-py
                python setup.py build --build-base=.
                python setup.py install
                
-------------------------------------------------------------------------------------

Usage(Currently works only with hardware connected) :

1. All the functions of the youbot_driver are exposed when youbotpy is imported.
2. Normal usage "from youbotpy import * "
3. Try the examples/helloworld.py to test the functionalities.

---------------------------------------------------------------------------------------


Check the milestones for future improvements.

Contact hotline@youbot-store.org for more improvements.
Help us by reporting issues.

----------------------------------------------------------------------------------------


