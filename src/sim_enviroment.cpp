#include "sim_enviroment.h"
#include <iostream>
SimEnviroment::SimEnviroment(std::string inPathname, std::string inFilename,
                             std::string outPathname, std::string outFilenameSuffix)
  :inPathname_(inPathname),
    inFilename_(inFilename),
    outPathname_(outPathname),
    outFilenameSuffix_(outFilenameSuffix)


{
  map_ptr= std::make_unique<nav_map::Map>(nav_map::Map());
  dataParser_ptr.reset(new data_parser::DataParser()); // Move constructor disabled
}

void SimEnviroment::runSimpleScenario(){
  // Init map corners
  navigation::Position leftCorner(0,0);
  navigation::Position rightCorner = dataParser_ptr->readRightCornerFromFile(inPathname_,inFilename_);
  map_ptr->initCorners(leftCorner, rightCorner);


  dataParser_ptr->readAllDataFromFile(inPathname_,inFilename_);

  // Init rovers size
  rovers_ptr.resize(dataParser_ptr->roversInitPoses().size());

  //Navigation
  for (size_t i=0; i<rovers_ptr.size(); i++){
    rovers_ptr[i].reset(new rover::MarsRover());
    std::string roverID = "Rover"+std::to_string(i+1);
    rovers_ptr[i]->init(roverID,outPathname_, outFilenameSuffix_ );
    navigation::Pose initPose= dataParser_ptr->roversInitPoses()[i];
    if (!map_ptr->isCellFree(initPose.pos)){
      std::cout<< "\nCell is occupied. Rover"<<i+1 <<" stops";
      /**  \todo {logic by cell occupied } **/
    }
    else{
      map_ptr->setRoverPositionOnMap(initPose.pos, roverID);
      rovers_ptr[i]->roverController()->setInitPose(initPose);
      for(const auto &direction : dataParser_ptr->roversDirSequences()[i]){

        if (!rovers_ptr[i]->isMoving()){ //Calc new goal and move
          navigation::Pose new_goal = rovers_ptr[i]->roverController()->calcNewPose(direction);
          navigation::Position  currPos = rovers_ptr[i]->roverController()->msrPose().pos;
          if (new_goal.pos !=currPos && !map_ptr->isCellFree(new_goal.pos)){
            std::cout<< "\nCell is occupied. Rover"<<i+1 <<" stops";
            /**  \todo {logic by cell occupied } **/
            break;
          }
          else
            rovers_ptr[i]->moveTo(new_goal);
          if (rovers_ptr[i]->onGoal())
            map_ptr->setRoverPositionOnMap(rovers_ptr[i]->roverController()->msrPose().pos, roverID);
        }
      }
    }
  }
    std::cout << "\nrunSimpleScenario finish\n";
}


void SimEnviroment::runExtendedScenario(){
  // Init map corners
  navigation::Position leftCorner(0,0);
  navigation::Position rightCorner = dataParser_ptr->readRightCornerFromFile(inPathname_,inFilename_);
  map_ptr->initCorners(leftCorner, rightCorner);


  dataParser_ptr->readAllDataFromFile(inPathname_,inFilename_);

  // Init rovers size
  rovers_ptr.resize(dataParser_ptr->roversInitPoses().size());


  //Place all rovers
  for (size_t i=0; i<rovers_ptr.size(); i++){

    rovers_ptr[i].reset(new rover::MarsRover());
    std::string roverID = "Rover"+std::to_string(i+1);
    rovers_ptr[i]->init(roverID,outPathname_, outFilenameSuffix_ );
    navigation::Pose initPose= dataParser_ptr->roversInitPoses()[i];


    if (!map_ptr->isCellFree(initPose.pos)){
      std::cout<< "\nCell is occupied. Rover"<<i+1 <<" stops";
      /**  \todo {logic by cell occupied } **/
    }
    else{
      map_ptr->setRoverPositionOnMap(initPose.pos, roverID);
      rovers_ptr[i]->roverController()->setInitPose(initPose);
      navigation::direction direction;
      do {
        direction = (dataParser_ptr->readNextDirectionFromFile(inPathname_,inFilename_,i+1));
        if (!rovers_ptr[i]->isMoving() && direction!=' '){ //Calc new goal and move
          navigation::Pose new_goal = rovers_ptr[i]->roverController()->calcNewPose(direction);
          navigation::Position  currPos = rovers_ptr[i]->roverController()->msrPose().pos;
          if (new_goal.pos !=currPos && !map_ptr->isCellFree(new_goal.pos)){
            std::cout<< "\nCell is occupied. Rover"<<i+1 <<" stops";
            /**  \todo {logic by cell occupied } **/
            break;
          }
          else
            rovers_ptr[i]->moveTo(new_goal);
          if (rovers_ptr[i]->onGoal())
            map_ptr->setRoverPositionOnMap(rovers_ptr[i]->roverController()->msrPose().pos, roverID);
        }
      } while (direction!=' ');

    }
  }
  std::cout << "\nrunExtendedScenario finish\n";
}
