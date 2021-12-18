//
// Created by Rodion Shyshkin on 13.12.2020.
//

#include "WorkerDTO.h"

WorkerDTO::WorkerDTO(const std::string &name,
                     const std::string &phone_number,
                     const unsigned int &salary,
                     const unsigned int &id) {
  name_ = name;
  phone_number_ = phone_number;
  salary_ = salary;
  id_ = id;
}

unsigned int WorkerDTO::GetSalary() const {
  return salary_;
}

std::string WorkerDTO::GetPhoneNumber() const {
  return phone_number_;
}

std::string WorkerDTO::GetName() const {
  return name_;
}

unsigned int WorkerDTO::GetWorkerID() const {
  return id_;
}