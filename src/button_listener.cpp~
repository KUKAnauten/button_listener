#include <ros/ros.h>
#include <std_msgs/String.h>

void buttonEventCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("I heard: [%s]", msg->data.c_str()); 
	
	
}

int main(int argc, char **argv)
{

ros::init(argc, argv , "button_listener");

ros::NodeHandle n;

ros::Subscriber sub = n.subscribe("/iiwa/state/buttonEvent",10, buttonEventCallback);

ros::spin();	

return 0;
}
