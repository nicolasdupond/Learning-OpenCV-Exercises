#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"

void on_mouseclick(int event, int x, int y, int flags, void* param){
	IplImage *image = (IplImage*)param;
	CvFont font;
	cvInitFont(&font, CV_FONT_HERSHEY_PLAIN, 1, 1);
	uchar* ptr;
	if (event == CV_EVENT_LBUTTONDOWN) {
		ptr = (uchar*)image->imageData + y * image->widthStep + x * 3;
		char text[20];
		sprintf(text, "%d  %d  %d", ptr[0], ptr[1], ptr[2]);
		cvPutText(image, text, cvPoint(x, y), &font, CvScalar(255, 0, 0));
		cvShowImage("Window", image);
	}
}

int main(){
	IplImage *img;
	img = cvLoadImage("opencv.jpg", 1);
	cvNamedWindow("Window", 1);
	cvSetMouseCallback("Window", on_mouseclick, img);
	cvShowImage("Window", img);
	cvWaitKey(0);
}