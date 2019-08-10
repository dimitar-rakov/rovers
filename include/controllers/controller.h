#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "data_types.hpp"
#include "memory"


namespace controllers
{

/// Controller status
enum cntr_status {READY = 1, RUNNING = 2, ERROR = 8};

/// Controller type
enum cntr_type {DEFAULT = 11};

/// Motion status
enum motion_status {MOVING = 10, ON_GOAL = 20};

/**
 * @brief The Controller base class
 */
class Controller{
public:

  /**
   * @brief Controller Default constructor   \todo {Make check for Rule of 5}
   */
  Controller();

  /**
   * @brief ~Controller Virtual destructor  \todo {Make check for Rule of 5}
   */
  virtual ~Controller();

  /**
   * @brief create Factory create method
   * @param cntrType Controller type
   * @return
   */
  static std::unique_ptr<Controller> create(cntr_type cntrType);


  /**
   * @brief init Set initial Parameter has to be run once before controller start
   * @param initPose Initial pose
   * @param lowerLeftCorner Lower left corner of the map
   * @param upperRightCorner Upper right corner of the map
   * @return true if successed
   */
  inline bool init(navigation::Pose initPose,
                   navigation::Position lowerLeftCorner,
                   navigation::Position upperRightCorner)
  {
    msrPose_ = initPose;
    lowerLeftCorner_ = lowerLeftCorner;
    upperRightCorner_ = upperRightCorner;
  }

  /**
   * @brief msrPose Return current pose
   * @return Current Pose
   */
  inline navigation::Pose msrPose(){return msrPose_;}

  /**
   * @brief cntrStatus Return controller status
   * @return Controller status
   */
  inline cntr_status cntrStatus(){return controllerStatus_;}

  /**
   * @brief motionStatus Return motion status
   * @return Motion status
   */
  inline motion_status motionStatus(){return motionStatus_;}

  /**
   * @brief moveTo Move to a desiredDirection
   * @param desiredDirection Desired direction
   */
  virtual void moveTo(const navigation::direction &desiredDirection);

 protected:
  /// Controller status
  cntr_status controllerStatus_;

  /// Movement status
  motion_status motionStatus_;

  /// Upper right corner of the grid map
  navigation::Position lowerLeftCorner_;

  /// Upper right corner of the grid map
  navigation::Position upperRightCorner_;

  /// Measured pose
  navigation::Pose msrPose_;

  /**
   * Check if the desPose is in the map \todo {bind the variable in doxygen}
   * @return true if in range
   */
  inline bool checkLimits(const navigation::Pose &desPose){
    return desPose.pos.x>=lowerLeftCorner_.x && desPose.pos.x<=upperRightCorner_.x &&
           desPose.pos.y>=lowerLeftCorner_.y && desPose.pos.y<=upperRightCorner_.y;
}


  /**
   * @brief calcNewPose Calculate a new pose \todo {eventualy public}
   * @param desDirection Desired direction
   * @return New pose
   */
  navigation::Pose calcNewPose(const navigation::direction &desDirection);


};
} // end of namespace controllers
#endif // CONTROLLER_H

