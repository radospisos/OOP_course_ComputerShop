//
// Created by Rodion Shyshkin on 19.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_IO_STRING_PARSERS_COMPONENTTYPEPARSER_H_
#define COMPSHOP_SRC_CLI_IO_STRING_PARSERS_COMPONENTTYPEPARSER_H_

#include <memory_model/storage/components/ComponentType.h>
#include <string>
#include <map>

namespace component_type_parser {
  namespace types_map {
    static std::map<std::string, ComponentType> create() {
      std::map<std::string, ComponentType> types;
      types["graphics_card"] = ComponentType::GRAPHICSCARD;
      types["cpu"] = ComponentType::PROCCESSOR;
      types["hard_disk"] = ComponentType::HARDDISK;
      types["mother_plate"] = ComponentType::MOTHERPLATE;
      types["ram"] = ComponentType::RAM;

      return types;
    }
  }

  static ComponentType Parse(std::string&& string) {
    auto types_map = types_map::create();
    if(types_map.find(string) == types_map.end()) return ComponentType::UNKNOWN;

    return types_map[string];
  }

  static std::string ParseToString(const ComponentType& type) {
    if(type == ComponentType::PROCCESSOR) return "CPU";
    else if(type == ComponentType::GRAPHICSCARD) return "Graphics Card";
    else if(type == ComponentType::HARDDISK) return "Hard Disk";
    else if(type == ComponentType::MOTHERPLATE) return "Mother Plate";
    else if(type == ComponentType::RAM) return "RAM";
    else return "unknown";
  }
}

#endif //COMPSHOP_SRC_CLI_IO_STRING_PARSERS_COMPONENTTYPEPARSER_H_
