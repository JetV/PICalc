//
// Created by jet on 23.02.17.
//

#ifndef PICALC_MATH_FUNCTIONS_H
#define PICALC_MATH_FUNCTIONS_H

#include "constants.h"

//Vector_of_indexes& operator += (Vector_of_indexes& left, const Vector_of_indexes& right);

template <class T>
std::array<T, NUMBER_OF_DIMENSIONS>& operator += (std::array<T, NUMBER_OF_DIMENSIONS>& left, const std::array<T, NUMBER_OF_DIMENSIONS>& right)
{
  for(size_t i = 0; i < NUMBER_OF_DIMENSIONS; ++i)
  {
    left[i] += right[i];
  }

  return left;
};


#endif //PICALC_MATH_FUNCTIONS_H
