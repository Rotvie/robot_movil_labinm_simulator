#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <iostream>


double x=0,y=0,z=0;
geometry_msgs::Quaternion odom_quat;

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{   
   x = msg->pose.pose.position.x;
   y = msg->pose.pose.position.y;
   z = msg->pose.pose.position.z;
   odom_quat = msg->pose.pose.orientation;
}

int main(int argc, char** argv){
  ros::init(argc, argv, "odom_to_base_footprint_tf");

  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("odom", 0, odomCallback);
  
  ros::Rate r(10.0);
  
  odom_quat = tf::createQuaternionMsgFromYaw(0.0);
  
  tf::TransformBroadcaster odom_broadcaster;  
  geometry_msgs::TransformStamped odom_trans;  
  odom_trans.header.frame_id = "odom";
  odom_trans.child_frame_id = "base_footprint";
  
  while(n.ok()) {
 	ros::spinOnce();
 	ros::Time current_time = ros::Time::now();
 	odom_trans.header.stamp = current_time;
	odom_trans.transform.translation.x = x;
	odom_trans.transform.translation.y = y;
	odom_trans.transform.translation.z = z;
	odom_trans.transform.rotation = odom_quat;
	odom_broadcaster.sendTransform(odom_trans);
	r.sleep();
  }
}
