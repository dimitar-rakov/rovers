#ifndef SIM_CONTROLLER_H
#define SIM_CONTROLLER_H
#include "controllers/controller.h"

namespace controllers
{
class SimController : public Controller
{
public:
  /**
   * @brief SimController Default constructor   \todo {Make check for Rule of 5}
   */
  SimController();

  /**
   * @brief ~SimController Virtual destructor  \todo {Make check for Rule of 5}
   */
  virtual ~SimController();

  /// Overload
  void moveTo(const navigation::direction &desiredDirection) override final;

};
} // end of namespace controllers
#endif // SIM_CONTROLLER_H
