//
// Created by Rodion Shyshkin on 17.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_MEMORYMODEL_STORAGE_SHOPVIEWMAP_H_
#define COMPSHOP_SRC_CORE_MEMORYMODEL_STORAGE_SHOPVIEWMAP_H_

#include <boost/uuid/uuid.hpp>
#include <map>
#include <memory_model/storage/components/ComponentEntity.h>
#include <memory_model/storage/workers/Worker.h>
#include <iostream>

namespace shop_view_map {
  template<typename T>
  bool FindComponentByID(const boost::uuids::uuid &article,
                std::map<T, std::map<boost::uuids::uuid, std::shared_ptr<ComponentEntity>>> map) {
    for(const auto& [type, components] : map) {
      for(const auto& [ID, component] : components) {
        if (ID == article) return true;
      }
    }
    return false;
  }

  template<typename T>
  bool FindWorkerByID(const unsigned int& id,
                         std::map<T, std::map<unsigned int, std::weak_ptr<Worker>>> map) {
    for(const auto& [type, workers] : map) {
      for(const auto& [ID, worker] : workers) {
        if (ID == id) return true;
      }
    }
    return false;
  }

  template<typename T>
  bool RemoveComponentFromMap(const boost::uuids::uuid &article,
                         std::map<T, std::map<boost::uuids::uuid, std::shared_ptr<ComponentEntity>>>& map) {
    for(auto& [type, components] : map) {
      auto found = components.find(article);
      if(found != components.end()) {
        components.erase(found);
        return true;
      }
    }
    return false;
  }

  template<typename T>
  bool RemoveWorkerFromMap(const unsigned int& id,
                      std::map<T, std::map<unsigned int, std::weak_ptr<Worker>>>& map) {
    for(auto& [type, workers] : map) {
      auto found = workers.find(id);
      if(found != workers.end()) {
        workers.erase(found);
        return true;
      }
    }
    return false;
  }
}

#endif //COMPSHOP_SRC_CORE_MEMORYMODEL_STORAGE_SHOPVIEWMAP_H_
