PROJECT(youBot)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
CMAKE_POLICY(SET CMP0003 OLD)

# Setup
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/modules )
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
SET(YOUBOT_PATH $ENV{YOUBOT_HOME})




##############################################################################
# 				Required common packages                     #
##############################################################################

FIND_PACKAGE( Boost 1.47 EXACT COMPONENTS  system serialization thread REQUIRED )
IF(Boost_FOUND)
  MESSAGE(STATUS "Boost library found at first attempt.")
ELSE(Boost_FOUND)
  SET( BOOST_ROOT $ENV{BOOSTDIR})
	MESSAGE(STATUS "Boost library NOT found at first attempt. Setting BOOST_ROOT to" $ENV{BOOSTDIR})
	FIND_PACKAGE( Boost COMPONENTS  system serialization thread REQUIRED )
	IF(Boost_FOUND)
		MESSAGE(STATUS "Boost library found in " ${BOOST_ROOT})
        #INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
        LINK_DIRECTORIES(${Boost_LIBRARY_DIRS} )
	ELSE(Boost_FOUND)
		MESSAGE(STATUS "Boost library not found. Boost-dependent headers will NOT be available")
	ENDIF(Boost_FOUND)
ENDIF(Boost_FOUND)

FIND_PACKAGE( Coin REQUIRED )

##############################################################################
# 				SIMULATION				     #
##############################################################################
FIND_PACKAGE( OpenRAVE REQUIRED )

IF(OpenRAVE_FOUND)
	MESSAGE(STATUS "Will Enable Simulation")
ELSE(OpenRAVE_FOUND)
	MESSAGE(STATUS "OpenRAVE not found and hence simulation will be disabled")
ENDIF(OpenRAVE_FOUND)

##############################################################################
# 				GUI					     #
##############################################################################

OPTION(YOUBOT_GUI "Build the gui version" ON )
OPTION(YOUBOT_CONSOLE "Build the console version" OFF )


IF(YOUBOT_GUI)
  FIND_PACKAGE( Qt4 REQUIRED )
  IF( QT4_FOUND )
    SET( QT_USE_QTMAIN TRUE )
    INCLUDE ( ${QT_USE_FILE} )
    ADD_DEFINITIONS( ${QT_DEFINITIONS} )
  ENDIF( QT4_FOUND )

  FIND_PACKAGE( SoQt4 REQUIRED )
  IF( SOQT_LIBRARY_FOUND )
    ADD_DEFINITIONS( -DSOQT_DLL -DCOIN_DLL )
    INCLUDE_DIRECTORIES( ${SOQT_INCLUDE_DIR} )
  ENDIF( SOQT_LIBRARY_FOUND )

  INCLUDE_DIRECTORIES( ${CMAKE_SOURCE_DIR} 
                       ${Boost_INCLUDE_DIRS})
                       
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS} )
  
  ADD_SUBDIRECTORY (src/libgui)
  ADD_SUBDIRECTORY (src/libbinding)
  #FILE( GLOB RES_FILES *.rc )
  #QT4_WRAP_CPP( QT_MOC_SRC application.h )
  
  ADD_EXECUTABLE(youbot_gui ${CMAKE_SOURCE_DIR}/src/main.cpp)
  ADD_EXECUTABLE(robot ${CMAKE_SOURCE_DIR}/src/robot.cpp)
  TARGET_LINK_LIBRARIES(youbot_gui libgui)
  TARGET_LINK_LIBRARIES(robot libgui)
  #SET( HDR_FILES_GUI application.h )

ENDIF(YOUBOT_GUI)






