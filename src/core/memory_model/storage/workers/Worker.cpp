//
// Created by Rodion Shyshkin on 11.12.2020.
//

#include "Worker.h"

Worker::Worker(const unsigned int& id,
               const Person& person,
               const unsigned int &salary) :
               id_(id),
               person_(person),
               salary_(salary){

}

unsigned int Worker::GetID() const {
  return id_;
}

Person Worker::GetPerson() const {
  return person_;
}

unsigned int Worker::GetSalary() const {
  return salary_;
}
