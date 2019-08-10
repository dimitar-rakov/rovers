#ifndef DATA_TRANSFER_H
#define DATA_TRANSFER_H
#include <string>
#include <vector>
#include <fstream>
#include "data_types.hpp"
#include <sys/types.h>
#include <sys/stat.h>

class DataTransfer
{
public:

  /**
   * @brief Controller Default constructor   \todo {Make check for Rule of 3}
   */
   DataTransfer();

   /**
    * @brief DataTransfer Init constructor
    * @param numRovers Number of rovers
    */
   DataTransfer(size_t numRovers);

  /**
   * @brief readDataFromFile Read navigation data from file with destination adress destFileName
   * @param destFileName
   */
  void readDataFromFile(const std::string &pathname, const std::string &filename);

  /**
   * @brief writeDataToFile Write navigation data to file with destination adress destFileName
   * @param destFileName
   */
  void writeDataToFile(const std::string &pathname, const std::string &filename, navigation::Pose pose);

  /**
   * @brief upperRightCornerCoord Return upper right corner coordinates
   * @return Initial upper right corner coordinates
   */
  navigation::Pose inline upperRightCornerCoord(){return upperRightCornerCoord_; }

  /**
   * @brief roversInitPoses Return rovers initial poses
   * @return Reference to Rovers initial poses
   */
  inline const std::vector <navigation::Pose>& roversInitPoses() {return roversInitPoses_;}

  /**
   * @brief roversDirSequences Return rovers directions sequences
   * @return Reference to Rovers direction sequences
   */
  inline const std::vector <std::vector <navigation::direction>> &roversDirSequences() {return roversDirSequences_;}
private:

  /**
   * @brief checkDirectoryExist
   * @param path Directory path
   * @return  true if successed
   */

  bool checkDirectoryExist(const std::string &pathname);

  inline char separator()
  {
  #ifdef _WIN32
      return '\\';
  #else
      return '/';
  #endif
  }

  /// Map upper right corner
  navigation::Pose upperRightCornerCoord_;

  /// Rovers initial poses
  std::vector <navigation::Pose> roversInitPoses_;

  /// Rovers directions sequences
  std::vector <std::vector <navigation::direction>> roversDirSequences_;
};

#endif // DATA_TRANSFER
