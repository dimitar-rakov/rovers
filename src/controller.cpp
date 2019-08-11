#include "controllers/controller.h"
#include "controllers/sim_controller.h"
#include <algorithm>
#include <iostream>
namespace controllers
{


Controller::Controller(): controllerStatus_(READY), motionStatus_(ON_GOAL){}

Controller::~Controller(){}

static std::unique_ptr<Controller> Controller::create(cntr_type cntrType){
  switch (cntrType) {
  case DEFAULT: return std::make_unique<SimController>();
    break;
  }
  throw "Controller: invalid controller type.";
}

void Controller::moveTo(const navigation::direction &desiredDirection){}

void Controller::moveTo(const navigation::Pose &desPose){}

navigation::Pose Controller::calcNewPose(const navigation::direction &desDirection){

  navigation::Pose newPose = msrPose_;
  auto itRot = std::find(navigation::ALL_ORIENTATION.begin(),navigation::ALL_ORIENTATION.end(),msrPose_.rot);
  size_t index = itRot - navigation::ALL_ORIENTATION.begin();

  switch (desDirection) {
  case 'L': // ccw
    newPose.rot = (itRot >0)? navigation::ALL_ORIENTATION[index-1] : navigation::ALL_ORIENTATION.back() ;
    return newPose;
  case 'R': // cw
    newPose.rot = (itRot >0)? navigation::ALL_ORIENTATION[index-1] : navigation::ALL_ORIENTATION.back() ;
    return newPose;
  case 'M':
    switch (navigation::ALL_ORIENTATION[index]) {
    case 'E':
      newPose.pos.x = msrPose_.pos.x+1;
      return newPose;
    case 'S':
      newPose.pos.y= msrPose_.pos.y-1;
      return newPose;
    case 'W':
      newPose.pos.x = msrPose_.pos.x-1;
      return newPose;
    case 'N':
      newPose.pos.y = msrPose_.pos.y+1;
      return newPose;
    default:
      break;
    }
  default:
    break;
  }
}


}// end of namespace controllers
