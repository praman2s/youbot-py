sudo apt-get install git git-core cmake libboost-all-dev python-dev python-numpy xdotool qt-sdk libxml2-dev
git clone git://github.com/youbot/youbot_driver.git
cd youbot_driver
mkdir build
cd build
cmake ..
make
sudo make install
cd ..
echo export YOUBOT_HOME=${PWD}  >> ~/.bashrc
xdotool type 'source ~/.bashrc'
xdotool key Return

