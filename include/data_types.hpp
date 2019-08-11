#ifndef DATA_TYPES_H
#define DATA_TYPES_H
#include "array"

namespace navigation
{

using direction = char;
using orientation = char;


/// All possible direction L
static constexpr std::array<direction,3> ALL_DIRECTION {'L','R','M'};

/// All possible orientations increasing clockwise (-90 deg)
static constexpr std::array<orientation,4> ALL_ORIENTATION {'E','S','W','N'};


struct Position
{
  Position():x(0),y(0) {}
  Position(int coord_x,int coord_y): x(coord_x),y(coord_y) {}
  int x;
  int y;
  friend bool operator ==(const Position &lhs, const Position &rhs){return lhs.x==rhs.x && lhs.y==rhs.y;}
  friend bool operator !=(const Position &lhs, const Position &rhs){return lhs.x!=rhs.x || lhs.y!=rhs.y;}
};

struct Pose
{
  Pose(): pos(0,0), rot('E'){}
  Pose(int coord_x,int coord_y, orientation orient): pos(coord_x, coord_y), rot(orient){}
  Position pos;
  orientation rot;
  friend bool operator ==(const Pose &lhs, const Pose &rhs){return lhs.pos==rhs.pos && lhs.rot==rhs.rot;}
  friend bool operator !=(const Pose &lhs, const Pose &rhs){return lhs.pos!=rhs.pos || lhs.rot!=rhs.rot;}
};

} // end of namespace controllers
#endif // DATA_TYPES_H
