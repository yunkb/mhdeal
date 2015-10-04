#ifndef NUM_FLUX_H
#define NUM_FLUX_H

#include "definitions.h"

class NumFlux
{
public:
    virtual void calculate(vec U_L, vec U_R, dealii::Point<DIM> quadPoint, dealii::Point<DIM> normal, vec& result) = 0;
};

class NumFluxCentral : public NumFlux
{
public:
    void calculate(vec U_L, vec U_R, dealii::Point<DIM> quadPoint, dealii::Point<DIM> normal, vec& result);
};

class NumFluxUpwind : public NumFlux
{
public:
    void calculate(vec U_L, vec U_R, dealii::Point<DIM> quadPoint, dealii::Point<DIM> normal, vec& result);
};

#endif