//
// Created by Rodion Shyshkin on 16.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_CHARACTERISTICS_H_
#define COMPSHOP_SRC_CORE_CHARACTERISTICS_H_

#include <optional>
#include <string>

struct Characteristics {

  std::optional<unsigned int> memory_capacity_;
  std::optional<unsigned int> frequency_;
  std::optional<double>       minimal_frequency_;
  std::optional<double>       maximal_frequency_;
  std::optional<unsigned int> cores_number_;
  std::optional<bool>         has_cooler_;
  std::optional<unsigned int> max_ram_;
  std::optional<std::string>  socket_;
  std::optional<unsigned int>  capacity_;
  std::optional<unsigned int>  turns_per_minute_;
  std::optional<bool>          is_ssd_;
  std::optional<unsigned int> core_frequency_;
  std::optional<unsigned int> memory_frequency_;
  std::optional<unsigned int> display_ports_num_;
};

#endif //COMPSHOP_SRC_CORE_CHARACTERISTICS_H_
