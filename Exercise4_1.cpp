#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"

int main(){
	
	CvCapture *capture = cvCreateFileCapture("opencv.mp4");
	double fps, width, height;
	IplImage *img;
	fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
	width = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
	height = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
	img = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);
	IplImage *gray_img = cvCreateImage(cvSize(img->width, img->height), IPL_DEPTH_8U, 1);
	IplImage *edge_img = cvCreateImage(cvSize(img->width, img->height), IPL_DEPTH_8U, 1);
	IplImage *temp = cvCreateImage(cvSize(img->width, img->height), IPL_DEPTH_8U, 3);
	CvFont font;
	cvInitFont(&font, CV_FONT_HERSHEY_PLAIN, 5, 5, (0, 0), 2, 8);
	cvNamedWindow("Original", 1);
	cvMoveWindow("Original", 0, 0);
	cvNamedWindow("GrayScale", 1);
	cvMoveWindow("GrayScale", img->width, 0); 
	cvNamedWindow("EdgeDetection", 1);
	cvMoveWindow("EdgeDetection", 0, img->height);
	cvNamedWindow("MergedWindow", 1);
	IplImage *merge_img = cvCreateImage(cvSize(img->width * 3, img->height), IPL_DEPTH_8U, 3);
	IplImage *hd_ori = cvCreateImageHeader(cvSize(img->width, img->height), IPL_DEPTH_8U, 3);
	IplImage *hd_gray = cvCreateImageHeader(cvSize(img->width, img->height), IPL_DEPTH_8U, 3);
	IplImage *hd_edge = cvCreateImageHeader(cvSize(img->width, img->height), IPL_DEPTH_8U, 3);
	hd_ori->widthStep = hd_gray->widthStep = hd_edge->widthStep = merge_img->widthStep;
	hd_ori->imageData = merge_img->imageData;
	hd_gray->imageData = merge_img->imageData + img->width * 3;
	hd_edge->imageData = merge_img->imageData + img->width * 6;
	img->widthStep = merge_img->widthStep;
	int c;
	while (1) {
		img = cvQueryFrame(capture);
		cvCopy(img, hd_ori);
		cvShowImage("Original", img);
		cvCvtColor(img, gray_img, CV_BGR2GRAY);
		cvCvtColor(gray_img, temp, CV_GRAY2BGR);
		cvCopy(temp, hd_gray);
		cvShowImage("GrayScale", gray_img);
		cvCanny(gray_img, edge_img, 10, 100, 3);
		cvCvtColor(edge_img, temp, CV_GRAY2BGR);
		cvCopy(temp, hd_edge);
		cvShowImage("EdgeDetection", edge_img);
		c = cvWaitKey(cvRound(200 / fps));
		cvPutText(merge_img, "Original", cvPoint(0, 100), &font, cvScalar(255, 0, 0));
		cvPutText(merge_img, "GrayScale", cvPoint(img->width, 100), &font, cvScalar(0, 255, 0));
		cvPutText(merge_img, "EdgeDetection", cvPoint(img->width * 2, 100), &font, cvScalar(0, 0, 255));
		cvShowImage("MergedWindow", merge_img);
		if (c == 27) break;
	}
}