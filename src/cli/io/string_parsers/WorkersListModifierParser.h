//
// Created by Rodion Shyshkin on 21.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_IO_STRING_PARSERS_WORKERSLISTMODIFIERPARSER_H_
#define COMPSHOP_SRC_CLI_IO_STRING_PARSERS_WORKERSLISTMODIFIERPARSER_H_

#include <map>
#include <string>
#include <WorkersListModifier.h>

namespace workers_list_modifier_parser {
  namespace modifiers_map {
    static std::map<std::string, WorkersListModifier> create() {
      std::map<std::string, WorkersListModifier> types;
      types["all"] = WorkersListModifier::ALL;
      types["salary_sorted"] = WorkersListModifier::SALARY_SORTED;
      types["by_name"] = WorkersListModifier::BY_NAME;

      return types;
    }
  }

  static WorkersListModifier Parse(std::string&& string) {
    auto types_map = modifiers_map::create();
    if(types_map.find(string) == types_map.end()) return WorkersListModifier::UNKNOWN;

    return types_map[string];
  }
}

#endif //COMPSHOP_SRC_CLI_IO_STRING_PARSERS_WORKERSLISTMODIFIERPARSER_H_
