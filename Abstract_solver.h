//
// Created by jet on 03.01.17.
//

#ifndef PICALC_ABSTRACT_SOLVER_H
#define PICALC_ABSTRACT_SOLVER_H


class Abstract_solver
{
  public:

    Abstract_solver();
    virtual ~Abstract_solver() = 0;

    virtual bool init();
    virtual bool iterate();
};


#endif //PICALC_ABSTRACT_SOLVER_H
