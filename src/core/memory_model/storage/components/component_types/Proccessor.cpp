//
// Created by Rodion Shyshkin on 11.12.2020.
//

#include "Proccessor.h"

Proccessor::Proccessor(const double &min_frequency,
                       const double &max_frequency,
                       const unsigned int &cores_num,
                       const bool &has_cooler) {
  minimal_frequency_ = min_frequency;
  maximal_frequency_ = max_frequency;
  cores_number_ = cores_num;
  has_cooler_ = has_cooler;
}

double Proccessor::GetMinimalFrequency() const {
  return minimal_frequency_;
}

double Proccessor::GetMaximalFrequency() const {
  return maximal_frequency_;
}

unsigned int Proccessor::GetCoresNumber() const {
  return cores_number_;
}

bool Proccessor::GetCoolerFlag() const {
  return has_cooler_;
}

ComponentType Proccessor::GetComponentType() const {
  return ComponentType::PROCCESSOR;
}

Characteristics Proccessor::GetCharacteristics() const {
  Characteristics result;
  result.minimal_frequency_ = minimal_frequency_;
  result.maximal_frequency_ = maximal_frequency_;
  result.cores_number_ = cores_number_;
  result.has_cooler_ = has_cooler_;

  return result;
}