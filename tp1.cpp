#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <math.h>

using namespace cv;

void rotate(cv::Mat& src, double angle, cv::Mat& dst){
	int len = std::max(src.cols, src.rows);
	cv::Point2f src_center(len/2.0F, len/2.0F);
	cv::Mat rot_mat = cv::getRotationMatrix2D(src_center, angle, 1.0);
	cv::warpAffine(src, dst, rot_mat, cv::Size(len, len));
} /* rotate */

void rotate1(cv::Mat& src, double angle, cv::Mat& dst){
	cv::Point2f src_center(src.cols/2.0F, src.rows/2.0F);
	cv::Mat rot_mat = getRotationMatrix2D(src_center, angle, 1.0);
	cv::warpAffine(src, dst, rot_mat, src.size());
} /* rotate */

void resize(cv::Mat& src, int percent, cv::Mat& dst){
	dst.cols = (int)(src.cols*percent)/100;
	dst.rows = (int)(src.rows*percent)/100;
	cv::resize(src, dst, dst.size());
} /* resize */

int main( int argc, char** argv ){
	Mat image, i_rotate, i_resize, i_resize1;
	image = imread( argv[1], 1 );

	if( argc != 2 || !image.data ){
		printf( "No image data \n" );
		return -1;
	}

	namedWindow( "TP1 - Introducao a Computacao Visual", CV_WINDOW_AUTOSIZE );
	imshow( "TP1 - Introducao a Computacao Visual", image );

	waitKey(0);

	rotate (image, -30, i_rotate);

	namedWindow( "TP1 - Introducao a Computacao Visual", CV_WINDOW_AUTOSIZE );
	imshow( "TP1 - Introducao a Computacao Visual", i_rotate );

	waitKey(0);

	rotate (image, 60, i_rotate);

	namedWindow( "TP1 - Introducao a Computacao Visual", CV_WINDOW_AUTOSIZE );
	imshow( "TP1 - Introducao a Computacao Visual", i_rotate );

	waitKey(0);

	rotate (image, 90, i_rotate);

	namedWindow( "TP1 - Introducao a Computacao Visual", CV_WINDOW_AUTOSIZE );
	imshow( "TP1 - Introducao a Computacao Visual", i_rotate );

	waitKey(0);

	rotate (image, 120, i_rotate);

	namedWindow( "TP1 - Introducao a Computacao Visual", CV_WINDOW_AUTOSIZE );
	imshow( "TP1 - Introducao a Computacao Visual", i_rotate );

	waitKey(0);
	rotate1 (image, -30, i_rotate);

	namedWindow( "TP1 - Introducao a Computacao Visual", CV_WINDOW_AUTOSIZE );
	imshow( "TP1 - Introducao a Computacao Visual", i_rotate );

	waitKey(0);

	rotate1 (image, 60, i_rotate);

	namedWindow( "TP1 - Introducao a Computacao Visual", CV_WINDOW_AUTOSIZE );
	imshow( "TP1 - Introducao a Computacao Visual", i_rotate );

	waitKey(0);
	rotate1 (image, 90, i_rotate);

	namedWindow( "TP1 - Introducao a Computacao Visual", CV_WINDOW_AUTOSIZE );
	imshow( "TP1 - Introducao a Computacao Visual", i_rotate );

	waitKey(0);

	rotate1 (image, 120, i_rotate);

	namedWindow( "TP1 - Introducao a Computacao Visual", CV_WINDOW_AUTOSIZE );
	imshow( "TP1 - Introducao a Computacao Visual", i_rotate );

	waitKey(0);
	resize (image, 75, i_resize);

	namedWindow( "TP1 - Introducao a Computacao Visual", CV_WINDOW_AUTOSIZE );
	imshow( "TP1 - Introducao a Computacao Visual", i_resize );

	waitKey(0);

	resize (image, 50, i_resize1);

	namedWindow( "TP1 - Introducao a Computacao Visual", CV_WINDOW_AUTOSIZE );
	imshow( "TP1 - Introducao a Computacao Visual", i_resize1 );

	waitKey(0);

	return 0;
}
