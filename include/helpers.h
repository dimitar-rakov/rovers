#ifndef HELPERS_H
#define HELPERS_H
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

inline bool checkDirectoryExist(const std::string &pathname){
  struct stat buffer;
  return (stat (pathname.c_str(), &buffer) == 0);
}


inline char separator() {
#ifdef _WIN32
    return '\\';
#else
    return '/';
#endif
}


#endif // HELPERS_H
