#ifndef SIM_ENVIROMENT_H
#define SIM_ENVIROMENT_H

#include <string>
#include <vector>
#include "data_types.hpp"
#include "helpers.h"
#include "memory"
#include "data_parser.h"
#include "map.h"
#include "rover.h"


class SimEnviroment
{
public:
  SimEnviroment();
  bool init();
  void run();
  bool running();

  std::unique_ptr<data_parser::DataParser> dataParser_;
  std::unique_ptr<nav_map::Map> map_;
  std::vector<std::unique_ptr<rover::Rover>> rovers_;

};

#endif // SIM_ENVIROMENT_H
