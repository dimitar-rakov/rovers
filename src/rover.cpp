#include "rover.h"
namespace rover
{
Rover::Rover() : roverID_("RoverX"), roverName_("Dummy") {
  ptrController.reset(new controllers::Controller());
}

void Rover::moveTo(const navigation::Pose &desPose){
  ptrController->moveTo(desPose);
    if (ptrController->motionStatus()==controllers::ON_GOAL)
     logger_.writeDataToFile(pathname_, roverID_+outputFilenameSuffix_, ptrController->msrPose());

}

Rover::~Rover(){}

}
