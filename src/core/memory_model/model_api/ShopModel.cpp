//
// Created by Rodion Shyshkin on 11.12.2020.
//

#include "ShopModel.h"

ShopModel::ShopModel() : storage_(std::make_unique<ShopStorage>()),
                          view_(std::make_unique<ShopView>()),
                          worker_id_generator_(std::make_unique<WorkerIDGenerator>()) {

}

ShopModel::ShopModel(std::unique_ptr<ShopStorage> storage,
                     std::unique_ptr<ShopView> view,
                     std::unique_ptr<WorkerIDGenerator> worker_id_generator) :
                     storage_(std::move(storage)), view_(std::move(view)),
                     worker_id_generator_(std::move(worker_id_generator)) {

}

bool ShopModel::AddComponent(const ComponentDTO &dto) {
  std::shared_ptr<ComponentInterface> interface = model_api_utils::ConvertComponentDTOToEntity(dto);
  boost::uuids::uuid newarticle = boost::uuids::random_generator_mt19937()();

  auto entity = ComponentEntity::Create(std::move(newarticle), dto.GetPrice(), interface);
  if(!entity.has_value()) return false;
  if(!storage_->AddComponent(std::make_shared<ComponentEntity>(entity.value()))) return false;
  if(!view_->AddComponent(std::make_shared<ComponentEntity>(entity.value()))) return false;

  return true;
}

bool ShopModel::AddWorker(const WorkerDTO &dto) {
  auto newid = worker_id_generator_->GenerateID();
  std::shared_ptr<Worker> worker = model_api_utils::ConvertWorkerDTOToEntity(dto, newid);
  if(worker == nullptr) return false;
  if(!storage_->AddWorker(worker)) return false;
  if(!view_->AddWorker(worker)) return false;
  return true;
}

std::optional<ComponentDTO> ShopModel::GetComponent(const std::string &article) const {
  auto newarticle = model_api_utils::ConvertStringToUUID(article);
  if(!newarticle.has_value()) return std::nullopt;
  auto component = storage_->GetComponent(newarticle.value());
  if(component == nullptr) return std::nullopt;
  auto dto = model_api_utils::ConvertEntityToComponentDTO(component);

  return dto;
}

std::optional<WorkerDTO> ShopModel::GetWorker(const unsigned int &id) const {
  auto worker = storage_->GetWorker(id);
  if(worker == nullptr) return std::nullopt;
  auto dto = model_api_utils::ConvertEntityToWorkerDTO(worker);

  return dto;
}

std::vector<ComponentDTO> ShopModel::GetAllComponents() const {
  std::vector<ComponentDTO> result;
  auto components = storage_->GetAllComponents();
  for(const auto& component : components) {
    result.push_back(model_api_utils::ConvertEntityToComponentDTO(component));
  }
  return result;
}

std::vector<WorkerDTO> ShopModel::GetAllWorkers() const {
  std::vector<WorkerDTO> result;
  auto workers = storage_->GetAllWorkers();
  for(const auto& worker : workers) {
    result.push_back(model_api_utils::ConvertEntityToWorkerDTO(worker));
  }
  return result;
}

bool ShopModel::RemoveWorker(const unsigned int &id) const {
  auto worker = storage_->GetWorker(id);
  if(worker == nullptr) return false;

  if(!storage_->RemoveWorker(id)) return false;
  if(!view_->RemoveWorker(id)) return false;
  return true;
}

bool ShopModel::RemoveComponent(const std::string &article) const {
  auto newarticle = model_api_utils::ConvertStringToUUID(article);
  if(!newarticle.has_value()) return false;
  auto component = storage_->GetComponent(newarticle.value());
  if(component == nullptr) return false;

  if(!storage_->RemoveComponent(component->GetArticle())) return false;
  if(!view_->RemoveComponent(component->GetArticle())) return false;

  return true;
}

std::vector<ComponentDTO> ShopModel::GetComponentsByType(const ComponentType &type) const {
  std::vector<ComponentDTO> result;
  auto entities = view_->GetComponentsByType(type);

  for(const auto& entity : entities) {
    result.push_back(model_api_utils::ConvertEntityToComponentDTO(entity));
  }
  return result;
}

std::vector<ComponentDTO> ShopModel::GetComponentsSortedByPrice() const {
  std::vector<ComponentDTO> result;
  auto entities = view_->GetComponentsSortedByPrice();

  for(const auto& entity : entities) {
    result.push_back(model_api_utils::ConvertEntityToComponentDTO(entity));
  }
  return result;
}

std::vector<ComponentDTO> ShopModel::GetComponentsInPriceRange(const unsigned int &lhs,
                                                               const unsigned int &rhs) const {
  std::vector<ComponentDTO> result;
  auto entities = view_->GetComponentsInPriceRange(lhs, rhs);

  for(const auto& entity : entities) {
    result.push_back(model_api_utils::ConvertEntityToComponentDTO(entity));
  }
  return result;
}

std::vector<WorkerDTO> ShopModel::GetWorkersByName(const std::string &name) const {
  std::vector<WorkerDTO> result;
  auto entities = view_->GetWorkersByName(name);

  for(const auto& entity : entities) {
    result.push_back(model_api_utils::ConvertEntityToWorkerDTO(entity));
  }
  return result;
}

std::vector<WorkerDTO> ShopModel::GetWorkersSortedBySalary() const {
  std::vector<WorkerDTO> result;
  auto entities = view_->GetWorkersSortedBySalary();

  for(const auto& entity : entities) {
    result.push_back(model_api_utils::ConvertEntityToWorkerDTO(entity));
  }
  return result;
}