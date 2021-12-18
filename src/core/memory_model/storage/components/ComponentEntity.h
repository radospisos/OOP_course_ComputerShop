//
// Created by Rodion Shyshkin on 13.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_COMPONENTS_COMPONENTENTITY_H_
#define COMPSHOP_SRC_CORE_COMPONENTS_COMPONENTENTITY_H_

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <optional>
#include "ComponentInterface.h"

class ComponentEntity {
 public:
  static std::optional<ComponentEntity> Create(boost::uuids::uuid&& article,
                                                 const unsigned int& price,
                                                 std::shared_ptr<ComponentInterface> component);

  boost::uuids::uuid GetArticle() const;
  ComponentInterface& GetComponent() const;
  unsigned int GetPrice() const;

 private:
  ComponentEntity(boost::uuids::uuid&& article,
                  const unsigned int& price,
                  std::shared_ptr<ComponentInterface> component);

 private:
  boost::uuids::uuid article_;
  unsigned int       price_;
  std::shared_ptr<ComponentInterface> component_;
};

#endif //COMPSHOP_SRC_CORE_COMPONENTS_COMPONENTENTITY_H_
