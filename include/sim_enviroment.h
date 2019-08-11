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
#include "controllers/sim_controller.h"
#include "mars_rover.h"

class SimEnviroment
{
public:
  /**
   * @brief SimEnviroment Init constructor
   * @param inPathname Input data directory pathname
   * @param inFilename Input data filename
   * @param outPathname Output data directory pathname
   * @param outFilenameSuffix Output data filename suffix
   */
  SimEnviroment(std::string inPathname, std::string inFilename,
                std::string outPathname, std::string outFilenameSuffix);

  /**
   * @brief runSimpleScenario Running a simple scenario
   */
  void runSimpleScenario();

  /**
   * @brief runExtendedScenario Running an extended scenario
   */
  void runExtendedScenario();

  /// Data parser pointer
  std::unique_ptr<data_parser::DataParser> dataParser_ptr;

  /// Map pointer
  std::unique_ptr<nav_map::Map> map_ptr;

  /// Container for rovers pointers
  std::vector<std::unique_ptr<rover::Rover>> rovers_ptr;

  /// Directory input path name
  std::string inPathname_;

  /// Input file name
  std::string inFilename_;

  /// Directory output path name
  std::string outPathname_;

  /// Output file name suffix
  std::string outFilenameSuffix_;


};

#endif // SIM_ENVIROMENT_H
