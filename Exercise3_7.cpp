cvNamedWindow(window_name, CV_WINDOW_AUTOSIZE);
	IplImage *img = cvLoadImage("opencv-logo2.jpg", 1);
	IplImage *img_r = cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
	IplImage *img_g = cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
	IplImage *img_b = cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
	IplImage *clone1, *clone2;
	cvSplit(img, img_b, img_g, img_r, NULL);  //if you don't want all, you can choose the others to NULL. ex: cvSplit(img, img1, NULL, NULL)
	clone1 = cvCloneImage(img_g);
	clone2 = cvCloneImage(img_g);
	double min_g, max_g;
	cvMinMaxLoc(img_g, &min_g, &max_g, NULL, NULL, NULL); //this function handles only single channel.
	// if you need location of those values, use cvMinMaxLoc(img_g, min_g, max_g, min_ptr, max_ptr, NULL);
	
	cvSet(clone1, CvScalar((max_g - min_g) / 2), NULL);
	cvZero(clone2);
	// erase the data under threshold.
	cvCmp(img_g, clone1, clone2, CV_CMP_GE); //CV_CMP_GE: Greater or Equal, only handle single channel images
	cvNamedWindow("AfterCmp", 1);
	cvShowImage("AfterCmp", clone2);
	cvNamedWindow("Green", 1);
	cvShowImage("Green", img_g);
	cvNamedWindow("Average", 1);
	cvShowImage("Average", clone1);
	cvSubS(img_g, (max_g - min_g) / 4, img_g, clone2);
	/*cvNamedWindow("Last", 1);
	cvShowImage("Last", clone2);*/
	
	cvShowImage(window_name, img_g);
	
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&img_r);
	cvReleaseImage(&img_g);
	cvReleaseImage(&img_b);
	cvDestroyWindow(window_name);