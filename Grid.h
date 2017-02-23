//
// Created by jet on 18.02.17.
//

#ifndef PICALC_GRID_H
#define PICALC_GRID_H


#include <vector>
#include <cstdio>
#include "math_functions.h"

class Grid {

  public:
    Grid(Vector sizes, Vector_of_indexes sizes_in_nodes);
    ~Grid();

    Node& get_node(Vector_of_indexes /*индекс элемента по оси*/indexes);
    Node& get_cell(Vector_of_indexes indexes);

    // создание и возвращение итератора вертикальных пар узлов
    Vertical_pair_nodes_iterator get_vertical_pair_nodes_iterator(Vector_of_indexes indexes);


  private:
    struct Node
    {
      Node();

      Vector _E_Field;
      Vector _B_Field;
      double _potential;
      unsigned double _dencity;
    };

    struct Vertical_pair_nodes_iterator
    {
      // итератор ребра между вертикальной парой узлов
      Vertical_pair_nodes_iterator(size_t index, Node* bottom_node, Node* top_node);

      // получение ссылки на нижний в вертикальной паре узел
      Node& get_bottom_node();
      // получение ссылки на верхний в вертикальной паре узел
      Node& get_top_node();

      // смещение итератора вертикальных пар на offset
      Vertical_pair_nodes_iterator& move(const std::array<int, NUMBER_OF_DIMENSIONS>& offset);
      void positive_move(Vector_of_indexes offset);

      // Перегруженный оператор смещения по последней координате пространства или смещение по линейному массиву узлов
      Vertical_pair_nodes_iterator& operator += (Vertical_pair_nodes_iterator& iterator, int offset);

      Node* _bottom_node;
      Node* _top_node;

      // Номер элемента вектора (узлов)
      size_t _index;
    };

  private:

    // вектор размеров расчетной области
    Vector _sizes;
    // вектор размеров в узлах (количество узлов на ось)
    std::array<size_t, NUMBER_OF_DIMENSIONS> _sizes_in_nodes;
    // вектор размеров в ячейках
    std::array<size_t, NUMBER_OF_DIMENSIONS> _sizes_in_cells;
    // вектор узлов
    std::vector<Node> _nodes;
    // вектор ячеек
    std::vector<Node> _cells;

};


#endif //PICALC_GRID_H
