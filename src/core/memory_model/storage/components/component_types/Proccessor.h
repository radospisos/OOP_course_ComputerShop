//
// Created by Rodion Shyshkin on 11.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_PROCESSOR_H_
#define COMPSHOP_SRC_CORE_PROCESSOR_H_

#include "memory_model/storage/components/ComponentInterface.h"

class Proccessor : public ComponentInterface {
 public:
  Proccessor() = default;
  Proccessor(const double& min_frequency,
             const double& max_frequency,
             const unsigned int& cores_num,
             const bool& has_cooler);

  ComponentType GetComponentType() const override;
  Characteristics GetCharacteristics() const override;

 private:
  double GetMinimalFrequency() const;
  double GetMaximalFrequency() const;
  unsigned int GetCoresNumber() const;
  bool GetCoolerFlag() const;

 private:
  double       minimal_frequency_;
  double       maximal_frequency_;
  unsigned int cores_number_;
  bool         has_cooler_;
};

#endif //COMPSHOP_SRC_CORE_PROCESSOR_H_
