#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "topic_publ_nums");
	ros::NodeHandle nh;
	ros::Publisher num_publisher = nh.advertise<std_msgs::Int32>("/numbers",10);

	ros::Rate loop_rate(10);
	int number_count = 0;
	while(ros::ok())
	{
		std_msgs::Int32 msg;
		msg.data = number_count;
		ROS_INFO("%d",msg.data);
		num_publisher.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		++number_count;
	}
	return 0;
}
