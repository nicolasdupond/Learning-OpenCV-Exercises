#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"

int main(){
	cvNamedWindow("Draw Circle", CV_WINDOW_AUTOSIZE);
	/* Create a two-dimensional matrix with three channels of type byte with data size
	100-by-100. Set all the values to 0. */
	CvMat *mat = cvCreateMat(100, 100, CV_8UC3);
	cvSetZero(mat);
	/* Draw Circle*/
	CvPoint center;
	CvScalar c_color;
	center.x = cvRound(mat->rows / 2);
	center.y = cvRound(mat->cols / 2);
	c_color = (0, 0, 255); //Here rgb.
	cvCircle(mat, center, 10, c_color, 2, 8);
	cvShowImage("Draw Circle", mat);
	cvWaitKey(0);
	cvReleaseData(mat);
	cvDestroyWindow("Draw Circle");
}