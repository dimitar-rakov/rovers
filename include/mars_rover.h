#ifndef MARS_ROVER_H
#define MARS_ROVER_H
#include "rover.h"

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


  bool init() override final;

};

#endif // MARS_ROVER_H
