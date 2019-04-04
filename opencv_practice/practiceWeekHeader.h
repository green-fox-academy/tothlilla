#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

//using namespace std;
//using namespace cv;

void changeImageBrightnessWithScalar(cv::Mat originImg);
void changeImageBrightnessWithConvertTo(cv::Mat originImg);
void changeImageBrightnessPixelByPixel(cv::Mat originImg);

void changeImageContrastWithOperators(cv::Mat originImg);
void changeImageContrastWithConvertTo(cv::Mat originImg);
void changeImageContrastPixelByPixel(cv::Mat originImg);