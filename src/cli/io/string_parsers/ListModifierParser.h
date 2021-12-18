//
// Created by Rodion Shyshkin on 21.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_IO_STRING_PARSERS_LISTMODIFICATORPARSER_H_
#define COMPSHOP_SRC_CLI_IO_STRING_PARSERS_LISTMODIFICATORPARSER_H_

#include <map>
#include <string>
#include <ListModifier.h>

namespace list_modifier_parser {
  namespace modifiers_map {
    static std::map<std::string, ListModifier> create() {
      std::map<std::string, ListModifier> types;
      types["all"] = ListModifier::ALL;
      types["price_sorted"] = ListModifier::PRICE_SORTED;
      types["price_range"] = ListModifier::PRICE_RANGE;
      types["by_type"] = ListModifier::BY_TYPE;

      return types;
    }
  }

  static ListModifier Parse(std::string&& string) {
    auto types_map = modifiers_map::create();
    if(types_map.find(string) == types_map.end()) return ListModifier::UNKNOWN;

    return types_map[string];
  }
}

#endif //COMPSHOP_SRC_CLI_IO_STRING_PARSERS_LISTMODIFICATORPARSER_H_
