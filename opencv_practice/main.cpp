#include "practiceWeekHeader.h"

int main(int argc, char** argv)
{
	//create a matrix object
	cv::Mat originImg;
	//open origin image
	originImg = cv::imread("lena.jpg"); //default read mode of image
	//use prepared functions
	finishedFunctions(originImg);
	//cv::waitKey(0); //display infinite time
	cv::waitKey(5000); //display 5 sec

	return 0;
}
