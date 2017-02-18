//
// Created by jet on 18.02.17.
//

#ifndef PICALC_GRID_H
#define PICALC_GRID_H


#include <vector>
#include <cstdio>
#include "constants.h"

class Grid {

  public:
    Grid(Vector sizes, std::array<size_t, NUMBER_OF_DIMENSIONS> sizes_in_nodes);
    ~Grid();

  private:
    struct Node
    {
      Node();

      Vector _E_Field;
      Vector _B_Field;
      double _potential;
      unsigned double _dencity;
    };

  private:
    Vector _sizes;
    std::array<size_t, NUMBER_OF_DIMENSIONS> _sizes_in_nodes;
    std::vector<Node> _nodes;
    std::vector<Node> _cells;

};


#endif //PICALC_GRID_H
