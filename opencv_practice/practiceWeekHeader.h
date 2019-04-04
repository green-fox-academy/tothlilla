#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
 //type of window - changable
using namespace std;
//using namespace cv;

void changeImageBrightnessWithScalar(cv::Mat originImg);
void changeImageBrightnessWithConvertTo(cv::Mat originImg);
