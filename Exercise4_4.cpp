#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"

int g_slider_position = 0;
int g_st_play = 0;
bool g_play;
CvCapture* g_capture = NULL;

void onPlay(int pos){
	if (pos == 1) {
		g_play = true;
	}
	else{
		g_play = false;
	}
}

void onTrackbarSlide(int pos) {
	cvSetCaptureProperty(
		g_capture,
		CV_CAP_PROP_POS_FRAMES,
		pos
		);
}

int main(int argc, char** argv) {
	cvNamedWindow("Window", CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture("opencv.mp4");
	int frames = (int)cvGetCaptureProperty(
		g_capture,
		CV_CAP_PROP_FRAME_COUNT
		);
	if (frames != 0) {
		cvCreateTrackbar(
			"Position",
			"Window",
			&g_slider_position,
			frames,
			onTrackbarSlide
			);
		cvCreateTrackbar(
			"Play",
			"Window",
			&g_st_play,
			1,
			onPlay
			);
	}
	IplImage* frame;
	int i;
	cvSetTrackbarPos("Play", "Window", 0);
	g_play = false;
	frame = cvQueryFrame(g_capture);
	// While loop (as in Example 2) capture & show video
	while (1){
		if (g_play) {
			frame = cvQueryFrame(g_capture);
			i = cvGetTrackbarPos("Position", "Window");
			cvSetTrackbarPos("Position", "Window", i + 10);
			if (!frame) break;
		}
		cvShowImage("Window", frame);
		char c = cvWaitKey(33);
		if (c == 27) break;
	}

	cvReleaseCapture(&g_capture);
	cvDestroyWindow("Window_Status");
	return 0;
}