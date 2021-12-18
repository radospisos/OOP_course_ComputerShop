//
// Created by Rodion Shyshkin on 11.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_WORKERS_WORKER_H_
#define COMPSHOP_SRC_CORE_WORKERS_WORKER_H_

#include "Person.h"
#include <memory>

class Worker {
 public:
  Worker(const unsigned int& id, const Person& person, const unsigned int& salary);

  unsigned int GetID() const;
  Person GetPerson() const;
  unsigned int GetSalary() const;

 private:
  unsigned int id_;
  Person person_;
  unsigned int salary_;
};

#endif //COMPSHOP_SRC_CORE_WORKERS_WORKER_H_
