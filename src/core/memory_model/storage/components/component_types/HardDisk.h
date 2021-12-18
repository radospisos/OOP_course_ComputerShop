//
// Created by Rodion Shyshkin on 11.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_COMPONENTS_HARDDISK_H_
#define COMPSHOP_SRC_CORE_COMPONENTS_HARDDISK_H_

#include "memory_model/storage/components/ComponentInterface.h"

class HardDisk : public ComponentInterface {
 public:
  HardDisk() = default;
  HardDisk(const unsigned int& capacity, const bool& is_ssd, const unsigned& turns_per_minute);

  unsigned int  GetCapacity() const;
  unsigned int  GetTurnsPerMinute() const;
  bool          GetSsdFlag() const;
  ComponentType GetComponentType() const override;
  Characteristics GetCharacteristics() const override;

 private:
  unsigned int  capacity_;
  unsigned int  turns_per_minute_;
  bool          is_ssd_;
};

#endif //COMPSHOP_SRC_CORE_COMPONENTS_HARDDISK_H_
