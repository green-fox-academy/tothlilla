#include "practiceWeekHeader.h"

void changeImageBrightnessWithScalar(cv::Mat originImg)
{
	cv::Mat brightImg = originImg + cv::Scalar(75, 75, 75);
	cv::namedWindow("image2", cv::WINDOW_NORMAL);
	cv::moveWindow("image2", 0, 280);
	imshow("image2", brightImg);
}

void changeImageBrightnessWithConvertTo(cv::Mat originImg)
{
	cv::Mat brightImg;
	originImg.convertTo(brightImg, -1, 1, -205);
	cv::namedWindow("image3", cv::WINDOW_NORMAL);
	cv::moveWindow("image3", 0, 560);
	imshow("image3", originImg);
}

