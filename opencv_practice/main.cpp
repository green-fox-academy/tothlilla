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
	cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
	//move window
	cv::moveWindow("image", 0, 0);
	//display image in a specified window
	imshow("image", originImg);

	//change image brightness with Scalar function and display
	changeImageBrightnessWithScalar(originImg);
	//change image brightness with convert function and display
	changeImageBrightnessWithConvertTo(originImg);
	//change image brightness in a loop pixel by pixel
	changeImageBrightnessPixelByPixel(originImg);

	//change image contrast with '*' operator
	changeImageContrastWithOperators(originImg);
	//change image contrast with convert function and display
	changeImageContrastWithConvertTo(originImg);
	//change contrast brightness in a loop pixel by pixel
	changeImageContrastPixelByPixel(originImg);

	//blending two images
	blendImagesWithAddWeighted();

	//change image to gray
	changeImageGrayWithImread(originImg);
	//changeImageGrayWithCvtColor1(originImg); //RGB mode
	changeImageGrayWithCvtColor2(originImg); //BGR mode
	
	//draw line
	drawLine();
	//draw elipses
	drawEllipse();


	//cv::waitKey(0); //display infinite time
	cv::waitKey(5000); //display 5 sec

	return 0;
}