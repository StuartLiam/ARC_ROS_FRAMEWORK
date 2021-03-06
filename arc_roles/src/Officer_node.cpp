#include "ros/ros.h"
#include "Role.h"

int main(int argc, char **argv){
  ros::init(argc, argv, "officer_node");
  arc_roles::Role officer("OFFICER");

  officer.set_priority(0.1);
  officer.set_max_count(1);

  officer.run();
  return 0;
}
