#include "practiceWeekHeader.h"

int main()
{
	//open origin image
	Mat originImg;
	originImg = imread("lena.jpg"); //default read mode of image
	//create window
	int windowFlag = WINDOW_NORMAL; //type of window - changable
	namedWindow("image", windowFlag);
	//display image in a specified window
	imshow("image", originImg);

	//change image brightness with Scalar function and display
	changeImageBrightnessWithScalar(originImg);

	waitKey(0); //display infinite time


	return 0;
}