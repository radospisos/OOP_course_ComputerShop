//
// Created by Rodion Shyshkin on 11.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_COMPONENTS_RAM_H_
#define COMPSHOP_SRC_CORE_COMPONENTS_RAM_H_

#include "memory_model/storage/components/ComponentInterface.h"

class RAM : public ComponentInterface {
 public:
  RAM() = default;
  RAM (const unsigned int& memory_capacity,
       const unsigned int& frequency);

  void SetMemoryCapacity(const unsigned int& memory_capacity);
  void SetFrequency(const unsigned int& frequency);

  unsigned int GetMemoryCapacity() const;
  unsigned int GetFrequency() const;

  ComponentType GetComponentType() const override;
  Characteristics GetCharacteristics() const override;

 private:
  unsigned int memory_capacity_;
  unsigned int frequency_;
};

#endif //COMPSHOP_SRC_CORE_COMPONENTS_RAM_H_
