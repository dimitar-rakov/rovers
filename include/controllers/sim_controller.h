#ifndef SIM_CONTROLLER_H
#define SIM_CONTROLLER_H
#include "controllers/controller.h"

namespace controllers
{
class SimController : public Controller
{
public:
  /**
   * @brief SimController Default constructor
   */
  SimController();

  /**
   * @brief ~SimController Virtual destructor
   */
  virtual ~SimController();

  /**
   * @brief moveTo Move to a desiredDirection
   * @param desiredDirection Desired direction
   */
  void moveTo(const navigation::direction &desiredDirection) override final;

  /**
   * @brief moveTo Move to a desiredPose
   * @param desiredDirection Desired pose
   */
  void moveTo(const navigation::Pose &desPose);

};
} // end of namespace controllers
#endif // SIM_CONTROLLER_H
