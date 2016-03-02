	cvNamedWindow(window_name, CV_WINDOW_AUTOSIZE);	
	IplImage *img = cvCreateImage(cvSize(100, 100), 8, 3);
	cvSet(img, cvScalar(0, 0, 0));	// can assign various values.
	cvZero(img);					// assign only zeros.
	for (int y = 19; y < 40; y++) {
		uchar* ptr = (uchar*)(
			img->imageData + y * img->widthStep
			);
		for (int x = 4; x < 20; x++) {
			ptr[3 * x] = 255;
			ptr[3 * x + 1] = 0;
		}
	}
	cvShowImage(window_name, img);
	cvWaitKey(0);
	cvReleaseData(img);
	cvDestroyWindow(window_name);