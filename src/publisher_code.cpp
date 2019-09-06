#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
	//create a node called "publisher_node"
	ros::init(argc, argv, "publisher_node");

	//create a NodeHandle to allow the node to communicate with ROS
	ros::NodeHandle n;

	//hook up this node to the master node and create a Publisher with buffer size 1000
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("publisher_topic", 1000);
	ros::Rate loop_rate(1);

	//count how many messages we send
	int count = 0;

	while (ros::ok())
	{
		//message object to be published
		std_msgs::String msg;

		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();

		ROS_INFO("%s", msg.data.c_str());

		//publish msg with chatter_pub
		chatter_pub.publish(msg);

		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}

	return 0;
}
