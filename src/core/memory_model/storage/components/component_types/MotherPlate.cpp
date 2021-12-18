//
// Created by Rodion Shyshkin on 11.12.2020.
//

#include "MotherPlate.h"

MotherPlate::MotherPlate(const unsigned int &max_ram,
                         const std::string &socket) {
  max_ram_ = max_ram;
  socket_ = socket;
}

unsigned int MotherPlate::GetMaxRam() const {
  return max_ram_;
}

std::string MotherPlate::GetSocket() const {
  return socket_;
}

ComponentType MotherPlate::GetComponentType() const {
  return ComponentType::MOTHERPLATE;
}

Characteristics MotherPlate::GetCharacteristics() const {
  Characteristics result;
  result.max_ram_ = max_ram_;
  result.socket_ = socket_;

  return result;
}