#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"

double m = -1.07f;
	int i;
	m = CV_IABS(m);
	cvCeil(m);
	cvFloor(m);
	i = cvRound(m);
	CvRNG *rng;
	cvRandInt(rng);
	CvPoint2D32f point32;
	CvPoint	point;
	point = cvPointFrom32f(point32);
	point32 = cvPointTo32f(point);