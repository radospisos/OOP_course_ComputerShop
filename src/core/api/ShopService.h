//
// Created by Rodion Shyshkin on 17.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_API_SHOPSERVICE_H_
#define COMPSHOP_SRC_CORE_API_SHOPSERVICE_H_

#include <api/ServiceInterface.h>
#include <memory_model/model_api/ShopModel.h>
#include <api/ProtoConverter.h>
#include <fstream>

class ShopService : public ServiceInterface {
 public:
  ShopService();
  ShopService(std::unique_ptr<ShopModel> model);

  bool AddComponent(const ComponentDTO& dto) override;
  bool RemoveComponent(const std::string& article) override;

  bool AddWorker(const WorkerDTO& dto) override;
  bool RemoveWorker(const unsigned int& id) override;

  std::optional<ComponentDTO> GetComponent(const std::string& article) const override;
  std::optional<WorkerDTO>    GetWorker(const unsigned int& id) const override;

  std::vector<ComponentDTO>   GetAllComponents() const override;
  std::vector<ComponentDTO>   GetComponentsSortedByPrice() const override;
  std::vector<ComponentDTO>   GetComponentsByType(const ComponentType& type) const override;
  std::vector<ComponentDTO>   GetComponentsInPriceRange(const unsigned int& lhs,
                                                        const unsigned int& rhs) const override;
  std::vector<WorkerDTO>      GetAllWorkers() const override;
  std::vector<WorkerDTO>      GetWorkersSortedBySalary() const override;
  std::vector<WorkerDTO>      GetWorkersByName(const std::string& name) const override;

  bool                        SaveToFile(const std::string& filepath) override;
  bool                        LoadFromFile(const std::string& filepath) override;

 private:
  std::unique_ptr<ShopModel> model_;
};

#endif //COMPSHOP_SRC_CORE_API_SHOPSERVICE_H_
