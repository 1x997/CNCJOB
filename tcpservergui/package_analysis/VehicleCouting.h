#pragma once

#include <boost/config/user.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <cv.h>
#include <highgui.h>

#include "../package_tracking/cvblob/cvblob.h"

typedef struct CarSpeed
{
    time_t starttime;
    time_t lasttime;
    CvPoint2D64f startcentroid;
    CvPoint2D64f lastcentroid;
}
CarSpeed;

typedef struct IdSpeed
{
    int id;
    double speed;

}
IdSpeed;


enum LaneOrientation
{
  LO_NONE       = 0,
  LO_HORIZONTAL = 1,
  LO_VERTICAL   = 2
};

enum VehiclePosition
{
  VP_NONE = 0,
  VP_A  = 1,
  VP_B  = 2
};

class VehicleCouting
{
private:
  bool firstTime;
  bool showOutput;
  int key;
  cv::Mat img_input;
  cvb::CvTracks tracks;
  std::map<cvb::CvID, std::vector<CvPoint2D64f>> points;
  LaneOrientation LaneOrientation;
  std::map<cvb::CvID, VehiclePosition> positions;
  long countAB;
  long countBA;
  int img_w;
  int img_h;
  int showAB;


public:
  std::map<cvb::CvID, CarSpeed> carspeeds;

  std::vector<IdSpeed> idspeeds;

  VehicleCouting();
  ~VehicleCouting();


  time_t start;
  time_t end;


  CvPoint2D64f startpoint;
  CvPoint2D64f endpoint;

  cv::Mat getInput();
  void setInput(const cv::Mat &i);
  void setTracks(const cvb::CvTracks &t);
  void process();



  std::vector<IdSpeed> getIdspeeds() const;
  void setIdspeeds(const std::vector<IdSpeed> &value);

private:
  VehiclePosition getVehiclePosition(const CvPoint2D64f centroid);

  void saveConfig();
  void loadConfig();
};
