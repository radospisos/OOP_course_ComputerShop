//
// Created by Rodion Shyshkin on 13.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_WORKERDTO_H_
#define COMPSHOP_SRC_CORE_WORKERDTO_H_

#include <optional>
#include "memory_model/storage/workers/PhoneNumber.h"
#include <string>

class WorkerDTO {
 public:
  WorkerDTO() = default;
  /*static std::optional<WorkerDTO> Create(const std::string& name,
                                         const std::string& phone_number,
                                         const unsigned int& salary,
                                         const unsigned int& id);*/

  WorkerDTO(const std::string& name, const std::string& phone_number,
            const unsigned int& salary, const unsigned int& id);

 public:
  std::string GetName() const;
  std::string GetPhoneNumber() const;
  unsigned int GetSalary() const;
  unsigned int GetWorkerID() const;

 private:
  std::string name_;
  std::string phone_number_;
  unsigned int salary_;
  unsigned int id_;
};

#endif //COMPSHOP_SRC_CORE_WORKERDTO_H_
