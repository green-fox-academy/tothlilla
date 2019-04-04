#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
 //type of window - changable
using namespace std;
using namespace cv;

void changeImageBrightnessWithScalar(Mat originImg);
void changeImageBrightnessWithConvertTo(Mat originImg);
