#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

//using namespace std;
//using namespace cv;

//----------START-------------
void finishedFunctions(cv::Mat originImg);
//----------TOPICS------------
void display_basic_image_with_error_handler(cv::Mat originImg);
void brightFunctions(cv::Mat originImg);
void contrastFunctions(cv::Mat originImg);
void grayFunctions(cv::Mat originImg);
void blendFunctions();
void drawFunctions();

void changeImageBrightnessWithScalar(cv::Mat originImg);
void changeImageBrightnessWithConvertTo(cv::Mat originImg);
void changeImageBrightnessPixelByPixel(cv::Mat originImg);

void changeImageContrastWithOperators(cv::Mat originImg);
void changeImageContrastWithConvertTo(cv::Mat originImg);
void changeImageContrastPixelByPixel(cv::Mat originImg);

void blendImagesWithAddWeighted();

void changeImageGrayWithImread(cv::Mat originImg);
void changeImageGrayWithCvtColor1(cv::Mat originImg);
void changeImageGrayWithCvtColor2(cv::Mat originImg);

void drawLine();
void drawEllipse();