//
// Created by Rodion Shyshkin on 19.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_COMMANDS_AVAILABLECOMMAND_H_
#define COMPSHOP_SRC_CLI_COMMANDS_AVAILABLECOMMAND_H_

#include <states/StateType.h>
#include <set>
#include <map>
#include <commands/Command.h>

namespace available_commands {
  namespace available_commands_map {
    static std::map<StateType, std::set<Command>> create() {
      return {
          {
              StateType::MAIN_MENU,
              {
                  Command::ADDCOMPONENT,
                  Command::ADDWORKER,
                  Command::GETWORKERSLIST,
                  Command::GETCOMPONENTSLIST,
                  Command::SAVE,
                  Command::LOAD,
                  Command::EXIT
              }
          },

          {
              StateType::SHOW_WORKERS_LIST,
              {
                  Command::GETWORKER,
                  Command::REMOVEWORKER,
                  Command::MAINMENU,
                  Command::EXIT
              }
          },

          {
              StateType::SHOW_COMPONENTS_LIST,
              {
                  Command::GETCOMPONENT,
                  Command::MAINMENU,
                  Command::EXIT
              }
          },

          {
              StateType::SHOW_COMPONENT,
              {
                  Command::REMOVECOMPONENT,
                  Command::GETCOMPONENTSLIST,
                  Command::MAINMENU,
                  Command::EXIT
              }
          },

          {
            StateType::SHOW_WORKER,
                {
                  Command::REMOVEWORKER,
                  Command::GETWORKERSLIST,
                  Command::MAINMENU,
                  Command::EXIT
                }
          }
      };
    }
  }

  static bool IsCommandAvailable(const StateType& state_type, const Command& command) {
    auto commands_map = available_commands_map::create();
    if(commands_map.find(state_type) == commands_map.end()) return false;

    auto commands_set = commands_map[state_type];
    if(commands_set.find(command) == commands_set.end()) return false;
    return true;
  }
}

#endif //COMPSHOP_SRC_CLI_COMMANDS_AVAILABLECOMMAND_H_
