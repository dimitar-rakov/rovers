#ifndef MARS_ROVER_H
#define MARS_ROVER_H
#include "rover.h"
#include "controllers/sim_controller.h"

namespace rover
{
class MarsRover : public Rover
{
public:
  /**
   * @brief MarsRover Default constructor
   */
  MarsRover();

  /**
   * @brief ~Rover Virtual destructor
   */
  ~MarsRover();

};
}
#endif // MARS_ROVER_H
