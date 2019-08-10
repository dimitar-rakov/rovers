#ifndef DATA_PARSER_H
#define DATA_PARSER_H
#include <string>
#include <vector>
#include <fstream>
#include "data_types.hpp"
#include "helpers.h"

class DataParser
{
public:

  /**
   * @brief Controller Default constructor
   */
   DataParser();

   /**
    * @brief DataParser Copy constructor not alowed
    */
   DataParser(const DataParser& parser) =delete;

   /**
    * @brief DataParser Move constructor not alowed
    */
   DataParser(DataParser&& parser) =delete;

   /**
    * @brief DataParser Copy assignment not alowed
    */
   DataParser& operator=(const DataParser& parser)=delete;

   /**
    * @brief DataParser Move assignment not alowed
    */
   DataParser& operator=(DataParser&& parser)=delete;

  /**
   * @brief readDataFromFile Read navigation data from file with destination adress destFileName
   * @param destFileName
   */
  void readDataFromFile(const std::string &pathname, const std::string &filename);

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

  /// Map upper right corner
  navigation::Pose upperRightCornerCoord_;

  /// Rovers initial poses
  std::vector <navigation::Pose> roversInitPoses_;

  /// Rovers directions sequences
  std::vector <std::vector <navigation::direction>> roversDirSequences_;
};

#endif // DATA_PARSER
