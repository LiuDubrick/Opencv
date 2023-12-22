#include"Workopencv.h"

using namespace cv;

//Image modification function
void  Demo_modle::Compare(Mat &image)
{
	Mat gray, blur, binarization;

	//Turn the image to a grayscale image
	cvtColor(image, gray, COLOR_BGR2GRAY);
	namedWindow("gray", WINDOW_FREERATIO);
	imshow("gray", gray);

	//Binarize the grayscale image
	threshold(gray, binarization, 125, 255, THRESH_OTSU);
	namedWindow("binarization", WINDOW_FREERATIO);
	imshow("binarization", binarization);

	//Blur the image Gaussian
	GaussianBlur(image, blur, Size(0, 0), 15);
	namedWindow("blur", WINDOW_FREERATIO);
	imshow("blur", blur);
}

void Demo_modle::Video_Demo(VideoCapture &video)
{
	namedWindow("frame", WINDOW_FREERATIO);
	VideoCapture capture = video;
	Mat frame;
	while (true)
	{
		capture.read(frame);
		//flip(frame, frame, 1);
	//	if (frame.empty())
	//		break;
		imshow("frame", frame);

		if (waitKey(40) == 27)
			break;
	}
}

void Demo_modle::Cam_Demo()
{
	namedWindow("frame", WINDOW_FREERATIO);
	VideoCapture capture(0);
	Mat frame;
	int c;
	while (true)
	{
		capture.read(frame);
		//flip(frame, frame, 1);
	//	if (frame.empty())
	//		break;
		imshow("frame", frame);

		c = waitKey(40);
		if (c == 27)
			break;
	}
}

void Demo_modle::Dilate_Demo(Mat &image)
{
	Mat output, adjustment;
	adjustment = getStructuringElement(MORPH_RECT,Size(20,20));
	dilate(image, output, adjustment);
	namedWindow("swell", WINDOW_FREERATIO);
	imshow("swell", output);

}

void Demo_modle::Edgescan_Demo(Mat &image)
{
	Mat output(image.size(), CV_8UC1);
	Canny(image, output, 150, 180);
	namedWindow("edge", WINDOW_FREERATIO);
	imshow("edge", output);
}

void Demo_modle::Erode_Demo(Mat& image)
{
	Mat output, adjustment;
	adjustment = getStructuringElement(MORPH_RECT, Size(20, 20));
	erode(image, output, adjustment);
	namedWindow("swell", WINDOW_FREERATIO);
	imshow("swell", output);
}

void Demo_modle::Resize_Demo(Mat& image)
{
	Mat zoomin;
	int h = image.rows, w = image.cols;
	resize(image, zoomin, Size(w / 2, h / 2), 0, 0, INTER_LINEAR);
	imshow("zoomin", zoomin);
	imshow("original", image);
}
