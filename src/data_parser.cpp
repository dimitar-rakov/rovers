#include "data_parser.h"
#include <iostream>

namespace data_parser
{
DataParser::DataParser(){}

void DataParser::readAllDataFromFile(const std::string &pathname, const std::string &filename){
  std::ifstream file;
  if (!checkDirectoryExist(pathname))
    throw "DataTransfer: Durectory does not exist.";

  file.open (pathname+separator()+filename, std::ios::in);
  if (!file)
    throw "DataTransfer: Input file cannot be open.";

  std::string str;
  int cnt =0;
  while (std::getline(file, str))
  {
    if (cnt ==0){
      upperRightCornerCoord_.pos.x = std::stoi(str.substr(0,1));
      upperRightCornerCoord_.pos.y = std::stoi(str.substr(2,1));
    }
    else if (!(cnt%2==0)){ //every odd line
      navigation::Pose pose(std::stoi(str.substr(0,1)), std::stoi(str.substr(2,1)),str.substr(4,1).c_str()[0]);
      roversInitPoses_.push_back(pose);
    }
    else{
      std::vector <navigation::direction> directions;
      for (auto direction: str)
        directions.push_back(direction);
      roversDirSequences_.push_back(directions); // new rover
    }

    cnt++;
  }
  file.close();
}

navigation::Position DataParser::readRightCornerFromFile(const std::string &pathname, const std::string &filename){
  std::ifstream file;

  if (!checkDirectoryExist(pathname))
    throw "DataTransfer: Durectory does not exist.";

  file.open (pathname+separator()+filename, std::ios::in);
  if (!file)
    throw "DataTransfer: Input file cannot be open.";

  std::string str;
  std::getline(file, str);
   navigation::Position pos(std::stoi(str.substr(0,1)), std::stoi(str.substr(2,1)));
  return pos;

}
}
