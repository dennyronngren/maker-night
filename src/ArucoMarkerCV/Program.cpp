#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
//#include <synchapi.h>

using namespace cv;
using namespace std;

int
main() {
	std::cout << "Welcome to Toobot!" << std::endl;

	//Mat image = Mat::zeros(300, 600, CV_8UC3);
	//circle(image, Point(250, 150), 100, Scalar(0, 255, 128), -100);
	//circle(image, Point(350, 150), 100, Scalar(255, 255, 255), -100);
	//imshow("Display Window", image);

	// create window
	namedWindow("Toobot camera feed", 1);

	// get the camera feed
	cv::VideoCapture capture(0);
	//capture.set(CAP_PROP_FPS, 10);
	Mat frame;
	while (true) {
		if (!capture.isOpened()) {
			break;
		}

		capture >> frame;

		std::vector<int> markerIds;
		std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
		cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
		cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
		cv::aruco::detectMarkers(inputImage, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);

		imshow("Toobot camera feed", frame);
		waitKey(100);
	}

	waitKey(0);
	return 0;
}
