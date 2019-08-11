#include "controllers/sim_controller.h"
#include <iostream>
namespace controllers
{
SimController::SimController (){}

SimController::~SimController (){}

void SimController::moveTo(const navigation::direction &desiredDirection){

  navigation::Pose newPose = calcNewPose(desiredDirection);
  //virtual movement
  if (newPose != msrPose_){
    motionStatus_ = MOVING;
    msrPose_= newPose;
    motionStatus_ = ON_GOAL;
  }
  else
    motionStatus_ = ON_GOAL;

}

void SimController::moveTo(const navigation::Pose &desPose){
  //virtual movement
  if (desPose!=msrPose_){
    motionStatus_ = MOVING;
    msrPose_= desPose;
    motionStatus_ = ON_GOAL;
  }
  else
    motionStatus_ = ON_GOAL;

}

} // end of namespace controllers
