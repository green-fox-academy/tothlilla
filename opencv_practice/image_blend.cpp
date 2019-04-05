#include "practiceWeekHeader.h"

void blendImagesWithAddWeighted()
{
	cv::Mat src1, src2, dst;
	src1 = cv::imread("uranus.jpg");
	src2 = cv::imread("lena.jpg");
	cv::namedWindow("Linear Blend", cv::WINDOW_AUTOSIZE);
	cv::resize(src1, src1, src2.size());
	cv::moveWindow("Linear Blend", 1000, 280);
	double alpha = 0.2;
	double beta = (1.0 - alpha);
	cv::addWeighted(src1, alpha, src2, beta, 0.0, dst);
	cv::imshow("Linear Blend", dst);
}
