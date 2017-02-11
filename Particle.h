//
// Created by jet on 11.02.17.
//

#ifndef PICALC_PARTICLE_H
#define PICALC_PARTICLE_H

#include "constants.h"
#include "Particle_types_container.hpp"

class Particle
{
  public:
    Particle();
    ~Particle();

  private:
    Particle_types _particle_type;

    Vector _position;
    Vector _velocity;
};


#endif //PICALC_PARTICLE_H
