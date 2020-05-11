#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>
#include <vector>
using namespace std;

// Define a global client that can request service
ros::ServiceClient client;

// This function calls the command_robot serviceto drive the robot in the specific direction

void drive_robot(float lin_x, float ang_z)

{
	// Request a service and pass velocities to the drive
	ROS_INFO_STREAM("Moving the robot towards target");
	
	ball_chaser::DriveToTarget srv;
	srv.request.linear_x = lin_x;
	srv.request.angular_z = ang_z;	


	if(!client.call(srv))
	   ROS_ERROR("Failed to call service ball_chaser");
	
}

// This callback function continuously executes and reads image data

void process_image_callback(const sensor_msgs::Image img)
{
	int white_pixel = 255;
        int left_count = 0;
        int right_count = 0;
        int front_count = 0;
        int back_count = 0;

	//Loop through each pixel in the image and check for a bright white one
        for (int i=0; i < img.height * img.step; i +=3){
            int pos_index = i % (img.width * 3)/3;
            
            if (img.data[i] == white_pixel && img.data[i + 1] == white_pixel && img.data[i+2] == white_pixel) {
            if(pos_index<=265){
            left_count += 1;
            }
            if(pos_index > 265 && pos_index<=533) {
            front_count += 1;
            }
            if (pos_index > 533){
            right_count += 1;
		            }
        }      
 }

// Indentifying if the pixel is in the left, mid or right side of the image

vector<int> pos_counter{left_count, front_count, right_count};
int move = *max_element(pos_counter.begin(), pos_counter.end());

// Call the drive_bot function and pass the velocities

if (move == 0){
    drive_robot(0,0);  
}
else if (move == left_count){
    drive_robot(0,-0.5);  
}
else if (move == right_count){
    drive_robot(0.5,0.5);  
}
else if (move == front_count){
    drive_robot(0.5,0);  
}

}
 int main(int argc, char** argv)
 
 {
 //Initialise  the process_image code and create a handle to it 
 ros::init(argc, argv, "process_image");
 ros::NodeHandle n;
 
 
 //Define a client service capable of requesting services from command_bot
 client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");
 
 // Subscribe to /camera/rgb/image_raw topic
 ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);
 
 //Handle ROS communication events
 ros::spin();
 
 return 0;
 
 }
