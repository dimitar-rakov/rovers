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
   * @brief Controller Default constructor
   */
  Controller();

  /**
   * @brief Controller Copy constructor not alowed
   */
  Controller(const Controller& controller) =delete;

  /**
   * @brief Controller Move constructor not alowed
   */
  Controller(Controller&& controller) =delete;

  /**
   * @brief Controller Copy assignment not alowed
   */
  Controller& operator=(const Controller& controller)=delete;

  /**
   * @brief Controller Move assignment not alowed
   */
  Controller& operator=(Controller&& controller)=delete;

  /**
   * @brief ~Controller Virtual destructor
   */
  virtual ~Controller();

  /**
   * @brief init Set initial Parameter has to be run once before controller start
   * @param initPose Initial pose
   * @return true if successed
   */
  inline bool setInitPose(navigation::Pose initPose){msrPose_ = initPose;}

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
   * @brief calcNewPose Calculate a new pose
   * @param desDirection Desired direction
   * @return New pose
   */
  navigation::Pose calcNewPose(const navigation::direction &desDirection);

  /**
   * @brief moveTo Move to a desiredDirection
   * @param desiredDirection Desired direction
   */
  virtual void moveTo(const navigation::direction &desiredDirection);

  /**
   * @brief moveTo Move to a desiredPose
   * @param desiredDirection Desired pose
   */
  virtual void moveTo(const navigation::Pose &desPose);


 protected:
  /// Controller status
  cntr_status controllerStatus_;

  /// Movement status
  motion_status motionStatus_;

  /// Measured pose
  navigation::Pose msrPose_;

};
} // end of namespace controllers
#endif // CONTROLLER_H

