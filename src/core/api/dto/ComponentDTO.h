//
// Created by Rodion Shyshkin on 13.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_COMPONENTDTO_H_
#define COMPSHOP_SRC_CORE_COMPONENTDTO_H_

#include <memory>
#include <string>
#include <optional>
#include <memory_model/storage/components/ComponentType.h>
#include <memory_model/storage/components/Characteristics.h>

class ComponentDTO {
 public:
  ComponentDTO();

  static ComponentDTO CreateProcessor(const double &minimal_frequency,
                                      const double &maximal_frequency,
                                      const unsigned int &cores_number,
                                      const bool &has_cooler,
                                      const unsigned int& price,
                                      const std::string& article);
  static ComponentDTO CreateRAM(const unsigned int &memory_capacity,
                                const unsigned int &frequency,
                                const unsigned int& price,
                                const std::string& article);
  static ComponentDTO CreateMotherPlate(const unsigned int &max_ram,
                                        const std::string &socket,
                                        const unsigned int& price,
                                        const std::string& article);
  static ComponentDTO CreateHardDisk(const unsigned int &capacity,
                                     const unsigned int &turns_per_minute,
                                     const bool &is_ssd,
                                     const unsigned int& price,
                                     const std::string& article);
  static ComponentDTO CreateGraphicsCard(const unsigned int &memory_capacity,
                                         const unsigned int &core_frequency,
                                         const unsigned int &memory_frequency,
                                         const unsigned int &display_ports_num,
                                         const unsigned int& price,
                                         const std::string& article);

  ComponentType GetComponentType() const;

  std::optional<unsigned int> GetMemoryCapacity() const;
  std::optional<unsigned int> GetFrequency() const;
  std::optional<double> GetMinimalFrequency() const;
  std::optional<double> GetMaximalFrequency() const;
  std::optional<unsigned int> GetCoresNumber() const;
  std::optional<bool> GetCoolerFlag() const;
  std::optional<unsigned int> GetMaxRam() const;
  std::optional<std::string> GetSocket() const;
  std::optional<unsigned int> GetCapacity() const;
  std::optional<unsigned int> GetTurnsPerMinute() const;
  std::optional<bool> GetSSDFlag() const;
  std::optional<unsigned int> GetCoreFrequency() const;
  std::optional<unsigned int> GetMemoryFrequency() const;
  std::optional<unsigned int> GetDisplayPortsNum() const;
  unsigned int GetPrice() const;
  std::string GetArticle() const;
  Characteristics GetCharacteristics() const;

 private:
  ComponentDTO(std::optional<unsigned int> memory_capacity,
               std::optional<unsigned int> frequency,
               std::optional<double>       minimal_frequency,
               std::optional<double>       maximal_frequency,
               std::optional<unsigned int> cores_number,
               std::optional<bool>         has_cooler,
               std::optional<unsigned int> max_ram,
               std::optional<std::string>  socket,
               std::optional<unsigned int>  capacity,
               std::optional<unsigned int>  turns_per_minute,
               std::optional<bool>          is_ssd,
               std::optional<unsigned int> core_frequency,
               std::optional<unsigned int> memory_frequency,
               std::optional<unsigned int> display_ports_num,
               const unsigned int& price,
               const std::string& article,
               ComponentType type);

 private:
  Characteristics characteristics_;
  ComponentType type_;
  unsigned int price_;
  std::string article_;
};

#endif //COMPSHOP_SRC_CORE_COMPONENTDTO_H_
