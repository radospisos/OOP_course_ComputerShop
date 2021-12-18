//
// Created by Rodion Shyshkin on 13.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_SHOPVIEW_H_
#define COMPSHOP_SRC_CORE_SHOPVIEW_H_

#include <memory>
#include <memory_model/storage/components/ComponentEntity.h>
#include <memory_model/storage/workers/Worker.h>
#include <map>
#include <memory_model/storage/ShopViewMap.h>

class ShopView {
 public:
  ShopView() = default;

  bool AddComponent(const std::shared_ptr<ComponentEntity>& component);
  bool AddWorker(const std::shared_ptr<Worker>& worker);

  bool RemoveComponent(const boost::uuids::uuid& article);
  bool RemoveWorker(const unsigned int& id);

  std::vector<std::shared_ptr<ComponentEntity>> GetComponentsByType(const ComponentType& type) const;
  std::vector<std::shared_ptr<ComponentEntity>> GetComponentsSortedByPrice() const;
  std::vector<std::shared_ptr<ComponentEntity>> GetComponentsInPriceRange(const unsigned int& lhs,
                                                         const unsigned int& rhs) const;

  std::vector<std::shared_ptr<Worker>>         GetWorkersByName(const std::string& name) const;
  std::vector<std::shared_ptr<Worker>>         GetWorkersSortedBySalary() const;

 private:
  std::map<ComponentType, std::map<boost::uuids::uuid, std::shared_ptr<ComponentEntity>>> by_type_;
  std::map<unsigned int, std::map<boost::uuids::uuid, std::shared_ptr<ComponentEntity>>> by_price_;

  std::map<unsigned int, std::map<unsigned int, std::weak_ptr<Worker>>> by_salary_;
  std::map<std::string, std::map<unsigned int, std::weak_ptr<Worker>>> by_name_;
};

#endif //COMPSHOP_SRC_CORE_SHOPVIEW_H_
