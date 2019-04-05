#include "practiceWeekHeader.h"

void drawLine()
{
	cv::Mat lineWindow = cv::Mat::zeros(cv::Size(500, 280), CV_8UC3);
	cv::line(lineWindow, cv::Point(0, 0), cv::Point(500, 280), cv::Scalar(255, 255, 10), 10, cv::FILLED);
	//Line types: FILLED LINE_4 LINE_8 LINE_AA 
	cv::imshow("line", lineWindow);
	cv::moveWindow("line", 250, 0);
}
void drawEllipse()
{
	cv::Mat ellipseWindow = cv::Mat::zeros(cv::Size(1000, 1000), CV_8UC3);
	//draw circle
	cv::ellipse(ellipseWindow, cv::Point(50, 50), cv::Size(50, 50), 0, 0, 360,
		cv::Scalar(255, 255, 10), 1, cv::LINE_8, 0);
	//draw half circle 1
	cv::ellipse(ellipseWindow, cv::Point(160, 50), cv::Size(50, 50), 0, 0, 180,
	cv::Scalar(255, 255, 10), 1, cv::LINE_8, 0);
	//draw half circle 2
	cv::ellipse(ellipseWindow, cv::Point(270, 50), cv::Size(50, 50), 0, 90, 270,
	cv::Scalar(255, 255, 10), 1, cv::LINE_8, 0);
	//draw ellipse 1
	cv::ellipse(ellipseWindow, cv::Point(380, 50), cv::Size(100, 50), 0, 0, 360,
		cv::Scalar(255, 255, 10), 1, cv::LINE_8, 0);
	//draw ellipse 2
	cv::ellipse(ellipseWindow, cv::Point(540, 100), cv::Size(50, 100), 0, 0, 360,
		cv::Scalar(255, 255, 10), 1, cv::LINE_8, 0);
	//change angle
	cv::ellipse(ellipseWindow, cv::Point(690, 100), cv::Size(100, 50), 25, 0, 360,
		cv::Scalar(255, 255, 10), 1, cv::LINE_8, 0);
	//change thickness
	cv::ellipse(ellipseWindow, cv::Point(860, 100), cv::Size(100, 50), 25, 0, 360,
		cv::Scalar(255, 255, 10), 8, cv::LINE_8, 0);
	//change shift
	cv::ellipse(ellipseWindow, cv::Point(200, 600), cv::Size(100, 60), 25, 0, 360,
		cv::Scalar(255, 255, 10), 2, cv::LINE_8, 2);
	//ckeck shift 
	cv::ellipse(ellipseWindow, cv::Point(50, 150), cv::Size(25, 15), 25, 0, 360,
		cv::Scalar(10, 10, 255), 1, cv::LINE_8, 0);


	cv::imshow("ellipse", ellipseWindow);
	cv::moveWindow("ellipse", 250, 300);
}
//--------------HINT--------------------
/*
void cv::ellipse(	
	InputOutputArray 	img,
	Point 	center,
	Size 	axes,
	double 	angle,
	double 	startAngle,
	double 	endAngle,
	const Scalar & 	color,
	int 	thickness = 1,
	int 	lineType = LINE_8,
	int 	shift = 0
)
*/