#include "SmartFridge.h"
#include <opencv2/opencv.hpp>
#include <ctime>

int main()
{
	fprintf(stdout,"Version Number %d.%d\n",SmartFridge_VERSION_MAJOR,SmartFridge_VERSION_MINOR);
	// Open the camera 
	cv::VideoCapture cap(0);
	if (!cap.isOpened())
	{
		fprintf(stderr, "Could not open Camera\n" );
		return -1;
	}
	// Create a window
	cv::namedWindow("Camera",1);
	cv::Mat CurrentFrame;
	double LastDisplayTime,FrameRatePerSec = 0;
	// Display image in Loop 
	while(1)
	{
		cap >> CurrentFrame;
		// Check if the frame is good
		if (CurrentFrame.rows > 0)
		{
			FrameRatePerSec++;
			cv::imshow("Camera",CurrentFrame);
			if(time(0)*1000 - LastDisplayTime > 1000)
			{
				fprintf(stdout, "FrameRate Per Second: %f\n", FrameRatePerSec);
				FrameRatePerSec = 0;
				LastDisplayTime = time(0)*1000;
			}
		}
		if(cv::waitKey(30) >=0) break;
	}
	return 0;
}