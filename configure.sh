sudo apt-get install git git-core cmake libboost-all-dev python-dev python-numpy xdotool qt-sdk libxml2-dev libboost-thread-dev libboost-date-time-dev libboost-filesystem-dev libboost-system-dev libboost-regex-dev
git clone https://github.com/praman2s/youbot-py.git
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
