#include "practiceWeekHeader.h"

int main()
{
	//open origin image
	Mat originImg;
	originImg = imread("lena.jpg"); //default read mode of image

	//error handling
	if (originImg.empty()){
		cout << "Image cannot be loaded..!!" << endl;
		return -1;
	}

	//create window
	namedWindow("image", WINDOW_NORMAL);

	//display image in a specified window
	imshow("image", originImg);

	//change image brightness with Scalar function and display
	changeImageBrightnessWithScalar(originImg);
	//change image brightness with convert function and display
	changeImageBrightnessWithConvertTo(originImg);

	
	waitKey(0); //display infinite time


	return 0;
}