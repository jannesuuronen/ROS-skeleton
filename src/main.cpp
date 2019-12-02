#include <ros/ros.h>
#include <ros/master.h>


/*User-defined messages*/
#include "test_node/masterMessage.h"

void msgCallback(const test_node::masterMessage &msg)
{
    std::cout << "Message recieved: " << msg.statusString << " " << msg.liftState << " " << msg.avgDist << std::endl;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "test_node");
    ros::NodeHandle n;
    ROS_INFO("Launching test node");
    ros::Rate loop_rate(50);
    ros::Subscriber sub = n.subscribe("/RIO_publisher_masterMessage", 10, msgCallback);
    while (ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }
}
