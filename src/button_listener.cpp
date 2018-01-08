#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PoseStamped.h>

#define BUTTONNAME 

geometry_msgs::PoseStamped myPose;
geometry_msgs::PoseStamped stablePose = NULL;

void poseCallback(const geometry_msgs::PoseStamped& pose_msg )
{
	myPose = pose_msg;
}

void buttonEventCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("I heard: [%s]", msg->data.c_str()); 
	
	if(msg->data == "BUTTONNAME_pushed"){
	stablePose = myPose;
	}
	
}

int main(int argc, char **argv)
{

ros::init(argc, argv , "button_listener");
ros::NodeHandle n;

ros::Subscriber subPose = n.subscribe("/iiwa/state/CartesianPose",100, poseCallback);
ros::spin();

ros::Subscriber subButton = n.subscribe("/iiwa/state/buttonEvent",10, buttonEventCallback);
ros::spin();	

ros::Publisher pub = n.advertise<geometry_msgs::PoseStamped>("/iiwa/registredPose", 50);
  ros::Rate loop_rate(10);
  ros::spinOnce();

  int count = 0;
  while (ros::ok())
  {
    if(stablePose != NULL){
    pub.publish(stablePose);
    }
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
  
return 0;
}
