//
// Created by Rodion Shyshkin on 11.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_COMPONENTINTERFACE_H_
#define COMPSHOP_SRC_CORE_COMPONENTINTERFACE_H_

#include "ComponentType.h"
#include "Characteristics.h"

class ComponentInterface {
 public:
  virtual ~ComponentInterface() = default;

  virtual ComponentType GetComponentType() const = 0;
  virtual Characteristics GetCharacteristics() const = 0;
};

#endif //COMPSHOP_SRC_CORE_COMPONENTINTERFACE_H_
