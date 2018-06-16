#include "completeEllipticIntegrals.h"
#include "boundaryConditionTD.h"
#include "equationsMhd.h"

template <int dim>
BoundaryConditionTitovDemoulin<dim>::BoundaryConditionTitovDemoulin(Parameters<dim>& parameters, TitovDemoulinParameters& td_parameters) :
  BoundaryCondition<EquationsTypeMhd, dim>(parameters), td_parameters(td_parameters)
{
  this->eps = sqrt(1. - (td_parameters.d / td_parameters.R) * (td_parameters.d / td_parameters.R));
  y_1 = this->eps * td_parameters.R;
  y_2 = -this->eps * td_parameters.R;
}

template <int dim>
double BoundaryConditionTitovDemoulin<dim>::r_1_bar(double x, double y) const
{
  return sqrt(this->eps * this->eps * ((y - this->y_1) * (y - this->y_1)) + (x * x));
}

template <int dim>
double BoundaryConditionTitovDemoulin<dim>::r_2_bar(double x, double y) const
{
  return sqrt(this->eps * this->eps * ((y - this->y_2) * (y - this->y_2)) + (x * x));
}

template <int dim>
double BoundaryConditionTitovDemoulin<dim>::omega_1(double x, double y) const
{
  return 0.5 * (1. + tanh(1. - r_1_bar(x, y)));
}

template <int dim>
double BoundaryConditionTitovDemoulin<dim>::omega_2(double x, double y) const
{
  return 0.5 * (1. + tanh(1. - r_2_bar(x, y)));
}

template <int dim>
double BoundaryConditionTitovDemoulin<dim>::omega(double time) const
{
  return (this->td_parameters.omega_0 / 2.) * (1. + tanh((time - this->td_parameters.t_drive) / this->td_parameters.t_ramp));
}

template <int dim>
void BoundaryConditionTitovDemoulin<dim>::bc_vector_value(int boundary_no, const Point<dim> &point, InputVector &result, const InputVector &W_plus, double time) const
{
  // For other than z=0 boundaries, we use do-nothing
  if (point[2] > SMALL)
  {
    for (unsigned int di = 0; di < Equations<EquationsTypeMhd, dim>::n_components; ++di)
      result[di] = W_plus[di];
    return;
  }
  else
  {
    double x = point[0], y = point[1];
    result[0] = W_plus[0];
    result[1] = result[0] * (-omega(time) * this->eps * ((y - y_1) * omega_1(x, y) + (y - y_2) * omega_2(x, y)));
    result[2] = result[0] * (omega(time) * (x / this->eps) * (omega_1(x, y) + omega_2(x, y)));
    result[3] = 0.0;

    // energy density
    result[4] = W_plus[4];

    result[5] = W_plus[5];
    result[6] = W_plus[6];
    result[7] = W_plus[7];
  }
}

template class BoundaryConditionTitovDemoulin<3>;