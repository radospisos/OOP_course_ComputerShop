//
// Created by Rodion Shyshkin on 13.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_MODELAPICONVERTER_H_
#define COMPSHOP_SRC_CORE_MODELAPICONVERTER_H_

#include <memory_model/storage/components/ComponentInterface.h>
#include <memory_model/storage/components/component_types/ComponentFactory.h>
#include "api/dto/ComponentDTO.h"
#include "api/dto/WorkerDTO.h"
#include <boost/uuid/uuid_io.hpp>

namespace model_api_utils {
  static std::string ConvertUUIDToString(const boost::uuids::uuid& id) {
    return boost::uuids::to_string(id);
  }

  static std::optional<boost::uuids::uuid> ConvertStringToUUID(const std::string& str) {
    boost::uuids::string_generator string_generator;
    boost::uuids::uuid article;
    try {
      article = string_generator(str);
    }
    catch(...) {
      return std::nullopt;
    }
    return article;
  }

  static std::unique_ptr<ComponentInterface> ConvertComponentDTOToEntity(const ComponentDTO& dto) {
    try {
      std::unique_ptr<ComponentInterface> result;
      if (ComponentType::RAM == dto.GetComponentType()) {
        result = component_factory::CreateRAM(dto.GetMemoryCapacity().value(),
                                              dto.GetFrequency().value());
      } else if (ComponentType::PROCCESSOR == dto.GetComponentType()) {
        result = component_factory::CreateProcessor(dto.GetMinimalFrequency().value(),
                                                    dto.GetMaximalFrequency().value(),
                                                    dto.GetCoresNumber().value(),
                                                    dto.GetCoolerFlag().value());
      } else if (ComponentType::MOTHERPLATE == dto.GetComponentType()) {
        result = component_factory::CreateMotherPlate(dto.GetMaxRam().value(), dto.GetSocket().value());
      } else if (ComponentType::HARDDISK == dto.GetComponentType()) {
        result = component_factory::CreateHardDisk(dto.GetCapacity().value(),
                                                   dto.GetTurnsPerMinute().value(),
                                                   dto.GetSSDFlag().value());
      } else if (ComponentType::GRAPHICSCARD == dto.GetComponentType()) {
        result = component_factory::CreateGraphicsCard(dto.GetMemoryCapacity().value(),
                                                       dto.GetCoreFrequency().value(),
                                                       dto.GetMemoryFrequency().value(),
                                                       dto.GetDisplayPortsNum().value());
      }
      return result;
    }
    catch(...) {
      return nullptr;
    }
  }

  static ComponentDTO ConvertEntityToComponentDTO(const std::shared_ptr<ComponentEntity>& component) {
    auto characteristics = component->GetComponent().GetCharacteristics();
    auto type = component->GetComponent().GetComponentType();
    auto price = component->GetPrice();
    auto article = ConvertUUIDToString(component->GetArticle());
    if(type == ComponentType::RAM) {
      return ComponentDTO::CreateRAM(characteristics.memory_capacity_.value(),
                                     characteristics.frequency_.value(),
                                     price, article);
    }
    else if(type == ComponentType::PROCCESSOR) {
      return ComponentDTO::CreateProcessor(characteristics.minimal_frequency_.value(),
                                           characteristics.maximal_frequency_.value(),
                                           characteristics.cores_number_.value(),
                                           characteristics.has_cooler_.value(),
                                           price, article);
    }
    else if(type == ComponentType::MOTHERPLATE) {
      return ComponentDTO::CreateMotherPlate(characteristics.max_ram_.value(),
                                             characteristics.socket_.value(),
                                             price, article);
    }
    else if(type == ComponentType::HARDDISK) {
      return ComponentDTO::CreateHardDisk(characteristics.capacity_.value(),
                                          characteristics.turns_per_minute_.value(),
                                          characteristics.is_ssd_.value(),
                                          price, article);
    }
    else if(type == ComponentType::GRAPHICSCARD) {
      return ComponentDTO::CreateGraphicsCard(characteristics.memory_capacity_.value(),
                                              characteristics.core_frequency_.value(),
                                              characteristics.memory_frequency_.value(),
                                              characteristics.display_ports_num_.value(),
                                              price, article);
    }
    else throw std::runtime_error("Not full coverage of enum.");
  }

  static std::shared_ptr<Worker> ConvertWorkerDTOToEntity(const WorkerDTO& dto, const unsigned int& id) {
    auto phone = PhoneNumber::Create(dto.GetPhoneNumber());
    if(!phone.has_value()) return nullptr;
    auto person = Person{dto.GetName(), phone.value()};
    return std::make_shared<Worker>(id, person, dto.GetSalary());
  }

  static WorkerDTO ConvertEntityToWorkerDTO(const std::shared_ptr<Worker>& worker) {
    auto person = worker->GetPerson();
    auto phone = person.GetPhoneNumber().number_;
    auto id = worker->GetID();
    auto salary = worker->GetSalary();
    auto name = person.GetName();

    return WorkerDTO{name, phone, salary, id};
  }
}

#endif //COMPSHOP_SRC_CORE_MODELAPICONVERTER_H_
