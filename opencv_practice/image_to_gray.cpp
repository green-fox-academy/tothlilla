#include "practiceWeekHeader.h"

void changeImageGrayWithImread(cv::Mat originImg)
{
	originImg = cv::imread("lena.jpg", cv::IMREAD_GRAYSCALE);
	cv::namedWindow("gray image 1", cv::WINDOW_AUTOSIZE);
	cv::moveWindow("gray image 1", 1000, 280);
	cv::imshow("gray image 1", originImg);
}

void changeImageGrayWithCvtColor1(cv::Mat originImg)
{
	originImg = cv::imread("lena.jpg");
	cv::Mat grayImage;
	cv::cvtColor(originImg, grayImage, cv::COLOR_RGB2GRAY);
	cv::namedWindow("gray image 2", cv::WINDOW_AUTOSIZE);
	cv::moveWindow("gray image 2", 1000, 560);
	cv::imshow("gray image 2", grayImage);
}

void changeImageGrayWithCvtColor2(cv::Mat originImg)
{
	originImg = cv::imread("lena.jpg");
	cv::Mat grayImage;
	cv::cvtColor(originImg, grayImage, cv::COLOR_BGR2GRAY);
	cv::namedWindow("gray image 3", cv::WINDOW_AUTOSIZE);
	cv::moveWindow("gray image 3", 250, 140);
	cv::imshow("gray image 3", grayImage);
}