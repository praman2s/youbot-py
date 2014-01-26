
FILE( GLOB SRC_FILES *.cpp )
FILE( GLOB HDR_FILES *.h )

FIND_PACKAGE(Boost COMPONENTS
                system
                thread
                python REQUIRED)

find_package(PythonLibs 2.7 REQUIRED)

INCLUDE_DIRECTORIES(${PYTHON_LIBRARIES})
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

INCLUDE_DIRECTORIES( ${CMAKE_SOURCE_DIR}
                     ${YOUBOT_PATH} 
                     ${YOUBOT_PATH}/soem/src)

ADD_LIBRARY(youbot SHARED binding.cpp)
ADD_EXECUTABLE(torquereading torque_filesaver.cpp)
TARGET_LINK_LIBRARIES(torquereading  ${YOUBOT_PATH}/lib/libYouBotDriver.so)
TARGET_LINK_LIBRARIES(youbot  ${Boost_LIBRARIES} ${PYTHON_LIBRARIES}  ${YOUBOT_PATH}/lib/libYouBotDriver.so)
