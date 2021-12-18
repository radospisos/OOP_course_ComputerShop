//
// Created by Rodion Shyshkin on 17.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_UTILS_PROTO_CONVERTER_H_
#define COMPSHOP_SRC_CORE_UTILS_PROTO_CONVERTER_H_

#include <component_type.pb.h>
#include <component.pb.h>
#include <storage.pb.h>
#include <worker.pb.h>
#include <characteristics.pb.h>
#include <memory_model/storage/components/ComponentEntity.h>
#include <api/dto/ComponentDTO.h>
#include <memory_model/model_api/ShopModel.h>

namespace proto_converter {
  static ComponentTypeProto ComponentTypeToProto(const ComponentType& type) {
    if(ComponentType::RAM == type) return ComponentTypeProto::RAM;
    else if(ComponentType::PROCCESSOR == type) return ComponentTypeProto::PROCCESSOR;
    else if(ComponentType::MOTHERPLATE == type) return ComponentTypeProto::MOTHERPLATE;
    else if(ComponentType::HARDDISK == type) return ComponentTypeProto::HARDDISK;
    else if(ComponentType::GRAPHICSCARD == type) return ComponentTypeProto::GRAPHICSCARD;
    else throw std::runtime_error("Not full coverage of enum.");
  }

  static ComponentType ComponentTypeFromProto(const ComponentTypeProto& type) {
    if(ComponentTypeProto::RAM == type) return ComponentType::RAM;
    if(ComponentTypeProto::PROCCESSOR == type) return ComponentType::PROCCESSOR;
    if(ComponentTypeProto::MOTHERPLATE == type) return ComponentType::MOTHERPLATE;
    if(ComponentTypeProto::HARDDISK == type) return ComponentType::HARDDISK;
    if(ComponentTypeProto::GRAPHICSCARD == type) return ComponentType::GRAPHICSCARD;
    else throw std::runtime_error("Not full coverage of enum.");
  }

  static Characteristics CharacteristicsFromProto(const CharacteristicsProto& characteristics) {
    Characteristics result;
    result.is_ssd_ = characteristics.ssd_flag();
    result.turns_per_minute_ = characteristics.turns_per_minute();
    result.capacity_ = characteristics.capacity();
    result.memory_capacity_ = characteristics.memory_capacity();
    result.memory_frequency_ = characteristics.memory_frequency();
    result.core_frequency_ = characteristics.core_frequency();
    result.minimal_frequency_ = characteristics.minimal_frequency();
    result.maximal_frequency_ = characteristics.maximal_frequency();
    result.max_ram_ = characteristics.max_ram();
    result.frequency_ = characteristics.frequency();
    result.socket_ = characteristics.socket();
    result.cores_number_ = characteristics.cores_number();
    result.has_cooler_ = characteristics.cooler_flag();
    result.display_ports_num_ = characteristics.display_ports_num();
    return result;
  }

  static CharacteristicsProto* CharacteristicsToProto(const Characteristics& characteristics) {
    auto result = CharacteristicsProto::default_instance().New();
    if(characteristics.is_ssd_.has_value()) result->set_ssd_flag(characteristics.is_ssd_.value());
    if(characteristics.turns_per_minute_.has_value()) result->set_turns_per_minute(characteristics.turns_per_minute_.value());
    if(characteristics.capacity_.has_value()) result->set_capacity(characteristics.capacity_.value());
    if(characteristics.memory_capacity_.has_value()) result->set_memory_capacity(characteristics.memory_capacity_.value());
    if(characteristics.memory_frequency_.has_value()) result->set_memory_frequency(characteristics.memory_frequency_.value());
    if(characteristics.core_frequency_.has_value()) result->set_core_frequency(characteristics.core_frequency_.value());
    if(characteristics.minimal_frequency_.has_value()) result->set_minimal_frequency(characteristics.minimal_frequency_.value());
    if(characteristics.maximal_frequency_.has_value()) result->set_maximal_frequency(characteristics.maximal_frequency_.value());
    if(characteristics.max_ram_.has_value()) result->set_max_ram(characteristics.max_ram_.value());
    if(characteristics.frequency_.has_value()) result->set_frequency(characteristics.frequency_.value());
    if(characteristics.socket_.has_value()) result->set_socket(characteristics.socket_.value());
    if(characteristics.cores_number_.has_value()) result->set_cores_number(characteristics.cores_number_.value());
    if(characteristics.has_cooler_.has_value()) result->set_cooler_flag(characteristics.has_cooler_.value());
    if(characteristics.display_ports_num_.has_value()) result->set_display_ports_num(characteristics.display_ports_num_.value());
    return result;
  }

  static std::optional<ComponentDTO> ComponentEntityFromProto(const ComponentProto& component) {
    auto type = ComponentTypeFromProto(component.type());
    auto characteristics = CharacteristicsFromProto(component.characteristics());
    auto price = component.price();
    auto article = component.article();
    try {
      if(ComponentType::RAM == type) {
        return ComponentDTO::CreateRAM(characteristics.memory_capacity_.value(),
                                       characteristics.frequency_.value(),
                                       price, article);
      }
      else if(ComponentType::PROCCESSOR == type) {
        return ComponentDTO::CreateProcessor(characteristics.minimal_frequency_.value(),
                                             characteristics.maximal_frequency_.value(),
                                             characteristics.cores_number_.value(),
                                             characteristics.has_cooler_.value(),
                                             price, article);
      }
      else if(ComponentType::MOTHERPLATE == type) {
        return ComponentDTO::CreateMotherPlate(characteristics.max_ram_.value(),
                                               characteristics.socket_.value(),
                                               price, article);
      }
      else if(ComponentType::HARDDISK == type) {
        return ComponentDTO::CreateHardDisk(characteristics.capacity_.value(),
                                            characteristics.turns_per_minute_.value(),
                                            characteristics.is_ssd_.value(),
                                            price, article);
      }
      else if(ComponentType::GRAPHICSCARD == type) {
        return ComponentDTO::CreateGraphicsCard(characteristics.memory_capacity_.value(),
                                                characteristics.core_frequency_.value(),
                                                characteristics.memory_frequency_.value(),
                                                characteristics.display_ports_num_.value(),
                                                price, article);
      }
      else throw std::runtime_error("Not full coverage of enum.");
    }
    catch(...) {
      return std::nullopt;
    }
  }

  static ComponentProto ComponentEntityToProto(const ComponentDTO& component) {
    auto proto = std::make_unique<ComponentProto>();
    proto->set_price(component.GetPrice());
    proto->set_type(ComponentTypeToProto(component.GetComponentType()));
    proto->set_article(component.GetArticle());
    proto->set_allocated_characteristics(CharacteristicsToProto(component.GetCharacteristics()));
    return *proto;
  }

  static std::optional<WorkerDTO> WorkerEntityFromProto(const WorkerProto& worker) {
    try {
      auto newworker = WorkerDTO{worker.name(), worker.phone(), worker.salary(), worker.id()};
      return newworker;
    }
    catch(...) {
      return std::nullopt;
    }
  }

  static WorkerProto WorkerEntityToProto(const WorkerDTO& worker) {
    auto newworker = std::make_unique<WorkerProto>();
    newworker->set_name(worker.GetName());
    newworker->set_phone(worker.GetPhoneNumber());
    newworker->set_id(worker.GetWorkerID());
    newworker->set_salary(worker.GetSalary());

    return *newworker;
  }

  static StorageProto StorageToProto(const std::vector<ComponentDTO>& components,
                              const std::vector<WorkerDTO>& workers) {
    StorageProto result;
    for(const auto& component : components) {
      auto* new_component = result.add_components();
      auto temporary = ComponentEntityToProto(component);
      *new_component = temporary;
    }
    for(const auto& worker : workers) {
      auto *new_worker = result.add_workers();
      auto temporary = WorkerEntityToProto(worker);
      *new_worker = temporary;
    }
    return result;
  }

  static std::unique_ptr<ShopModel> StorageFromProto(const StorageProto& storage) {
    auto result = std::make_unique<ShopModel>();
    for(const auto& item : storage.components()) {
      auto dto = ComponentEntityFromProto(item);
      if(!dto.has_value()) return nullptr;
      result->AddComponent(dto.value());
    }
    for(const auto& item : storage.workers()) {
      auto dto = WorkerEntityFromProto(item);
      if(!dto.has_value()) return nullptr;
      result->AddWorker(dto.value());
    }
    return result;
  }
}

#endif //COMPSHOP_SRC_CORE_UTILS_PROTO_CONVERTER_H_
