cmake_minimum_required(VERSION 2.8.3)
project(arc_behaviour)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  arc_msgs
  roscpp
  rospy
  marker_msgs
  geometry_msgs
  actionlib
  move_base_msgs
  actionlib_msgs
)

## System dependencies are found with CMake's conventions
# ind_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

# Generate added messages and services with any dependencies listed here
#generate_messages(
#  DEPENDENCIES
#  arc_msgs
#  std_msgs  # Or other packages containing msgs
#)

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES arc_behaviour
  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
        include
)

## Declare a C++ library
# add_library(arc_behaviour
#   src/${PROJECT_NAME}/arc_behaviour.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(arc_behaviour ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
# add_executable(arc_behaviour_node src/arc_behaviour_node.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(arc_behaviour_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# target_link_libraries(arc_behaviour_node
#   ${catkin_LIBRARIES}
# )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS arc_behaviour arc_behaviour_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_arc_behaviour.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
add_executable(arc_base src/arc_base_node.cpp src/ArcBase.cpp include/ArcBase.h src/RandomWanderMS.cpp src/RandomWanderMS.h src/MotorSchema.h)

target_link_libraries(arc_base
  ${catkin_LIBRARIES}
)

#PERCEPTUAL SCHEMAS
add_executable(detect_marker_ps src/DetectMarkerPS.cpp include/DetectMarkerPS.h src/detect_marker_ps_node.cpp)
add_executable(detect_robot_ps src/detect_robot_ps_node.cpp src/DetectRobotPS.cpp include/DetectRobotPS.h)
add_executable(detect_debris_ps src/detect_debris_ps_node.cpp src/DetectDebrisPS.cpp include/DetectDebrisPS.h)
add_executable(detect_victim_ps src/detect_victim_ps_node.cpp src/AdvancedDetectVictimPS.cpp include/AdvancedDetectVictimPS.h)
add_executable(navigation_adapter src/NavigationAdapter.cpp include/NavigationAdapter.h src/navigation_adapter_node.cpp)
add_executable(random_wander_ms src/RandomWanderMS.cpp src/RandomWanderMS.h src/random_wander_ms_node.cpp src/MotorSchema.h)
add_executable(move_to_goal_ms src/MoveToGoalMS.cpp src/MoveToGoalMS.h src/move_to_goal_ms_node.cpp src/MotorSchema.h)
add_executable(clean_debris_ms src/CleanDebrisMS.cpp src/CleanDebrisMS.h src/clean_debris_ms_node.cpp src/MotorSchema.h)
add_executable(handle_marker_ms src/HandleMarkerMS.cpp src/HandleMarkerMS.h src/handle_marker_ms_node.cpp src/MotorSchema.h)
add_executable(bot_brain src/Bot_Brain.cpp src/Bot_Brain.h src/bot_brain_node.cpp)



target_link_libraries(detect_victim_ps ${catkin_LIBRARIES} )
target_link_libraries(detect_marker_ps ${catkin_LIBRARIES} )
target_link_libraries(detect_robot_ps ${catkin_LIBRARIES} )
target_link_libraries(detect_debris_ps ${catkin_LIBRARIES} )
target_link_libraries(random_wander_ms ${catkin_LIBRARIES} )
target_link_libraries(move_to_goal_ms ${catkin_LIBRARIES} )
target_link_libraries(clean_debris_ms ${catkin_LIBRARIES} )
target_link_libraries(handle_marker_ms ${catkin_LIBRARIES} )
target_link_libraries(navigation_adapter ${catkin_LIBRARIES} )
target_link_libraries(bot_brain ${catkin_LIBRARIES})


add_dependencies(detect_debris_ps marker_msgs_generate_messages_cpp arc_msgs_generate_messages_cpp)
add_dependencies(detect_victim_ps marker_msgs_generate_messages_cpp arc_msgs_generate_messages_cpp)
add_dependencies(detect_robot_ps marker_msgs_generate_messages_cpp arc_msgs_generate_messages_cpp)
add_dependencies(random_wander_ms marker_msgs_generate_messages_cpp arc_msgs_generate_messages_cpp)
add_dependencies(move_to_goal_ms marker_msgs_generate_messages_cpp arc_msgs_generate_messages_cpp)
add_dependencies(clean_debris_ms marker_msgs_generate_messages_cpp arc_msgs_generate_messages_cpp)
add_dependencies(handle_marker_ms marker_msgs_generate_messages_cpp arc_msgs_generate_messages_cpp)
add_dependencies(navigation_adapter arc_msgs_generate_messages_cpp)
add_dependencies(bot_brain marker_msgs_generate_messages_cpp arc_msgs_generate_messages_cpp)
