/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef ACTWOPHASEGRGRPOLY_H
#define ACTWOPHASEGRGRPOLY_H

#include "ACGrGrBase.h"

// Forward Declarations
class ACTwoPhaseGrGrPoly;

template <>
InputParameters validParams<ACTwoPhaseGrGrPoly>();

/**
 * This kernel calculates the residual and jacobian for grain growth for a
 * two-phase poly-crystal system. A single material property gamma_asymm is used for
 * the prefactor of the cross-terms between order parameters. Ratios are then
 * used to define second-phase energy and mobility relative to parent-phase.
 */
class ACTwoPhaseGrGrPoly : public ACGrGrBase
{
public:
  ACTwoPhaseGrGrPoly(const InputParameters & parameters);

protected:
  virtual Real computeDFDOP(PFFunctionType type);
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  const MaterialProperty<Real> & _gamma;
  /// index of the OP the kernel is currently acting on
  unsigned int _op_index;
  /// Number of grains/variants of the second-phase
  unsigned int _second_phase_op_num;
  /// Ratio of surface energy to GB energy, e.g., interphase energy
  Real _en_ratio;
  /// Ratio of second-phase to parent-phase GB energy
  Real _second_phase_en_ratio;
  /// Ratio of second-phase to parent-phase GB mobility
  Real _mob_ratio;
};

#endif // ACTWOPHASEGRGRPOLY_H
