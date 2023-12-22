#include<opencv2/opencv.hpp>
#include<imgproc.hpp>
#include<imgcodecs.hpp>
#include<highgui.hpp>
#include<iostream>
#include<string>

#include"Workopencv.h"

using namespace std;
using namespace cv;


int main() 
{
	//image reading
	//string path_image = "Z:/photography/well painted/2022/work.jpg";
	//string path_video = "Z:/MIDIA/material/Spoof videos/zhang.mp4";
	string path_image,path_video;
	
	//image getting
	cout << "Please enter the path of the image to be processed" << endl;
	getline(cin, path_image);
	Mat img = imread(path_image);
	if (img.empty())
	{
		printf("could not load image....");
		return -1;
	}

	//video reading
	cout << "Please enter the path of the video to be processed" << endl;
	getline(cin, path_video);
	VideoCapture video(path_video);
	if (!video.isOpened())
	{
		printf("could not load video ....");
		return -1;
	}


	//Directions for use
	cout << endl;
	cout << endl 
		 << "Below is the user manual" << endl;
	cout <<
		"---------------------------------------------------------" << endl;
	cout << "     FUNCTION    " << "\t " << "THE VALUE SHOULD ENTER" << "\t" 
		 << endl<<endl;
	cout << " Exit            " << "\t " << " 0" << "\t" << endl;
	cout << " Show image      " << "\t " << " 1" << "\t" << endl;//(07_01.cpp)
	cout << " Show video      " << "\t " << " 2" << "\t" << endl;//(07_01.cpp)
	cout << " Process images  " << "\t " << " 3" << "\t" << endl;//(07_02.cpp)
	cout << " Open camera     " << "\t " << " 4" << "\t" << endl;//(07_01.cpp)
	cout << " Edge detection  " << "\t " << " 5" << "\t" << endl;//(07_03.cpp)
	cout << " Dilate treatment" << "\t " << " 6" << "\t" << endl;//(07_03.cpp)
	cout << " Erode treatment " << "\t " << " 7" << "\t" << endl;//(07_03.cpp)
	cout << " Resize image    " << "\t " << " 8" << "\t" << endl;//(07_03.cpp)

	
	int id;
	Demo_modle function;
	while (cin >> id)
	{
		if (id == 0)
			break;

		//show original image
		else if (id == 1)
		{
			namedWindow("input", WINDOW_FREERATIO);
			imshow("input", img);
		}

		//Open the video
		else if (id == 2)
		{
			function.Video_Demo(video);
		}

		//compare the image with different effect
		else if (id == 3)
		{
			function.Compare(img);
		}

		//Turn on the camera
		else if (id == 4)
		{
			function.Cam_Demo();
		}

		//Edge detection
		else if (id == 5)
		{
			function.Edgescan_Demo(img);
		}

		//Pixel bloat
		else if (id == 6)
		{
			function.Dilate_Demo(img);
		}

		//Erode
		else if (id == 7)
		{
			function.Erode_Demo(img);
		}

		//Resize
		else if (id == 8)
		{
			function.Resize_Demo(img);
		}

		else
			cout << "If you want to exit, please enter 0" << endl;


		waitKey(0);
		destroyAllWindows();
	}
	return 0;
}