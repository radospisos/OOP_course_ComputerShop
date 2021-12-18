//
// Created by Rodion Shyshkin on 11.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_WORKERS_PHONENUMBER_H_
#define COMPSHOP_SRC_CORE_WORKERS_PHONENUMBER_H_

#include <string>
#include <optional>

class PhoneNumber {
 public:
  static std::optional<PhoneNumber> Create(const std::string& number) {
    if(number.size() != 10) return std::nullopt;
    if(number[0] != '0') return std::nullopt;
    if(!std::all_of(number.begin(), number.end(), ::isdigit)) return std::nullopt;

    return PhoneNumber{number};
  }

 public:
  std::string number_;

 private:
  explicit PhoneNumber(const std::string& number) : number_(number) { }
};

#endif //COMPSHOP_SRC_CORE_WORKERS_PHONENUMBER_H_
