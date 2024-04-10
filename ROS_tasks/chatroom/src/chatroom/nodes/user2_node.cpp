#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>
#include <thread>

std::string username = "User2";

void messageCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("%s", msg->data.c_str());
}

void publishMessages(ros::Publisher pub) {
    ros::Rate loop_rate(10);
    std::cout << "[" << username << "] Type your messages here: \n";
    while (ros::ok()) {
        std_msgs::String msg;
        std::string input_msg;
        std::getline(std::cin, input_msg);
        msg.data = "[" + username + "] " + input_msg;
        pub.publish(msg);
        loop_rate.sleep();
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "user2");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("conversation", 500, messageCallback);
    ros::Publisher pub = nh.advertise<std_msgs::String>("conversation", 500);
 
    std::thread pub_thread(publishMessages, pub);

    ros::spin();

    pub_thread.join();

    return 0;
}
