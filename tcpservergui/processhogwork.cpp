#include "processhogwork.h"


processhogwork::processhogwork(Mat image)
{
    this->image=image;

}

processhogwork::~processhogwork()
{

}

void processhogwork::process()
{



//    vector<Rect> found;
//    HOGDescriptor defaultHog;
//    defaultHog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
//    defaultHog.detectMultiScale(image, found);
//    for(int i = 0; i < found.size(); i++)
//        {
//            Rect r = found[i];
//            rectangle(image, r.tl(), r.br(), Scalar(0, 255, 0), 2);//top left     bottom right
//        }
    image.copyTo(resultimage);


    emit finished();
    //return tempimg;

}
