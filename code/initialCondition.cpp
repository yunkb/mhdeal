#include "initialCondition.h"
#include "equationsEuler.h"
#include "equationsMhd.h"

template <EquationsType equationsType, int dim>
InitialCondition<equationsType, dim>::InitialCondition() : Function<dim>(Equations<equationsType, dim>::n_components)
{
};

template<>
double InitialCondition<EquationsTypeEuler, 2>::value(const Point<2> &p, const unsigned int component) const
{
  double x = p(0);
  double y = p(1);
  switch (component) {
  case 0:
    return 0.;
    break;
  case 1:
    return 0.;
    break;
  case 2:
    return 10. * (x < -0.7)*(y > 0.3)*(y < 0.45) + (1 - (x < -0.7)*(y > 0.3)*(y < 0.45));
    break;
  case 3:
    return 2.5 * (1.5 - y);
    break;
  }
};

template<>
double InitialCondition<EquationsTypeEuler, 3>::value(const Point<3> &p, const unsigned int component) const
{
  double x = p(0);
  double y = p(1);
  switch (component) {
  case 0:
    return 0.;
    break;
  case 1:
    return 0.;
    break;
  case 2:
    return 0.;
    break;
  case 3:
    return 10. * (x < -0.7)*(y > 0.3)*(y < 0.45) + (1 - (x < -0.7)*(y > 0.3)*(y < 0.45));
    break;
  case 4:
    return 2.5 * (1.5 - y);
    break;
  }
};

template<>
double InitialCondition<EquationsTypeMhd, 2>::value(const Point<2> &p, const unsigned int component) const
{
  double x = p(0);
  double y = p(1);
  switch (component) {
  case 0:
    return 0.;
    break;
  case 1:
    return 0.;
    break;
  case 2:
    return 10. * (x < -0.7)*(y > 0.3)*(y < 0.45) + (1 - (x < -0.7)*(y > 0.3)*(y < 0.45));
    break;
  case 3:
    return 2.5 * (1.5 - y);
    break;
  }
};

template<>
double InitialCondition<EquationsTypeMhd, 3>::value(const Point<3> &p, const unsigned int component) const
{
  double x = p(0);
  double y = p(1);
  switch (component) {
  case 0:
    return 0.;
    break;
  case 1:
    return 0.;
    break;
  case 2:
    return 0.;
    break;
  case 3:
    return 0.;
    break;
  case 4:
    return 0.;
    break;
  case 5:
    return 0.;
    break;
  case 6:
    return 10. * (x < -0.7)*(y > 0.3)*(y < 0.45) + (1 - (x < -0.7)*(y > 0.3)*(y < 0.45));
    break;
  case 7:
    return 2.5 * (1.5 - y);
    break;
  }
};

template class InitialCondition<EquationsTypeEuler, 2>;
template class InitialCondition<EquationsTypeEuler, 3>;
template class InitialCondition<EquationsTypeMhd, 2>;
template class InitialCondition<EquationsTypeMhd, 3>;