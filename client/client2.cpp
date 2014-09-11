/*
 * =====================================================================================
 *
 *       Filename:  client.cpp
 *	  	
 *    Description:  stream opencv Mat frame to server by tcp with boost asio
 *
 *
 *        Version:  1.0
 *        Created:  2014/4/29 11:40:20
 *         Author:  yuliyang
 *
 *		     Mail:  wzyuliyang911@gmail.com
 *			 Blog:  http://www.cnblogs.com/yuliyang
 *
 * =====================================================================================
 */

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>  
#include <ctime>
#include <string>
using boost::asio::ip::tcp;
using namespace  std;
using namespace cv;

int main(int args, char *argv[])
{
//	HOGDescriptor hog;
//	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector()); /* 直接调用opencv里的HOG特征检测 */
//	VideoCapture cap(0);                        /* open webcam */
//	if(!cap.isOpened())  
//	{  
//		return -1;  
//	}  

	
	Mat frame;
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);      /* set width */
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);     /* set height */

	try
	{
		boost::asio::io_service io_service;
		tcp::endpoint end_point(boost::asio::ip::address::from_string(argv[1]), 3200);

		tcp::socket socket(io_service);
		
		boost::system::error_code ignored_error;
		socket.connect(end_point);
		while (true)
		{
			cap>>frame;
						
			imshow("client",frame);   
		
			char c=(char)waitKey(100);
			if (c==27)
			{
				break;
			}
	
			frame = (frame.reshape(0,1)); // to make it continuous
			
			std::string message((char *)frame.data,230400); /* the size of mat data is 320*240*3 */
			socket.write_some(boost::asio::buffer(message), ignored_error);
			cout<<"send image finished"<<endl;
			
			
		
		}
		socket.close();
		
		

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

		return 0;
}
