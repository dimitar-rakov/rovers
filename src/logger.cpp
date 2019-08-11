#include "logger.h"
namespace logger
{
Logger::Logger(){}

void Logger::writeDataToFile(const std::string &pathname, const std::string &filename, navigation::Pose pose){
  std::fstream file;

  file.open (pathname+separator()+filename, std::ios::app );
  if (!file){
    /**  \todo {Discuse wit TTTech } **/
    throw "DataTransfer: Output file cannot be open.";
  }
  file << pose.pos.x<< " " <<pose.pos.y<< " " <<pose.rot<<"\n";
  file.close();
}

}
