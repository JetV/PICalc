//
// Created by jet on 11.02.17.
//

#ifndef PICALC_PARTICLE_TYPE_H
#define PICALC_PARTICLE_TYPE_H


#include <cstddef>

class Particle_type
{
  public:
    Particle_type();
    ~Particle_type();



  private:
    int _charge;
    size_t _mass;
};


#endif //PICALC_PARTICLE_TYPE_H
