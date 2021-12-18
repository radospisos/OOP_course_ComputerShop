//
// Created by Rodion Shyshkin on 11.12.2020.
//

#include "GraphicsCard.h"

GraphicsCard::GraphicsCard(const unsigned int &memory_capacity,
                           const unsigned int &core_frequency,
                           const unsigned int &memory_frequency,
                           const unsigned int &display_ports_num) {
  memory_capacity_ = memory_capacity;
  core_frequency_ = core_frequency;
  memory_frequency_ = memory_frequency;
  display_ports_num_ = display_ports_num;
}
unsigned int GraphicsCard::GetDisplayPortsNum() const {
  return display_ports_num_;
}
unsigned int GraphicsCard::GetCoreFrequency() const {
  return core_frequency_;
}

unsigned int GraphicsCard::GetMemoryFrequency() const {
  return memory_frequency_;
}

unsigned int GraphicsCard::GetMemoryCapacity() const {
  return memory_capacity_;
}

ComponentType GraphicsCard::GetComponentType() const {
  return ComponentType::GRAPHICSCARD;
}

Characteristics GraphicsCard::GetCharacteristics() const {
  Characteristics result;
  result.memory_capacity_ = memory_capacity_;
  result.core_frequency_ = core_frequency_;
  result.memory_frequency_ = memory_frequency_;
  result.display_ports_num_ = display_ports_num_;

  return result;
}