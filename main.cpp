#include <iostream>

#include "sim_enviroment.h"
using namespace std;

int main(int argc, char **argv){

  std::string path{argv[1]};
  std::string input_filename{argv[2]};
  std::string sufix_filename{argv[3]};

  //  std::string path = "/home/dimitar";
  //  std::string input_filename = "nav_input_data.txt";;
  //  std::string sufix_filename = "_nav_output_data.txt";

  if (!checkDirectoryExist(path))  {
    /**  \todo {Discuse wit TTTech } **/
    throw "DataTransfer: Directory does not exist.";
  }

  std::ifstream file;
  file.open (path+separator()+input_filename, std::ios::in);
  if (!file){
    /**  \todo {Discuse wit TTTech } **/
    throw "DataTransfer: Input file cannot be open.";
  }
  file.close();

  auto sim_ptr = std::make_unique<SimEnviroment>(SimEnviroment(path,input_filename, path, sufix_filename));
  sim_ptr->runSimpleScenario();

}

