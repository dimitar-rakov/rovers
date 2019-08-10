#ifndef ROVER_H
#define ROVER_H
#include "controllers/controller.h"
#include "data_parser.h"

class Rover
{
public:
  /**
   * @brief Rover Default constructor
   */
  Rover();

  /**
   * @brief Rover Copy constructor not alowed
   */
  Rover(const Rover& rover) =delete;

  /**
   * @brief Rover Move constructor not alowed
   */
  Rover(Rover&& rover) =delete;

  /**
   * @brief Rover Copy assignment not alowed
   */
  Rover& operator=(const Rover& rover)=delete;

  /**
   * @brief Rover Move assignment not alowed
   */
  Rover& operator=(Rover&& rover)=delete;


  /**
   * @brief ~Rover Virtual destructor
   */
  virtual ~Rover();

  /**
   * @brief init Set initial Parameter has to be run once before Rover start
   * @return true if successed
   */
   virtual bool init();

  /// Rover ID
  std::string roverID_;

  /// Pointer to rover controller. To  be defined in init()
  std::unique_ptr<controllers::Controller>  ptrController;

  /// Data parser.
  DataParser  dataParser_;


};

#endif // ROVER_H
