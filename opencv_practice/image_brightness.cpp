#include "practiceWeekHeader.h"

void changeImageBrightnessWithScalar(cv::Mat originImg)
{
	cv::Mat brightImg = originImg + cv::Scalar(75, 75, 75);
	cv::namedWindow("image2", cv::WINDOW_AUTOSIZE);
	cv::moveWindow("image2", 0, 280);
	imshow("image2", brightImg);
}

void changeImageBrightnessWithConvertTo(cv::Mat originImg)
{
	cv::Mat brightImg;
	//image.convertTo(new_image, -1, alpha, beta);
	//double alpha contrast
	//int beta brightness
	originImg.convertTo(brightImg, -1, 1, -205);
	cv::namedWindow("image3", cv::WINDOW_AUTOSIZE);
	cv::moveWindow("image3", 0, 560);
	imshow("image3", originImg);
}

void changeImageBrightnessPixelByPixel(cv::Mat originImg) {
	//Initial pixel values equal to zero, same size and type as the original image
	cv::Mat brightImg = cv::Mat::zeros(originImg.size(), originImg.type());
	int beta = 200;
	for (int y = 0; y < originImg.rows; y++) {
		for (int x = 0; x < originImg.cols; x++) {
			for (int c = 0; c < originImg.channels(); c++) {
				brightImg.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(originImg.at<cv::Vec3b>(y, x)[c] + beta);
			}
		}
	}
	cv::namedWindow("image4", cv::WINDOW_AUTOSIZE);
	cv::moveWindow("image4", 500, 0);
	imshow("image4", brightImg);
}


