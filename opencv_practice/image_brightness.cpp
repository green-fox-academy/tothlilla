#include "practiceWeekHeader.h"

void changeImageBrightnessWithScalar(Mat originImg)
{
	Mat brightImg = originImg + Scalar(75, 75, 75);
	namedWindow("image2", WINDOW_NORMAL);
	moveWindow("image2", 0, 280);
	imshow("image2", brightImg);
}

void changeImageBrightnessWithConvertTo(Mat originImg)
{
	Mat brightImg;
	originImg.convertTo(brightImg, -1, 1, -205);
	namedWindow("image3", WINDOW_NORMAL);
	moveWindow("image3", 0, 560);
	imshow("image3", originImg);
}

