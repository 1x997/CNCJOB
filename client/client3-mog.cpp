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
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <ctime>
#include <string>
 using boost::asio::ip::tcp;
 using namespace  std;
 using namespace cv;


 static bool recodeflag=false;
 static cv::Mat frame;
 static cv::Mat back;
 static cv::Mat fore;
 static Mat copyimg;
 static std::vector<std::vector<cv::Point>> contours;
 static cv::BackgroundSubtractorMOG2 bg;


 void initBackgroundSubtractorMOG2(){
 	bg.setInt("nmixtures", 3);
 	bg.setBool("detectShadows", false);
 }


 int main(int args, char *argv[])
 {
	//HOGDescriptor hog;
	//hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector()); /* 直接调用opencv里的HOG特征检测 */
	VideoCapture cap(0);                        /* open webcam */
 	if(!cap.isOpened())  
 	{  
 		return -1;  
 	}  
 	initBackgroundSubtractorMOG2();


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
 			frame.copyTo(copyimg);	
 			bg.operator ()(frame,fore);

 			bg.getBackgroundImage(back);
 			cv::erode(fore,fore,cv::Mat());
 			cv::dilate(fore,fore,cv::Mat());
 			cv::findContours(fore,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);//轮廓
 			if (contours.size()>0 )
 			{
				//如果轮廓的面积太小了也不用写到输出视频
 				for (int i = 0; i< contours.size(); i++)
 				{
 					double a=contourArea( contours[i],false);
					if (a>500)//轮廓面积小于1000
					{
						cv::drawContours(frame,contours,i,cv::Scalar(0,0,255),2);
						recodeflag=true; //记录该帧并发送
					}
					else
					{
						recodeflag=false;//不发送
					}
				}

			}
			else
			{
				recodeflag=false;
			}
			if (recodeflag)
			{
			}
			if (!frame.empty())
			{
				imshow("rigger",frame); 
			}
			if (!copyimg.empty())
			{
				imshow("webcam",copyimg); 
			}
			char c=(char)waitKey(100);//退出且关闭socket
			if (c==27)
			{
				break;
			}
				copyimg = (copyimg.reshape(0,1)); // to make it continuous
					std::string message((char *)copyimg.data,230400); /* the size of mat data is 320*240*3 */

				if (recodeflag)
				{
					socket.write_some(boost::asio::buffer(message), ignored_error); //发送
					cout<<"send image finished"<<endl;
				}

			}
		socket.close();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		return 0;
	}
