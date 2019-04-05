#include "practiceWeekHeader.h"

///////////////////////////////////
//------------START----------------
void finishedFunctions(cv::Mat originImg)
{
	//choice one of the topics and click
	//display_basic_image_with_error_handler(originImg);
	//brightFunctions(originImg);
	//contrastFunctions(originImg);
	//blendFunctions();
	//grayFunctions(originImg);
	drawFunctions();
}

////////////////////////////////////
//-------------TOPICS---------------
//$$$$$$  Basic Functions   $$$$$$$$
void display_basic_image_with_error_handler(cv::Mat originImg)
{

	//error handling
	if (originImg.empty()) {
		std::cout << "Image cannot be loaded..!!" << std::endl;
		return;
	}
	//create window
	cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
	//move window
	cv::moveWindow("image", 0, 0);
	//display image in a specified window
	cv::imshow("image", originImg);
}
//$$$$$$ Play with image brightness $$$$$$$$
void brightFunctions(cv::Mat originImg)
{
	//change image brightness with Scalar function and display
	changeImageBrightnessWithScalar(originImg);
	//change image brightness with convert function and display
	changeImageBrightnessWithConvertTo(originImg);
	//change image brightness in a loop pixel by pixel
	changeImageBrightnessPixelByPixel(originImg);
}
//$$$$$$ Play with image contrast $$$$$$$$
void contrastFunctions(cv::Mat originImg)
{
	//change image contrast with '*' operator
	changeImageContrastWithOperators(originImg);
	//change image contrast with convert function and display
	changeImageContrastWithConvertTo(originImg);
	//change contrast brightness in a loop pixel by pixel
	changeImageContrastPixelByPixel(originImg);
}
//$$$$$$ Play with blending of images $$$$$$$$
void blendFunctions()
{
	//blending two images
	blendImagesWithAddWeighted();
}
//$$$$$$ Play with creating images $$$$$$$$
void grayFunctions(cv::Mat originImg)
{
	//change image to gray
	changeImageGrayWithImread(originImg);
	changeImageGrayWithCvtColor1(originImg); //RGB mode
	changeImageGrayWithCvtColor2(originImg); //BGR mode
}
//$$$$$$ Use basic drawing funs $$$$$$$$
void drawFunctions()
{
	//draw line
	drawLine();
	//draw ellipse
	drawEllipse();
}