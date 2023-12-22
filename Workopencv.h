#pragma once
#include<opencv2/opencv.hpp>

using namespace cv;

class Demo_modle
{
public:
	void Compare(Mat &image);
	void Video_Demo(VideoCapture &video);
	void Cam_Demo();
	void Dilate_Demo(Mat &image);
	void Edgescan_Demo(Mat &image);
	void Erode_Demo(Mat& image);
	void Resize_Demo(Mat& image);
};