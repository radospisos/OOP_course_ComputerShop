//
// Created by Rodion Shyshkin on 12.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_SHOPSTORAGE_H_
#define COMPSHOP_SRC_CORE_SHOPSTORAGE_H_

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/string_generator.hpp>
#include <map>
#include <memory_model/storage/components/ComponentInterface.h>
#include <memory_model/storage/workers/Worker.h>
#include <memory_model/storage/components/ComponentEntity.h>

class ShopStorage {
 public:
  bool AddComponent(std::shared_ptr<ComponentEntity> component);
  bool AddWorker(std::shared_ptr<Worker> worker);

  std::shared_ptr<ComponentEntity>    GetComponent(const boost::uuids::uuid& article);
  std::shared_ptr<Worker>             GetWorker(const unsigned int& worker_number);

  std::vector<std::shared_ptr<ComponentEntity>>    GetAllComponents() const;
  std::vector<std::shared_ptr<Worker>>             GetAllWorkers() const;

  bool RemoveComponent(const boost::uuids::uuid& article);
  bool RemoveWorker(const unsigned int& worker_number);

 private:
  std::map<boost::uuids::uuid, std::shared_ptr<ComponentEntity>> components_;
  std::map<unsigned int, std::shared_ptr<Worker>> workers_;
};

#endif //COMPSHOP_SRC_CORE_SHOPSTORAGE_H_
