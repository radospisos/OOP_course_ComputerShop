//
// Created by Rodion Shyshkin on 13.12.2020.
//

#include "ComponentEntity.h"

std::optional<ComponentEntity> ComponentEntity::Create(boost::uuids::uuid &&article,
                                                         const unsigned int& price,
                                                         std::shared_ptr<ComponentInterface> component) {
  if(component == nullptr) return std::nullopt;
  return ComponentEntity{std::move(article), price, component};
}

ComponentEntity::ComponentEntity(boost::uuids::uuid&& article,
                                 const unsigned int& price,
                                 std::shared_ptr<ComponentInterface> component) :
    article_(std::move(article)), component_(component), price_(price) {}

ComponentInterface& ComponentEntity::GetComponent() const {
  return *component_;
}

boost::uuids::uuid ComponentEntity::GetArticle() const {
  return article_;
}

unsigned int ComponentEntity::GetPrice() const {
  return price_;
}