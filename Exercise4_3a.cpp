#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"

CvRect g_rect;
IplImage *g_src;
//Readme
/* I'm not sure about it.
on callback the parameter "param" holds its value during main loop. never release.
*/
void on_mouseclick(int event, int x, int y, int flags, void* param){
	IplImage *image = (IplImage*) param;
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		g_rect.x = x;
		g_rect.y = y;
		cvShowImage("Window", image);
		break;
	case CV_EVENT_LBUTTONUP:
		image = cvCloneImage(g_src);
		g_rect.width = x - g_rect.x;
		g_rect.height = y - g_rect.y;
		IplImage *hd_img = cvCreateImageHeader(cvSize(g_rect.width, g_rect.height), IPL_DEPTH_8U, 3);
		hd_img->widthStep = image->widthStep;
		hd_img->imageData = image->imageData + g_rect.y * image->widthStep + g_rect.x * 3;
		cvNot(hd_img, hd_img);
		cvShowImage("Window", image);
		// you can use cvRectangle instead.
		break;
	/*default:
		break;*/
	}
}

int main(){
	IplImage *img;
	img = cvLoadImage("opencv.jpg", 1);
	g_src = cvCloneImage(img);
	cvNamedWindow("Window", 1);
	cvSetMouseCallback("Window", on_mouseclick, img);
	cvShowImage("Window", img);
	cvWaitKey(0);
}