#include "Grid_operators.h"
#include "Grid.h"
#include "math_functions.h"


void interplation_node_to_cell(Grid& grid)
{
  Vector_of_indexes indexes;
  indexes.fill(0);
  auto pair_iterator = grid.get_vertical_pair_nodes_iterator(indexes);
  
  const auto& sizes_of_grid_in_nodes = grid.get_sizes_in_nodes();
  size_t plane_border = sizes_of_grid_in_nodes[0] * (sizes_of_grid_in_nodes[1] - 1);  
  size_t volume_of_plane = sizes_of_grid_in_nodes[0] * sizes_of_grid_in_nodes[1];
  size_t number_of_planes = grid.get_number_of_nodes() / volume_of_plane;


  for (size_t plane_number = 0; plane_number < number_of_planes; ++plane_number)
  {
    size_t current_plane_border = plane_border + plane_number * volume_of_plane;
    for (; pair_iterator._index < current_plane_border; pair_iterator += 1)
    {
      // TODO: интерпол€ци€
    }
    
    pair_iterator += sizes_of_grid_in_nodes[0];
  
  }
  
}