#include "practiceWeekHeader.h"

void change_image_brightness(Mat originImg)
{
	Mat brightImg = originImg + Scalar(75, 75, 75);
	namedWindow("image2", WINDOW_NORMAL);
	imshow("image2", brightImg);
}

