#ifndef __COMMON__
#define __COMMON__

#include <iostream>
#include <vector>

using String = std::string;

template <typename Type>
using List = std::vector<Type>;

#define log_e std::cerr
#define log_i std::cout

#endif