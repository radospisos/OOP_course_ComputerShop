//
// Created by Rodion Shyshkin on 13.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_WORKERS_PERSON_H_
#define COMPSHOP_SRC_CORE_WORKERS_PERSON_H_

#include <string>
#include "PhoneNumber.h"

class Person {
 public:
  Person(const std::string& name, const PhoneNumber& number);

  std::string GetName() const;
  PhoneNumber GetPhoneNumber() const;

 private:
  std::string name_;
  PhoneNumber phone_number_;
};

#endif //COMPSHOP_SRC_CORE_WORKERS_PERSON_H_
