#ifndef ROVER_H
#define ROVER_H
#include "controllers/controller.h"
#include "logger.h"

namespace rover
{
class Rover
{
public:
  /**
   * @brief Rover Default constructor
   */
  Rover();

  /**
   * @brief Rover Copy constructor not alowed
   */
  Rover(const Rover& rover) =delete;

  /**
   * @brief Rover Move constructor not alowed
   */
  Rover(Rover&& rover) =delete;

  /**
   * @brief Rover Copy assignment not alowed
   */
  Rover& operator=(const Rover& rover)=delete;

  /**
   * @brief Rover Move assignment not alowed
   */
  Rover& operator=(Rover&& rover)=delete;


  /**
   * @brief ~Rover Virtual destructor
   */
  virtual ~Rover();

  void moveTo(const navigation::Pose &desPose);

  void moveTo(const navigation::direction &desiredDirection);

  inline bool isMoving(){return ptrController->motionStatus()==controllers::MOVING;}

  inline bool onGoal(){return ptrController->motionStatus()==controllers::ON_GOAL;}

  inline bool init(const std::string &roverID, const std::string &pathname, const std::string &outputFilenameSuffix){
    roverID_=roverID;
    pathname_= pathname;
    outputFilenameSuffix_ =outputFilenameSuffix;
  }

  const std::shared_ptr<controllers::Controller> roverController(){return ptrController;}

protected:
  /// Rover ID
  std::string roverID_;

  /// Rover name
  std::string roverName_;

  /// Directory path name
  std::string pathname_;

  /// File name
  std::string outputFilenameSuffix_;

  /// Pointer to rover controller.
  std::shared_ptr<controllers::Controller> ptrController;

  /// Output Data logger.
  logger::Logger  logger_;


};
}
#endif // ROVER_H
