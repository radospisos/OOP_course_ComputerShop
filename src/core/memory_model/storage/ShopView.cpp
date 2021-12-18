//
// Created by Rodion Shyshkin on 13.12.2020.
//

#include "ShopView.h"

bool ShopView::AddComponent(const std::shared_ptr<ComponentEntity> &component) {
  auto article = component->GetArticle();
  auto pair = std::make_pair(article, component);

  if(shop_view_map::FindComponentByID(article, by_type_) ||
      shop_view_map::FindComponentByID(article, by_price_)) return false;

  by_type_[component->GetComponent().GetComponentType()].insert(pair);
  by_price_[component->GetPrice()].insert(pair);
  return true;
}

bool ShopView::AddWorker(const std::shared_ptr<Worker> &worker) {
  auto id = worker->GetID();
  auto pair = std::make_pair(id, worker);

  if(shop_view_map::FindWorkerByID(id, by_name_) ||
    shop_view_map::FindWorkerByID(id, by_salary_)) return false;

  by_name_[worker->GetPerson().GetName()].insert(pair);
  by_salary_[worker->GetSalary()].insert(pair);
  return true;
}

bool ShopView::RemoveComponent(const boost::uuids::uuid &article) {
  return (shop_view_map::RemoveComponentFromMap(article, by_type_)
          && shop_view_map::RemoveComponentFromMap(article, by_price_));
}

bool ShopView::RemoveWorker(const unsigned int &id) {
  return (shop_view_map::RemoveWorkerFromMap(id, by_name_) &&
          shop_view_map::RemoveWorkerFromMap(id, by_salary_));
}

std::vector<std::shared_ptr<Worker>> ShopView::GetWorkersSortedBySalary() const {
  std::vector<std::shared_ptr<Worker>> result;
  for(const auto& [salary, map] : by_salary_) {
    for(const auto& [id, worker] : map) {
      result.push_back(worker.lock());
    }
  }
  return result;
}

std::vector<std::shared_ptr<Worker>> ShopView::GetWorkersByName(const std::string &name) const {
  std::vector<std::shared_ptr<Worker>> result;
  auto key = by_name_.find(name);
  if(key == by_name_.end()) return result;
  for(const auto& [id, worker] : key->second) {
    result.push_back(worker.lock());
  }
  return result;
}

std::vector<std::shared_ptr<ComponentEntity>> ShopView::GetComponentsSortedByPrice() const {
  std::vector<std::shared_ptr<ComponentEntity>> result;
  for(const auto& [price, map] : by_price_) {
    for(const auto& [article, component] : map) {
      result.push_back(component);
    }
  }
  return result;
}

std::vector<std::shared_ptr<ComponentEntity>> ShopView::GetComponentsInPriceRange(const unsigned int &lhs,
                                                                 const unsigned int &rhs) const {
  std::vector<std::shared_ptr<ComponentEntity>> result;
  for(const auto& [price, map] : by_price_) {
    for(const auto& [article, component] : map) {
      if(component->GetPrice() >= lhs &&
      component->GetPrice() <= rhs) result.push_back(component);
    }
  }
  return result;
}

std::vector<std::shared_ptr<ComponentEntity>> ShopView::GetComponentsByType(const ComponentType &type) const {
  std::vector<std::shared_ptr<ComponentEntity>> result;
  auto key = by_type_.find(type);
  if(key == by_type_.end()) return result;
  for(const auto& [article, component] : key->second) {
    result.push_back(component);
  }
  return result;
}