//
// Created by jet on 18.02.17.
//

#include "Grid.h"

Grid::Grid(Vector sizes, std::array<size_t, NUMBER_OF_DIMENSIONS> sizes_in_nodes) :
  _sizes(sizes),
  _sizes_in_nodes(sizes_in_nodes)
{
  size_t nodes_count = 1;
  size_t cells_count = 0;

  for(auto& nodes_by_axis_count : sizes_in_nodes)
  {
    if(nodes_by_axis_count == 0)
    {
      nodes_by_axis_count = 1;
    }

    nodes_count *= nodes_by_axis_count;

    if(nodes_by_axis_count != 1)
    {
      cells_count *= nodes_by_axis_count - 1;
    }
  }

  _nodes = std::vector<Node>(nodes_count);
  _cells = std::vector<Node>(cells_count);
}

Grid::Node::Node() :
  _potential(0.0),
  _dencity(0.0)
{
  _E_Field.fill(0.0);
  _B_Field.fill(0.0);
}
