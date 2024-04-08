**# ROS Chatroom Package**

This package implements a simple chatroom system using ROS.

**Task Description and Approach**

The task was to create a chatroom system where multiple users can communicate with each other by sending and receiving messages. The approach undertaken involved creating individual nodes for each user to send and receive messages, as well as a central chatroom node to relay messages between users.

**ROS Topics Published**

- `/chatroom` - Topic for sending and receiving messages within the chatroom.

**ROS Messages Used**

- **Messages:**
  - `std_msgs/String` - Used to represent messages exchanged within the chatroom.

**Video Demonstration**

 https://youtu.be/mSgRUVIqNac


