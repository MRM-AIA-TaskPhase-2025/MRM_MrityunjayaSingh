// Chatroom Node (chatroom_node.cpp)
#include <ros/ros.h>
#include <std_msgs/String.h>

void chatroomCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("[Chatroom] Message Received: %s", msg->data.c_str());

    // Republish the message to all users
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("chatroom", 10);
    pub.publish(*msg);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "chatroom_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("chatroom", 10, chatroomCallback);

    ros::spin();

    return 0;
}

