
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{

	/*int height = 520;
	int width = 840;
	Mat img(height, width, CV_8UC3);

	Point textOrg(100, img.rows / 2);
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
	double fontScale = 2;
	Scalar color(200, 100, 50);
	putText(img, "OpenCV step By Step", textOrg, fontFace, fontScale, color);
	namedWindow("helloy",0);
	imshow("helloy", img);
	waitKey(0);*/
		setlocale(LC_ALL, "Russian");
	char filename[80]; // read.jpg
		cout << "Введите имя файла, в который хотите внести изменения, и нажмите Enter" << endl;
	cin.getline(filename, 80);
	cout << "Открыть файл";
	cout << filename << endl;
	Mat img = imread(filename, 1);
	
	imshow("Load", img);
	Mat scr_gray;
	Mat canny_output;
	Mat _img;
	cvtColor(img, scr_gray, COLOR_RGB2GRAY);
	blur(scr_gray, scr_gray, Size(3, 3));

	double otsu_thresh_val = threshold(scr_gray, _img, 0, 255, THRESH_BINARY | THRESH_OTSU);
	double hight_thresh_val = otsu_thresh_val, lower_thresh_val = otsu_thresh_val * 0.5;
		cout << otsu_thresh_val;
	Canny(scr_gray, canny_output, lower_thresh_val, hight_thresh_val, 3);
	imshow("Load", canny_output);
	imwrite("canny_output.jpg", canny_output);
	waitKey(0);
	system("pause");

	return 0;

}
