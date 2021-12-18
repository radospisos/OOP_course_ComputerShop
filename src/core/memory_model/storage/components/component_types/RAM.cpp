//
// Created by Rodion Shyshkin on 11.12.2020.
//

#include <iostream>
#include "RAM.h"

RAM::RAM(const unsigned int &memory_capacity,
         const unsigned int &frequency) {
  memory_capacity_ = memory_capacity;
  frequency_ = frequency;

}

void RAM::SetMemoryCapacity(const unsigned int &memory_capacity) {
  memory_capacity_ = memory_capacity;
}

void RAM::SetFrequency(const unsigned int &frequency) {
  frequency_ = frequency;
}

unsigned int RAM::GetFrequency() const {
  return frequency_;
}

unsigned int RAM::GetMemoryCapacity() const {
  return memory_capacity_;
}

ComponentType RAM::GetComponentType() const {
  return ComponentType::RAM;
}

Characteristics RAM::GetCharacteristics() const {
  Characteristics result;
  result.memory_capacity_ = memory_capacity_;
  result.frequency_ = frequency_;
  return result;
}