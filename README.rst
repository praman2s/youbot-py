.. youbot-py documentation master file, created by
   sphinx-quickstart on Sun Dec 22 13:18:19 2013.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

youBot-py (Under Development)
===========================================================

* **The first stable release 0.1.0 - Support for Arm**

1 .cd $HOME  (or your favourite directory)
2. git clone https://github.com/praman2s/youbot-py
3. sudo apt-get install git git-core cmake libboost-all-dev python-dev python-numpy xdotool qt-sdk libxml2-dev libboost-thread-dev libboost-date-time-dev libboost-filesystem-dev libboost-system-dev libboost-regex-dev
4. cd youbot-py
5. git clone https://github.com/youbot/youbot_driver.git
6. cd youbot_driver
7. mkdir build && cd build
8. cmake ..
9. make -j2
10. sudo make install
11. cd ..
12. python setup.py build
13. sudo python setup.py install



.. image:: youbot.png
    :height: 300
    :align: center

For more info :  http://praman2s.github.io/youbot-py/
