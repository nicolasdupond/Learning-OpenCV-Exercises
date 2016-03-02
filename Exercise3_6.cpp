cvNamedWindow(window_name, CV_WINDOW_AUTOSIZE);
	IplImage *img = cvCreateImage(cvSize(210, 210), 8, 1);
	cvZero(img);
	for (int i = 0; i < 10; i++){
		cvSetImageROI(img, cvRect(i * 10, i * 10, img->width - i * 20, img->height - i * 20));
		cvSet(img, i * 20);
		cvResetImageROI(img);
	}

	cvShowImage(window_name, img);
	cvWaitKey(0);
	cvReleaseData(img);
	cvDestroyWindow(window_name);