//
// Created by Rodion Shyshkin on 11.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_COMPONENTS_GRAPHICSCARD_H_
#define COMPSHOP_SRC_CORE_COMPONENTS_GRAPHICSCARD_H_

#include "memory_model/storage/components/ComponentInterface.h"

class GraphicsCard : public ComponentInterface {
 public:
  GraphicsCard() = default;
  GraphicsCard (const unsigned int& memory_capacity,
                const unsigned int& core_frequency,
                const unsigned int& memory_frequency,
                const unsigned int& display_ports_num);

  unsigned int GetMemoryCapacity () const;
  unsigned int GetCoreFrequency () const;
  unsigned int GetMemoryFrequency () const;
  unsigned int GetDisplayPortsNum () const;
  ComponentType GetComponentType() const override;
  Characteristics GetCharacteristics() const override;

 private:
  unsigned int memory_capacity_;
  unsigned int core_frequency_;
  unsigned int memory_frequency_;
  unsigned int display_ports_num_;
};

#endif //COMPSHOP_SRC_CORE_COMPONENTS_GRAPHICSCARD_H_
