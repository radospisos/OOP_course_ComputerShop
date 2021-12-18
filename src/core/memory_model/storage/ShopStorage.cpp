//
// Created by Rodion Shyshkin on 12.12.2020.
//

#include "ShopStorage.h"
#include <iostream>

bool ShopStorage::AddComponent(std::shared_ptr<ComponentEntity> component) {
  if(component == nullptr) return false;
  auto pair = std::make_pair(component->GetArticle(), component);
  components_.insert(pair);
  return true;
}

bool ShopStorage::AddWorker(std::shared_ptr<Worker> worker) {
  if(worker == nullptr) return false;
  auto pair = std::make_pair(worker->GetID(), worker);
  if(workers_.find(pair.first) != workers_.end()) return false;
  workers_.insert(pair);
  return true;
}

std::shared_ptr<ComponentEntity> ShopStorage::GetComponent(const boost::uuids::uuid &article) {
  if(components_.find(article) == components_.end()) return nullptr;
  return components_[article];
}

std::shared_ptr<Worker> ShopStorage::GetWorker(const unsigned int &worker_number) {
  try {
    return workers_.at(worker_number);
  }
  catch(...) {
    return nullptr;
  }
}

std::vector<std::shared_ptr<ComponentEntity>> ShopStorage::GetAllComponents() const {
  std::vector<std::shared_ptr<ComponentEntity>> result;
  for(const auto& [article, component] : components_) {
    result.push_back(component);
  }
  return result;
}

std::vector<std::shared_ptr<Worker>> ShopStorage::GetAllWorkers() const {
  std::vector<std::shared_ptr<Worker>> result;
  for(const auto& [id, worker] : workers_) {
    result.push_back(worker);
  }
  return result;
}

bool ShopStorage::RemoveComponent(const boost::uuids::uuid &article) {
  auto component = GetComponent(article);
  if(component == nullptr) return false;
  auto uuid = component->GetArticle();
  auto found = components_.find(uuid);
  if(found == components_.end()) return false;
  components_.erase(found);

  return true;
}

bool ShopStorage::RemoveWorker(const unsigned int &worker_number) {
  auto found = workers_.find(worker_number);
  if(found == workers_.end()) return false;
  workers_.erase(found);

  return true;
}