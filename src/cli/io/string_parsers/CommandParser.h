//
// Created by Rodion Shyshkin on 19.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_COMMANDS_COMMANDPARSER_H_
#define COMPSHOP_SRC_CLI_COMMANDS_COMMANDPARSER_H_

#include <map>
#include <string>
#include <commands/Command.h>

namespace command_parser {

  namespace commands_map {
    static std::map<std::string, Command> create() {
      std::map<std::string, Command> commands;
      commands["mainmenu"] = Command::MAINMENU;
      commands["mm"] = Command::MAINMENU;
      commands["add_component"] = Command::ADDCOMPONENT;
      commands["add_worker"] = Command::ADDWORKER;
      commands["view_component"] = Command::GETCOMPONENT;
      commands["view_worker"] = Command::GETWORKER;
      commands["show_components"] = Command::GETCOMPONENTSLIST;
      commands["show_workers"] = Command::GETWORKERSLIST;
      commands["remove_component"] = Command::REMOVECOMPONENT;
      commands["remove_worker"] = Command::REMOVEWORKER;
      commands["save"] = Command::SAVE;
      commands["load"] = Command::LOAD;
      commands["exit"] = Command::EXIT;

      return commands;
    }
  }

  static Command Parse(std::string&& string) {
    auto command_map = commands_map::create();
    if(command_map.find(string) == command_map.end()) return Command::UNKNOWN;

    return command_map[string];
  }
}

#endif //COMPSHOP_SRC_CLI_COMMANDS_COMMANDPARSER_H_
