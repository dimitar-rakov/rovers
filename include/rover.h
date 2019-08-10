#ifndef ROVER_H
#define ROVER_H
#include "controllers/controller.h"
#include "data_transfer.h"

class Rover
{
public:
  /**
   * @brief Rover Default constructor   \todo {Make check for Rule of 5}
   */
  Rover();

  /**
   * @brief ~Rover Virtual destructor  \todo {Make check for Rule of 5}
   */
  virtual ~Rover();

  /**
   * @brief init Set initial Parameter has to be run once before Rover start
   * @return true if successed
   */
   virtual bool init();

  /// Pointer to rover controller. To  be defined in init()
  std::unique_ptr<controllers::Controller>  ptrController;

  /// Pointer to rover data transfer. To  be defined in init()
  std::unique_ptr<DataTransfer>  ptrDataTransfer;
};

#endif // ROVER_H
