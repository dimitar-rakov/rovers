#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <vector>
#include <fstream>
#include "data_types.hpp"
#include "helpers.h"

namespace logger
{
class Logger
{
public:
  /**
   * @brief Logger Default constructor
   */
  Logger();

  /**
   * @brief writeDataToFile Write navigation data to a file with a given filename
   * @param pathname
   * @param filename
   * @param pose
   */
  void writeDataToFile(const std::string &pathname, const std::string &filename, navigation::Pose pose);
};
}
#endif // LOGGER_H
