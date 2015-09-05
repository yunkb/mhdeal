#include "common.h"

const ui DG_ORDER = 0;
const ui INIT_REF_NUM = 0;
const ui COMPONENT_COUNT = 5;

const d T_FINAL = 1000.0;
const d DELTA_T = 0.001;

const bool PRINT_ALGEBRA = true;

const d GAMMA = 1.0;
const d ETA = 1.0;
// ideal gas constant
const d R = 287.14;
// specific heat capacity at constant volume
const d C_V = 717.5;
const d KAPPA = 1.0 + (R / C_V);

// Exterior pressure (dimensionless).
const double P_EXT = 2.5;
// Inlet density (dimensionless).
const double RHO_EXT = 1.0;
// Inlet x-velocity (dimensionless).
const double V1_EXT = 0.;
// Inlet y-velocity (dimensionless).
const double V2_EXT = 0.0;
// Inlet z-velocity (dimensionless).
const double V3_EXT = 0.0;
// Inlet energy.
const double E_EXT = P_EXT / (KAPPA - 1.0) + RHO_EXT * (V1_EXT*V1_EXT + V2_EXT*V2_EXT + V3_EXT*V3_EXT) / 2.0;