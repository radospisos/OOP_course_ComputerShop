//
// Created by Rodion Shyshkin on 11.12.2020.
//

#include "HardDisk.h"

HardDisk::HardDisk(const unsigned int &capacity,
                   const bool &is_ssd,
                   const unsigned int &turns_per_minute) {
  capacity_ = capacity;
  is_ssd_ = is_ssd;
  turns_per_minute_ = turns_per_minute;
}

unsigned int HardDisk::GetCapacity() const {
  return capacity_;
}

bool HardDisk::GetSsdFlag() const {
  return is_ssd_;
}

unsigned int HardDisk::GetTurnsPerMinute() const {
  return turns_per_minute_;
}

ComponentType HardDisk::GetComponentType() const {
  return ComponentType::HARDDISK;
}

Characteristics HardDisk::GetCharacteristics() const {
  Characteristics result;
  result.capacity_ = capacity_;
  result.turns_per_minute_ = turns_per_minute_;
  result.is_ssd_ = is_ssd_;

  return result;
}