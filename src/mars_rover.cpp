#include "mars_rover.h"

namespace rover
{
MarsRover::MarsRover() {
  ptrController.reset(new controllers::SimController());
}

MarsRover::~MarsRover(){}



}
