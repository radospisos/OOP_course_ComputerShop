//
// Created by Rodion Shyshkin on 11.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_SHOPMODEL_H_
#define COMPSHOP_SRC_CORE_SHOPMODEL_H_

#include <memory_model/storage/ShopStorage.h>
#include <memory_model/storage/WorkerIDGenerator.h>
#include <memory_model/storage/ShopView.h>
#include "api/dto/ComponentDTO.h"
#include "ModelAPIUtils.h"
#include "api/dto/WorkerDTO.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

class ShopModel {
 public:
  ShopModel();
  ShopModel(ShopModel& model);
  ShopModel(std::unique_ptr<ShopStorage> storage,
            std::unique_ptr<ShopView> view,
            std::unique_ptr<WorkerIDGenerator> worker_id_generator);

  bool AddComponent(const ComponentDTO& dto);
  bool AddWorker(const WorkerDTO& dto);

  bool RemoveComponent(const std::string& article) const;
  bool RemoveWorker(const unsigned int& id) const;

  std::optional<ComponentDTO> GetComponent(const std::string& article) const;
  std::optional<WorkerDTO>    GetWorker(const unsigned int& id) const;

  std::vector<ComponentDTO>   GetAllComponents() const;
  std::vector<ComponentDTO>   GetComponentsSortedByPrice() const;
  std::vector<ComponentDTO>   GetComponentsByType(const ComponentType& type) const;
  std::vector<ComponentDTO>   GetComponentsInPriceRange(const unsigned int& lhs,
                                                        const unsigned int& rhs) const;
  std::vector<WorkerDTO>      GetAllWorkers() const;
  std::vector<WorkerDTO>      GetWorkersSortedBySalary() const;
  std::vector<WorkerDTO>      GetWorkersByName(const std::string& name) const;

 private:
  std::unique_ptr<ShopStorage> storage_;
  std::unique_ptr<ShopView> view_;
  std::unique_ptr<WorkerIDGenerator> worker_id_generator_;
};

#endif //COMPSHOP_SRC_CORE_SHOPMODEL_H_
