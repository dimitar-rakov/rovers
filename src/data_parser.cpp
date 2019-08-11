#include "data_parser.h"
#include <iostream>

namespace data_parser
{
DataParser::DataParser(){}

void DataParser::readAllDataFromFile(const std::string &pathname, const std::string &filename){
  readRightCornerFromFile(pathname, filename);
  readInitPosesFromFile(pathname,filename);
  readDirectionsFromFile(pathname,filename);
}

navigation::Position DataParser::readRightCornerFromFile(const std::string &pathname, const std::string &filename){
  std::ifstream file;

  file.open (pathname+separator()+filename, std::ios::in);
  if (!file){
    /**  \todo {Discuse wit TTTech } **/
    throw "DataTransfer: Input file cannot be open.";
  }

  std::string str;
  std::getline(file, str);
  navigation::Position pos(std::stoi(str.substr(0,1)), std::stoi(str.substr(2,1)));
  file.close();;
  return pos;

}

void DataParser::readInitPosesFromFile(const std::string &pathname,const std::string &filename){
  std::ifstream file;
  file.open (pathname+separator()+filename, std::ios::in);
  if (!file){
    /**  \todo {Discuse wit TTTech } **/
    throw "DataTransfer: Input file cannot be open.";
  }

  std::string str;
  int cnt =0;
  while (std::getline(file, str))
  {
    if (!(cnt ==0) && !(cnt%2==0)){ //every odd line
      navigation::Pose pose(std::stoi(str.substr(0,1)), std::stoi(str.substr(2,1)),str.substr(4,1).c_str()[0]);
      roversInitPoses_.push_back(pose);
    }
    cnt++;
  }
  currRoverDirSequenceIndex_.resize(roversInitPoses_.size(),-1);
  file.close();
}

void DataParser::readDirectionsFromFile(const std::string &pathname, const std::string &filename){
  std::ifstream file;
  file.open (pathname+separator()+filename, std::ios::in);
  if (!file){
    /**  \todo {Discuse wit TTTech } **/
    throw "DataTransfer: Input file cannot be open.";
  }

  std::string str;
  int cnt =0;
  while (std::getline(file, str))
  {
    if (!(cnt ==0) && (cnt%2==0)){ //every even line
        std::vector <navigation::direction> directions;
        for (auto direction: str)
          directions.push_back(direction);
        roversDirSequences_.push_back(directions); // new rover
      }

      cnt++;
    }
    file.close();
  }

navigation::direction DataParser::readNextDirectionFromFile(const std::string &pathname,
                                                            const std::string &filename,
                                                            size_t roverNum){
  std::ifstream file;
  file.open (pathname+separator()+filename, std::ios::in);
  if (!file){
    /**  \todo {Discuse wit TTTech } **/
    throw "DataTransfer: Input file cannot be open.";
  }
  std::string str;
  int cnt =0;
  while (std::getline(file, str))
  {
    if (!(cnt ==0) && (cnt%(2*roverNum)==0)){ //every rover direction line
        if (currRoverDirSequenceIndex_[roverNum-1]< static_cast<int>(str.size()-1)){
          currRoverDirSequenceIndex_[roverNum-1]++;
          file.close();
          return str[currRoverDirSequenceIndex_[roverNum-1]];
        }
        else
          return ' ';
      }
      cnt++;
    }
    file.close();
}

}
