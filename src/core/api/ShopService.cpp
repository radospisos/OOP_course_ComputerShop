//
// Created by Rodion Shyshkin on 17.12.2020.
//

#include "ShopService.h"

ShopService::ShopService() : model_(std::make_unique<ShopModel>()) {

}

ShopService::ShopService(std::unique_ptr<ShopModel> model) : model_(std::move(model)) {

}

bool ShopService::AddComponent(const ComponentDTO &dto) {
  return model_->AddComponent(dto);
}

bool ShopService::RemoveComponent(const std::string &article) {
  return model_->RemoveComponent(article);
}

bool ShopService::AddWorker(const WorkerDTO& dto) {
  return model_->AddWorker(dto);
}

bool ShopService::RemoveWorker(const unsigned int &id) {
  return model_->RemoveWorker(id);
}

std::optional<ComponentDTO> ShopService::GetComponent(const std::string &article) const {
  return model_->GetComponent(article);
}

std::optional<WorkerDTO> ShopService::GetWorker(const unsigned int &id) const {
  return model_->GetWorker(id);
}

std::vector<ComponentDTO> ShopService::GetAllComponents() const {
  return model_->GetAllComponents();
}

std::vector<ComponentDTO> ShopService::GetComponentsByType(const ComponentType &type) const {
  return model_->GetComponentsByType(type);
}

std::vector<ComponentDTO> ShopService::GetComponentsSortedByPrice() const {
  return model_->GetComponentsSortedByPrice();
}

std::vector<ComponentDTO> ShopService::GetComponentsInPriceRange(const unsigned int &lhs,
                                                                 const unsigned int &rhs) const {
  return model_->GetComponentsInPriceRange(lhs, rhs);
}

std::vector<WorkerDTO> ShopService::GetAllWorkers() const {
  return model_->GetAllWorkers();
}

std::vector<WorkerDTO> ShopService::GetWorkersSortedBySalary() const {
  return model_->GetWorkersSortedBySalary();
}

std::vector<WorkerDTO> ShopService::GetWorkersByName(const std::string &name) const {
  return model_->GetWorkersByName(name);
}

bool ShopService::SaveToFile(const std::string &filepath) {
  std::fstream file(filepath, std::ios::out);
  if(!file.is_open()) return false;

  StorageProto proto = proto_converter::StorageToProto(model_->GetAllComponents(),
                                                       model_->GetAllWorkers());
  if(!proto.SerializeToOstream(&file)) return false;

  file.close();
  return true;
}

bool ShopService::LoadFromFile(const std::string &filepath) {
  std::fstream file(filepath, std::ios::in);
  if(!file.is_open()) return false;

  StorageProto proto;
  if(!proto.ParseFromIstream(&file)) {
    file.close();
    return false;
  }
  file.close();

  auto newmodel = proto_converter::StorageFromProto(proto);
  if(newmodel == nullptr) return false;
  model_ = std::move(newmodel);
  return true;
}