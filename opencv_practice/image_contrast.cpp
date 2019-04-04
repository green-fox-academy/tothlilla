#include "practiceWeekHeader.h"

void changeImageContrastWithOperators(cv::Mat originImg)
{
	cv::Mat brightImg = originImg * 2;
	cv::namedWindow("image5", cv::WINDOW_AUTOSIZE);
	cv::moveWindow("image5", 500, 280);
	imshow("image5", brightImg);
}

void changeImageContrastWithConvertTo(cv::Mat originImg)
{
	cv::Mat brightImg;
	//image.convertTo(new_image, -1, alpha, beta);
	//double alpha contrast
	//int beta brightness
	originImg.convertTo(brightImg, -1, 0.5, 0);
	cv::namedWindow("image6", cv::WINDOW_AUTOSIZE);
	cv::moveWindow("image6", 500, 560);
	imshow("image6", originImg);
}

void changeImageContrastPixelByPixel(cv::Mat originImg) {
	//Initial pixel values equal to zero, same size and type as the original image
	cv::Mat brightImg = cv::Mat::zeros(originImg.size(), originImg.type());
	double alpha = 200;
	for (int y = 0; y < originImg.rows; y++) {
		for (int x = 0; x < originImg.cols; x++) {
			for (int c = 0; c < originImg.channels(); c++) {
				brightImg.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(alpha * originImg.at<cv::Vec3b>(y, x)[c]);
			}
		}
	}
	cv::namedWindow("image7", cv::WINDOW_AUTOSIZE);
	cv::moveWindow("image7", 1000, 0);
	imshow("image7", brightImg);
}