//
// Created by jet on 11.02.17.
//

#ifndef PICALC_CONSTANTS_H
#define PICALC_CONSTANTS_H

// TODO: change to precompiled header
#include <array>

#define LIGHT_SPEED 1

#define ELECTRON_MASS 1
#define ELECTRON_CHARGE 1

#define NUMBER_OF_DIMENSIONS 3 // TODO: Избавиться от константы, задавать в последствии в динамике, через методы vector

typedef std::array<double, NUMBER_OF_DIMENSIONS> Vector;

#endif //PICALC_CONSTANTS_H
