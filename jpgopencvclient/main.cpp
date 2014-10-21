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
 * read 端
 *
 */
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>
#include <vector>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/thread/thread.hpp>
using boost::asio::ip::tcp;
using namespace  std;
using namespace cv;
Mat  pngimage ;
int main()
{
    try
    {
        boost::asio::io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 3200));
        tcp::socket socket(io_service);
        acceptor.accept(socket);
        boost::system::error_code error;
        for (;;)
        {
            boost::array< char, 16 > header;
            std::size_t length = boost::asio::read(socket, boost::asio::buffer(header), boost::asio::transfer_all(), error);
            cout<<"length : "<< length<<endl;
            cout<<"length data : "<<string(header.begin(),header.end())<<endl;
            std::vector<uchar> body(atoi((string(header.begin(),header.end())).c_str()));
            std::size_t lengthbody = boost::asio::read(socket, boost::asio::buffer(body), boost::asio::transfer_all(), error);
            cout << "lengthbody : "<<lengthbody<<endl;
            pngimage = imdecode(Mat(body),CV_LOAD_IMAGE_COLOR);
            imshow("jpgopencvclient",pngimage);
            waitKey(10);
        }
        socket.close();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
