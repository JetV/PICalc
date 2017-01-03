//
// Created by jet on 03.01.17.
//

#ifndef PICALC_PIC_SOLVER_H
#define PICALC_PIC_SOLVER_H


#include <vector>
#include "Abstract_solver.h"

class PIC_solver : Abstract_solver
{
  public:

    PIC_solver();
    ~PIC_solver();

    bool init();
    bool iterate();

  private:

    /* 4*PI for normalization */
    static double CGS_normalizer;


    // light speed
    double _light_speed;

    //plasma larmor frequency s^(-10)
    uint64_t _larmor_frequency;

    // coefficient factor for time step
    double _time_step_coefficient;

    // time step = time_step_coefficient * larmor_frequency
    long double _time_step;

    // decentering parameter
    // TODO: узнать что за параметр, используется в addscale
    double _decentering_parameter;

    // Smoothing value
    double _smooth_factor;

    // space_step = light_speed * decentering_parameter * time_step
    long double _space_step;

    /*! number of particles species */
    // TODO: создать класс-коллекцию частиц, в нем определить структуру для типа частицы
    //int ns;

    // GEM challenge parameters
    //TODO: Параметр delta - узнать его физический смысл, и возможно, заменить на шаг ларморова витка?
    //double B0x, B0y, B0z, delta;
    std::vector<double> _initial_B_value;


    // KEEP IN MEMORY GUARD CELLS ARE INCLUDED
    // numbers of cells for each direction
    std::vector<size_t> _numbers_of_cells;

    // local grid boundaries coordinate
    std::vector< std::pair <double> > _locale_grid_boundaries;
    // grid spacing get from boundaries values

    // Space sizes
    // TODO: verify type
    std::vector<size_t> _box_sizes;

    /** source center - X direction   */
    std::vector<double > _center_coodinates;

    /** Characteristic length */
    double _characteristic_length;

};


#endif //PICALC_PIC_SOLVER_H
