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

  // Цикл по размерам во всех направлениях для пространственного объема
  for(size_t i = 0; i < NUMBER_OF_DIMENSIONS; ++i)
  {
    // Проверка на некорректность значения ячеек
    if(sizes_in_nodes[i] == 0)
    {
      sizes_in_nodes[i] = 1;
    }

    _sizes_in_cells[i] = 1;

    nodes_count *= sizes_in_nodes[i];
    // Домножаем общее количество ячеек, домножаем на "число узлов-1", либо ничего не делаем
    if(sizes_in_nodes[i] != 1)
    {
      _sizes_in_cells[i] = sizes_in_nodes[i] - 1;
      cells_count *= _sizes_in_cells[i];
    }
  }

  // Линейный массив узлов
  _nodes = std::vector<Node>(nodes_count);
  _cells = std::vector<Node>(cells_count);
}

size_t Grid::get_number_of_nodes()
{
  return _nodes.size();
}

const std::array<size_t, NUMBER_OF_DIMENSIONS>& Grid::get_sizes_in_nodes()
{
  return _sizes_in_nodes;
}

Grid::Node& Grid::get_node(Vector_of_indexes indexes)
{
  // Напоминание: массив всех узлов линеен
  size_t node_id = 0;
  // Проход по всем измерениям от последнего
  for(size_t i = NUMBER_OF_DIMENSIONS -1 ; i >= 0; --i)
  {
    // Получаем число узлов в слое
    // Индекс по данной оси
    size_t nodes_in_layer_count = indexes[i];
    // Объём слоя под этим индексом (измеренный в узлах)
    for(size_t j = i; j < NUMBER_OF_DIMENSIONS; ++j)
    {
      nodes_in_layer_count *= _sizes_in_nodes[j];
    }
    // Добавляем к общему индексу объем слоя по данной оси
    node_id += nodes_in_layer_count;
  }
  return _nodes[node_id];
}

Grid::Node& Grid::get_cell(Vector_of_indexes indexes)
{
  // Напоминание: массив всех ячеек линеен
  size_t cell_id = 0;
  // Проход по всем измерениям от последнего
  for(size_t i = NUMBER_OF_DIMENSIONS -1 ; i >= 0; --i)
  {
    // Получаем число ячеек в слое
    // Индекс по данной оси
    size_t cells_in_layer_count = indexes[i];
    // Объём слоя под этим индексом (измеренный в ячейках)
    for(size_t j = i; j < NUMBER_OF_DIMENSIONS; ++j)
    {
      cells_in_layer_count *= _sizes_in_cells[j];
    }
    // Добавляем к общему индексу объем слоя по данной оси
    cell_id += cells_in_layer_count;
  }
  return _cells[cell_id];
}

Grid::Node::Node() :
  _potential(0.0),
  _dencity(0.0)
{
  _E_Field.fill(0.0);
  _B_Field.fill(0.0);
}

// Check template! TODO: complete
Grid::Vertical_pair_nodes_iterator& Grid::Vertical_pair_nodes_iterator::move(const std::array<int, NUMBER_OF_DIMENSIONS>& offset)
{
  // _indexes += offset;

}

Grid::Vertical_pair_nodes_iterator& Grid::Vertical_pair_nodes_iterator::operator += (int offset)
{
  _index += offset;
  _bottom_node += offset;
  _top_node += offset;
}

Grid::Node& Grid::Vertical_pair_nodes_iterator::get_bottom_node()
{
  return *_bottom_node;
}

Grid::Node& Grid::Vertical_pair_nodes_iterator::get_top_node()
{
  return *_top_node;
}

Grid::Vertical_pair_nodes_iterator::Vertical_pair_nodes_iterator(size_t index, Node* bottom_node, Node* top_node) :
  _index(index),
  _bottom_node(bottom_node),
  _top_node(top_node)
{
}

Grid::Vertical_pair_nodes_iterator Grid::get_vertical_pair_nodes_iterator(Vector_of_indexes indexes)
{
  // Напоминание: массив всех узлов линеен
  size_t node_id = 0;
  // Проход по всем измерениям от последнего
  for(size_t i = NUMBER_OF_DIMENSIONS -1 ; i >= 0; --i)
  {
    // Получаем число узлов в слое
    // Индекс по данной оси
    size_t nodes_in_layer_count = indexes[i];
    // Объём слоя под этим индексом (измеренный в узлах)
    for(size_t j = i; j < NUMBER_OF_DIMENSIONS; ++j)
    {
      nodes_in_layer_count *= _sizes_in_nodes[j];
    }
    // Добавляем к общему индексу объем слоя по данной оси
    node_id += nodes_in_layer_count;
  }

  // принимает текущий узел (id), указатель на текущий узел, указатель на узел выше в вертикальной паре - это не работает для одномерного случая TODO:
  return Vertical_pair_nodes_iterator(node_id, &_nodes[node_id], &_nodes[node_id + _sizes_in_nodes[NUMBER_OF_DIMENSIONS-2]]);
}

Grid::Vertical_pair_nodes_iterator Grid::get_vertical_pair_nodes_iterator(Vector_of_indexes indexes)
{
  // Напоминание: массив всех узлов линеен

  size_t node_id = 0;
  // Проход по всем измерениям от последнего
  for (size_t i = NUMBER_OF_DIMENSIONS - 1; i >= 0; --i)
  {
    // Получаем число узлов в слое
    // Индекс по данной оси
    size_t nodes_in_layer_count = indexes[i];
    // Объём слоя под этим индексом (измеренный в узлах)
    for (size_t j = i; j < NUMBER_OF_DIMENSIONS; ++j)
    {
      nodes_in_layer_count *= _sizes_in_nodes[j];
    }
    // Добавляем к общему индексу объем слоя по данной оси
    node_id += nodes_in_layer_count;
  }

  // принимает текущий узел (id), указатель на текущий узел, указатель на узел выше в вертикальной паре - это не работает для одномерного случая TODO:
  return Vertical_pair_nodes_iterator(node_id, &_nodes[node_id], &_nodes[node_id + _sizes_in_nodes[NUMBER_OF_DIMENSIONS - 2]]);
}




