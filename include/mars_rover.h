#ifndef MARS_ROVER_H
#define MARS_ROVER_H
#include "rover.h"

class MarsRover : public Rover
{
public:
  /**
   * @brief MarsRover Default constructor   \todo {Make check for Rule of 5}
   */
  MarsRover();

  /**
   * @brief ~Rover Virtual destructor  \todo {Make check for Rule of 5}
   */
  ~MarsRover();


  bool init() override final;

};

#endif // MARS_ROVER_H
