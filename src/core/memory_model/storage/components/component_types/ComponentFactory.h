//
// Created by Rodion Shyshkin on 13.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_COMPONENTFACTORY_H_
#define COMPSHOP_SRC_CORE_COMPONENTFACTORY_H_

#include "memory_model/storage/components/ComponentType.h"
#include "memory_model/storage/components/ComponentInterface.h"
#include "RAM.h"
#include "Proccessor.h"
#include "MotherPlate.h"
#include "HardDisk.h"
#include "GraphicsCard.h"
#include <map>

namespace component_factory {
  static std::unique_ptr<RAM> CreateRAM(const unsigned int& memory_capacity,
                                        const unsigned int& frequency) {
    return std::make_unique<RAM>(memory_capacity, frequency);
  }

  static std::unique_ptr<Proccessor> CreateProcessor(const double& minimal_frequency,
                                                     const double& maximal_frequency,
                                                     const unsigned int& cores_number,
                                                     const bool& has_cooler) {
    return std::make_unique<Proccessor>(minimal_frequency, maximal_frequency,
                                        cores_number, has_cooler);
  }

  static std::unique_ptr<MotherPlate> CreateMotherPlate(const unsigned int& max_ram,
                                                        const std::string& socket) {
    return std::make_unique<MotherPlate>(max_ram, socket);
  }

  static std::unique_ptr<HardDisk> CreateHardDisk(const unsigned int& capacity,
                                                  const unsigned int& turns_per_minute,
                                                  const bool& is_ssd) {
    return std::make_unique<HardDisk>(capacity, turns_per_minute, is_ssd);
  }

  static std::unique_ptr<GraphicsCard> CreateGraphicsCard(const unsigned int& memory_capacity,
                                                          const unsigned int& core_frequency,
                                                          const unsigned int& memory_frequency,
                                                          const unsigned int& display_ports_num) {
    return std::make_unique<GraphicsCard>(memory_capacity, core_frequency,
                                          memory_frequency, display_ports_num);
  }
}

#endif //COMPSHOP_SRC_CORE_COMPONENTFACTORY_H_
