//
// Created by Rodion Shyshkin on 11.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_COMPONENTS_MOTHERPLATE_H_
#define COMPSHOP_SRC_CORE_COMPONENTS_MOTHERPLATE_H_

#include "memory_model/storage/components/ComponentInterface.h"
#include <string>

class MotherPlate : public ComponentInterface {
 public:
  MotherPlate() = default;
  MotherPlate (const unsigned int& max_ram,
               const std::string& socket);

  unsigned int GetMaxRam () const;
  std::string GetSocket () const;
  ComponentType GetComponentType() const override;
  Characteristics GetCharacteristics() const override;

 private:
  unsigned int max_ram_;
  std::string socket_;
};

#endif //COMPSHOP_SRC_CORE_COMPONENTS_MOTHERPLATE_H_
