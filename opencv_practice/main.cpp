#include "practiceWeekHeader.h"

void finishedFunctions(cv::Mat originImg);
void brightFunctions(cv::Mat originImg);
void contrastFunctions(cv::Mat originImg);
void grayFunctions(cv::Mat originImg);
void blendFunctions();
void drawFunctions();
int main()
{
	//create a matrix object
	cv::Mat originImg;
	//open origin image

	originImg = cv::imread("lena.jpg"); //default read mode of image

	//error handling
	if (originImg.empty()) {
		std::cout << "Image cannot be loaded..!!" << std::endl;
		return -1;
	}

	//create window
	cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
	//move window
	cv::moveWindow("image", 0, 0);
	//display image in a specified window
	imshow("image", originImg);
	
	finishedFunctions(originImg);

	//cv::waitKey(0); //display infinite time
	cv::waitKey(5000); //display 5 sec

	return 0;
}
void finishedFunctions(cv::Mat originImg)
{
	brightFunctions(originImg);
	contrastFunctions(originImg);
	blendFunctions();
	grayFunctions(originImg);
	drawFunctions();
}
void brightFunctions(cv::Mat originImg)
{
	//change image brightness with Scalar function and display
	changeImageBrightnessWithScalar(originImg);
	//change image brightness with convert function and display
	changeImageBrightnessWithConvertTo(originImg);
	//change image brightness in a loop pixel by pixel
	changeImageBrightnessPixelByPixel(originImg);
}
void contrastFunctions(cv::Mat originImg)
{
	//change image contrast with '*' operator
	changeImageContrastWithOperators(originImg);
	//change image contrast with convert function and display
	changeImageContrastWithConvertTo(originImg);
	//change contrast brightness in a loop pixel by pixel
	changeImageContrastPixelByPixel(originImg);
}
void blendFunctions() 
{
	//blending two images
	blendImagesWithAddWeighted();
}
void grayFunctions(cv::Mat originImg)
{
	//change image to gray
	changeImageGrayWithImread(originImg);
	changeImageGrayWithCvtColor1(originImg); //RGB mode
	changeImageGrayWithCvtColor2(originImg); //BGR mode
}
void drawFunctions()
{
	//draw line
	drawLine();
	//draw elipse
	drawEllipse();
}