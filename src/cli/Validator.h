//
// Created by Rodion Shyshkin on 19.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_VALIDATOR_H_
#define COMPSHOP_SRC_CLI_VALIDATOR_H_

#include <string>
#include <api/dto/WorkerDTO.h>

namespace validator {
  static std::optional<unsigned int> ParseNumber(const std::string& number) {
    unsigned int result;
    try {
      result = std::stoul(number);
    }
    catch(...) {
      return std::nullopt;
    }
    return result;
  }

  static std::optional<double> ParseDoubleNumber(const std::string& number) {
    double result;
    try {
      result = std::stod(number);
    }
    catch(...) {
      return std::nullopt;
    }
    return result;
  }

  static std::optional<bool> ParseFlag(const std::string& number) {
    if(number == "y" || number == "yes") return true;
    else if(number == "n" || number == "no") return false;
    else return std::nullopt;
  }

  static bool ValidateStringFillness(const std::string& param) {
    return !param.empty();
  }
}

#endif //COMPSHOP_SRC_CLI_VALIDATOR_H_
