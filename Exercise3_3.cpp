/*float sum(const CvMat* mat) {
		float s = 0.0f;
		for (int row = 0; row<mat->rows; row++) {
			const float* ptr = (const float*)(mat->data.ptr + row * mat->step);
			for (col = 0; col<mat->cols; col++) {
				s += *ptr++;
			}
		}
		return(s);
	}*/
	/*void saturate_sv(IplImage* img) {
		for (int y = 0; y<img->height; y++) {
			uchar* ptr = (uchar*)(
				img->imageData + y * img->widthStep
				);
			for (int x = 0; x<img->width; x++) {
				ptr[3 * x + 1] = 255;
				ptr[3 * x + 2] = 255;
			}
		}
	}*/
	cvNamedWindow(window_name, CV_WINDOW_AUTOSIZE);	
	/* Create a two-dimensional matrix with three channels of type byte with data size
	100-by-100. Set all the values to 0. */
	CvMat *mat = cvCreateMat(100, 100, CV_8UC3);
	cvSetZero(mat);
	/* Draw Circle*/
	uchar *ptr;
	int i, j;
	for (i = 19; i < 40; i++){
		for (j = 4; j < 20; j++){
			ptr = cvPtr2D(mat, i, j);
			*ptr++ = 0;
			*ptr++ = 255;
			*ptr = 0;
		}
	}
	cvShowImage(window_name, mat);
	cvWaitKey(0);
	cvReleaseData(mat);
	cvDestroyWindow(window_name);