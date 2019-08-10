#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <vector>
#include <fstream>
#include "data_types.hpp"
#include "helpers.h"

class Logger
{
public:
  /**
   * @brief Logger Default constructor
   */
  Logger();

  /**
   * @brief writeDataToFile Write navigation data to file with destination adress destFileName
   * @param destFileName
   */
  void writeDataToFile(const std::string &pathname, const std::string &filename, navigation::Pose pose);

};

#endif // LOGGER_H
