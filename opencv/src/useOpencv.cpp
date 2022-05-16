#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main(int argc,char** argv){
	Mat src = imread("./data/girl1.jpg"); //读取图片
	if (src.empty()) {                     //判断是否找到图片
		printf("没有找到图片 ");           //输出文字
		return -1;
	}
	else
	{
		namedWindow("input",WINDOW_AUTOSIZE);// 显示窗口命名为input ；WINDOW_AUTOSIZE显示大小为图片自定义大小，且不可以更改大小
		imshow("input",src); //显示
		waitKey(0);//显示的毫秒时间，如果函数参数<=0表示一直显示。>0表示显示的时间
		destroyAllWindows();
		return 0;
 
	}
}
