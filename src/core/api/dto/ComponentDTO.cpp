//
// Created by Rodion Shyshkin on 13.12.2020.
//

#include "ComponentDTO.h"

ComponentDTO::ComponentDTO() : type_(ComponentType::UNKNOWN), price_(0) {  }

ComponentDTO ComponentDTO::CreateProcessor(const double &minimal_frequency,
                                           const double &maximal_frequency,
                                           const unsigned int &cores_number,
                                           const bool &has_cooler,
                                           const unsigned int& price,
                                           const std::string& article) {
  return ComponentDTO{std::nullopt, std::nullopt, minimal_frequency, maximal_frequency,
                      cores_number, has_cooler, std::nullopt, std::nullopt, std::nullopt,
                      std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt,
                      price, article, ComponentType::PROCCESSOR};
}

ComponentDTO ComponentDTO::CreateRAM(const unsigned int &memory_capacity, const unsigned int &frequency,
                                     const unsigned int& price,
                                     const std::string& article) {
  return ComponentDTO{memory_capacity, frequency, std::nullopt, std::nullopt,
                      std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt,
                      std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt,
                      price, article, ComponentType::RAM};
}

ComponentDTO ComponentDTO::CreateMotherPlate(const unsigned int &max_ram, const std::string &socket,
                                             const unsigned int& price,
                                             const std::string& article) {
  return ComponentDTO{std::nullopt, std::nullopt, std::nullopt, std::nullopt,
                      std::nullopt, std::nullopt, max_ram, socket, std::nullopt,
                      std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt,
                      price, article, ComponentType::MOTHERPLATE};
}

ComponentDTO ComponentDTO::CreateHardDisk(const unsigned int &capacity,
                                          const unsigned int &turns_per_minute, const bool &is_ssd,
                                          const unsigned int& price,
                                          const std::string& article) {
  return ComponentDTO{std::nullopt, std::nullopt, std::nullopt, std::nullopt,
                      std::nullopt, std::nullopt, std::nullopt, std::nullopt, capacity,
                      turns_per_minute, is_ssd, std::nullopt, std::nullopt, std::nullopt,
                      price, article, ComponentType::HARDDISK};
}

ComponentDTO ComponentDTO::CreateGraphicsCard(const unsigned int &memory_capacity,
                                              const unsigned int &core_frequency,
                                              const unsigned int &memory_frequency,
                                              const unsigned int &display_ports_num,
                                              const unsigned int& price,
                                              const std::string& article) {
  return ComponentDTO{memory_capacity, std::nullopt, std::nullopt, std::nullopt,
                      std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt,
                      std::nullopt, std::nullopt, core_frequency, memory_frequency, display_ports_num,
                      price, article, ComponentType::GRAPHICSCARD};
}

ComponentDTO::ComponentDTO(std::optional<unsigned int> memory_capacity,
                           std::optional<unsigned int> frequency,
                           std::optional<double> minimal_frequency,
                           std::optional<double> maximal_frequency,
                           std::optional<unsigned int> cores_number,
                           std::optional<bool> has_cooler,
                           std::optional<unsigned int> max_ram,
                           std::optional<std::string> socket,
                           std::optional<unsigned int> capacity,
                           std::optional<unsigned int> turns_per_minute,
                           std::optional<bool> is_ssd,
                           std::optional<unsigned int> core_frequency,
                           std::optional<unsigned int> memory_frequency,
                           std::optional<unsigned int> display_ports_num,
                           const unsigned int& price,
                           const std::string& article,
                           ComponentType type) {
  characteristics_.memory_capacity_ = memory_capacity;
  characteristics_.frequency_ = frequency;
  characteristics_.minimal_frequency_ = minimal_frequency;
  characteristics_.maximal_frequency_ = maximal_frequency;
  characteristics_.cores_number_ = cores_number;
  characteristics_.has_cooler_ = has_cooler;
  characteristics_.max_ram_ = max_ram;
  characteristics_.socket_ = socket;
  characteristics_.capacity_ = capacity;
  characteristics_.turns_per_minute_ = turns_per_minute;
  characteristics_.is_ssd_ = is_ssd;
  characteristics_.core_frequency_ = core_frequency;
  characteristics_.memory_frequency_ = memory_frequency;
  characteristics_.display_ports_num_ = display_ports_num;
  price_ = price;
  type_ = type;
  article_ = article;
}

ComponentType ComponentDTO::GetComponentType() const {
  return type_;
}

std::optional<std::string> ComponentDTO::GetSocket() const {
  return characteristics_.socket_;
}

std::optional<unsigned int> ComponentDTO::GetFrequency() const {
  return characteristics_.frequency_;
}

std::optional<unsigned int> ComponentDTO::GetMaxRam() const {
  return characteristics_.max_ram_;
}

std::optional<unsigned int> ComponentDTO::GetMemoryCapacity() const {
  return characteristics_.memory_capacity_;
}

std::optional<unsigned int> ComponentDTO::GetMemoryFrequency() const {
  return characteristics_.memory_frequency_;
}

std::optional<unsigned int> ComponentDTO::GetCoreFrequency() const {
  return characteristics_.core_frequency_;
}

std::optional<unsigned int> ComponentDTO::GetDisplayPortsNum() const {
  return characteristics_.display_ports_num_;
}

std::optional<unsigned int> ComponentDTO::GetCapacity() const {
  return characteristics_.capacity_;
}

std::optional<bool> ComponentDTO::GetCoolerFlag() const {
  return characteristics_.has_cooler_;
}

std::optional<unsigned int> ComponentDTO::GetCoresNumber() const {
  return characteristics_.cores_number_;
}

std::optional<double> ComponentDTO::GetMaximalFrequency() const {
  return characteristics_.maximal_frequency_;
}

std::optional<double> ComponentDTO::GetMinimalFrequency() const {
  return characteristics_.minimal_frequency_;
}

std::optional<bool> ComponentDTO::GetSSDFlag() const {
  return characteristics_.is_ssd_;
}

std::optional<unsigned int> ComponentDTO::GetTurnsPerMinute() const {
  return characteristics_.turns_per_minute_;
}

unsigned int ComponentDTO::GetPrice() const {
  return price_;
}

std::string ComponentDTO::GetArticle() const {
  return article_;
}

Characteristics ComponentDTO::GetCharacteristics() const {
  return characteristics_;
}