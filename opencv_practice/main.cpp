#include "practiceWeekHeader.h"

int main()
{
	//open origin image
	cv::Mat originImg;
	originImg = cv::imread("lena.jpg"); //default read mode of image

	//error handling
	if (originImg.empty()){
		std::cout << "Image cannot be loaded..!!" << std::endl;
		return -1;
	}

	//create window
	cv::namedWindow("image", cv::WINDOW_NORMAL);
	//move window
	cv::moveWindow("image", 0, 0);
	//display image in a specified window
	imshow("image", originImg);

	//change image brightness with Scalar function and display
	changeImageBrightnessWithScalar(originImg);
	//change image brightness with convert function and display
	changeImageBrightnessWithConvertTo(originImg);

	
	//cv::waitKey(0); //display infinite time
	cv::waitKey(5000); //display 3 sec


	return 0;
}