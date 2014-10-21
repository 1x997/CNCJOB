/*
 * 使用了boost.asio 传输 opencv 获取的webcam 图像，传输的图像经过jpg压缩，传输的字节数大约为34000
 * 是原来 240*320*3 的1/6 速度更加快了。
 *
 * yuliyang@qq.com
 *
 * 2014/10/21
 *
 * @copyright yuliyang@qq.com
 *
 *
 *
 *
 * write端
 *
 */
#include <fstream>
#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include <ctime>
#include <string>
#include <cstdio>
using boost::asio::ip::tcp;
using namespace  std;
using namespace cv;

int main(int args, char *argv[])
{
    VideoCapture cap(0);                        /* open webcam */
    if(!cap.isOpened())
    {
        return -1;
    }
    Mat frame;
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);      /* set width */
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);     /* set height */
    try
    {
        boost::asio::io_service io_service;
        tcp::endpoint end_point(boost::asio::ip::address::from_string("127.0.0.1"), 3200);
        tcp::socket socket(io_service);
        boost::system::error_code ignored_error;
        socket.connect(end_point);
        while (true)
        {
            cap>>frame;
            char c=(char)waitKey(100);
            if (c==27)
            {
                break;
            }
            //(1) jpeg compression
            vector<uchar> buff;//buffer for coding
            vector<int> param = vector<int>(2);
            param[0]=CV_IMWRITE_JPEG_QUALITY;
            param[1]=95;//default(95) 0-100
            imencode(".jpg",frame,buff,param);
            cout<<"coded file size(jpg)"<<buff.size()<<endl;//fit buff size automatically.
            string headlength(std::to_string(buff.size()));
            headlength.resize(16);
            std::size_t length = boost::asio::write(socket, boost::asio::buffer(headlength), boost::asio::transfer_all(), ignored_error);
            cout << "length : "<<length<<endl;
            std::size_t lengthbody = boost::asio::write(socket, boost::asio::buffer(string(buff.begin(),buff.end())), boost::asio::transfer_all(), ignored_error);
            cout << "lengthbody : "<<lengthbody<<endl;
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

//int main(int argc, char** argv)
//{
//        Mat src = imread("G://py-workspace//1.jpg");
//        //(1) jpeg compression
//        vector<uchar> buff;//buffer for coding
//        vector<int> param = vector<int>(2);
//        param[0]=CV_IMWRITE_JPEG_QUALITY;
//        param[1]=95;//default(95) 0-100
//        imencode(".jpg",src,buff,param);
//        cout<<"coded file size(jpg)"<<buff.size()<<endl;//fit buff size automatically.

//        Mat jpegimage = imdecode(Mat(buff),CV_LOAD_IMAGE_COLOR);
//        //(2) png compression
//        param[0]=CV_IMWRITE_PNG_COMPRESSION;
//        param[1]=3;//default(3)  0-9.
//        imencode(".png",src,buff,param);
//        cout<<"coded file size(png)"<<buff.size()<<endl;
//        Mat pngimage = imdecode(Mat(buff),CV_LOAD_IMAGE_COLOR);

//        //(3) intaractive jpeg compression
//        char name[64];
//        namedWindow("jpg");
//        int q=95;
//        createTrackbar("quality","jpg",&q,100);
//        int key = 0;
//        while(key!='q')
//        {
//                param[0]=CV_IMWRITE_JPEG_QUALITY;
//                param[1]=q;
//                imencode(".jpg",src,buff,param);
//                Mat show = imdecode(Mat(buff),CV_LOAD_IMAGE_COLOR);

//                double psnr = getPSNR(src,show);//get PSNR
//                double bpp = 8.0*buff.size()/(show.size().area());//bit/pixe;
//                sprintf(name,"quality:%03d, %.1fdB, %.2fbpp",q,psnr,bpp);
//                putText(show,name,Point(15,50), FONT_HERSHEY_SIMPLEX,1,CV_RGB(255,255,255),2);
//                imshow("jpg",show);
//                key = waitKey(33);

//                if(key =='s')
//                {
//                        //(4) data writing
//                        sprintf(name,"q%03d_%.2fbpp.png",q,bpp);
//                        imwrite(name,show);

//                        sprintf(name,"q%03d_%.2fbpp.jpg",q,bpp);
//                        param[0]=CV_IMWRITE_JPEG_QUALITY;
//                        param[1]=q;
//                        imwrite(name,src,param);;
//                }
//        }
//}
//double getPSNR(Mat& src1, Mat& src2, int bb)
//{
//        int i,j;
//        double sse,mse,psnr;
//        sse = 0.0;

//        Mat s1,s2;
//        cvtColor(src1,s1,CV_BGR2GRAY);
//        cvtColor(src2,s2,CV_BGR2GRAY);

//        int count=0;
//        for(j=bb;j<s1.rows-bb;j++)
//        {
//                uchar* d=s1.ptr(j);
//                uchar* s=s2.ptr(j);

//                for(i=bb;i<s1.cols-bb;i++)
//                {
//                        sse += ((d[i] - s[i])*(d[i] - s[i]));
//                        count++;
//                }
//        }
//        if(sse == 0.0 || count==0)
//        {
//                return 0;
//        }
//        else
//        {
//                mse =sse /(double)(count);
//                psnr = 10.0*log10((255*255)/mse);
//                return psnr;
//        }
//}

