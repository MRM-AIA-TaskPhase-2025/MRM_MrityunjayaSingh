#include <ros/ros.h>
#include <std_msgs/String.h>

std::string username = "User3";  // Change the username accordingly for each user

int main(int argc, char** argv)
{
    ros::init(argc, argv, "user3_node");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("chatroom", 10);

    ros::Rate loop_rate(1);  // Adjust the rate as needed

    while (ros::ok())
    {
        std_msgs::String msg;
        std::string input_msg;

        // Get input message from user
        std::getline(std::cin, input_msg);

        // Populate the message with the input message
        msg.data = username + ": " + input_msg;

        // Publish the message to the "chatroom" topic
        pub.publish(msg);

        // Allow ROS to process callbacks
        ros::spinOnce();

        // Sleep to maintain loop rate
        loop_rate.sleep();
    }

    return 0;
}
