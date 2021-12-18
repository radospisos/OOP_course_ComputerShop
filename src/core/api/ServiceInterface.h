//
// Created by Rodion Shyshkin on 18.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_API_SERVICEINTERFACE_H_
#define COMPSHOP_SRC_CORE_API_SERVICEINTERFACE_H_

#include <vector>
#include <optional>
#include <api/dto/WorkerDTO.h>
#include <api/dto/ComponentDTO.h>

class ServiceInterface {
 public:
  ~ServiceInterface() = default;

/*
  virtual bool AddRAM(const unsigned int& price,
              const unsigned int& memory_capacity, const unsigned int& frequency) = 0;

  virtual bool AddProccessor(const unsigned int& price,
                     const double& minimal_frequency,
                     const double& maximal_frequency,
                     const unsigned int& cores_num,
                     const bool& has_cooler) = 0;

  virtual bool AddMotherPlate(const unsigned int& price,
                      const unsigned int& max_ram,
                      const std::string& socket) = 0;

  virtual bool AddHardDisk(const unsigned int& price,
                   const unsigned int& capacity,
                   const bool& is_ssd,
                   const unsigned int& turns_per_min) = 0;

  virtual bool AddGraphicsCard(const unsigned int& price,
                       const unsigned int& memory_capacity,
                       const unsigned int& core_frequency,
                       const unsigned int& memory_frequency,
                       const unsigned int& display_ports_amount) = 0;
*/
  virtual bool AddComponent(const ComponentDTO& component) = 0;
  virtual bool RemoveComponent(const std::string& article) = 0;

  virtual bool AddWorker(const WorkerDTO& worker) = 0;
  virtual bool RemoveWorker(const unsigned int& id) = 0;

  virtual std::optional<ComponentDTO> GetComponent(const std::string& article) const = 0;
  virtual std::optional<WorkerDTO>    GetWorker(const unsigned int& id) const = 0;

  virtual std::vector<ComponentDTO>   GetAllComponents() const = 0;
  virtual std::vector<ComponentDTO>   GetComponentsSortedByPrice() const = 0;
  virtual std::vector<ComponentDTO>   GetComponentsByType(const ComponentType& type) const = 0;
  virtual std::vector<ComponentDTO>   GetComponentsInPriceRange(const unsigned int& lhs,
                                                        const unsigned int& rhs) const = 0;
  virtual std::vector<WorkerDTO>      GetAllWorkers() const = 0;
  virtual std::vector<WorkerDTO>      GetWorkersSortedBySalary() const = 0;
  virtual std::vector<WorkerDTO>      GetWorkersByName(const std::string& name) const = 0;

  virtual bool                        SaveToFile(const std::string& filepath) = 0;
  virtual bool                        LoadFromFile(const std::string& filepath) = 0;
};

#endif //COMPSHOP_SRC_CORE_API_SERVICEINTERFACE_H_
