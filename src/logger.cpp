#include "logger.h"

Logger::Logger(){}

void Logger::writeDataToFile(const std::string &pathname, const std::string &filename, navigation::Pose pose){
  std::ofstream file;

  if (!checkDirectoryExist(pathname))
    throw "DataTransfer: Durectory does not exist.";

  file.open (pathname+separator()+filename, std::ios::app );
  if (!file)
    throw "DataTransfer: Output file cannot be open.";
  file << pose.pos.x<< " " <<pose.pos.y<< " " <<pose.rot<<"\n";
  file.close();
}
