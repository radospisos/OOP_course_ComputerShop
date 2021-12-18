//
// Created by Rodion Shyshkin on 19.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_COMMANDS_COMMANDTOSTATETYPE_H_
#define COMPSHOP_SRC_CLI_COMMANDS_COMMANDTOSTATETYPE_H_

#include <states/StateType.h>
#include <commands/Command.h>
#include <map>

namespace command_to_state_type {
  namespace command_state_map {
    static std::map<Command, StateType> create() {
      std::map<Command, StateType> states;

      states[Command::MAINMENU] = StateType::MAIN_MENU;
      states[Command::ADDWORKER] = StateType::ADD_WORKER;
      states[Command::ADDCOMPONENT] = StateType::ADD_COMPONENT;
      states[Command::GETCOMPONENT] = StateType::SHOW_COMPONENT;
      states[Command::GETCOMPONENTSLIST] = StateType::SHOW_COMPONENTS_LIST;
      states[Command::GETWORKERSLIST] = StateType::SHOW_WORKERS_LIST;
      states[Command::GETWORKER] = StateType::SHOW_WORKER;
      states[Command::REMOVEWORKER] = StateType::REMOVE_WORKER;
      states[Command::REMOVECOMPONENT] = StateType::REMOVE_COMPONENT;
      states[Command::SAVE] = StateType::SAVE_TO_FILE;
      states[Command::LOAD] = StateType::LOAD_FROM_FILE;
      states[Command::EXIT] = StateType::EXIT_STATE;

      return states;
    }
  }

  static StateType Convert(const Command& command) {
    auto command_states_map = command_state_map::create();
    if(command_states_map.find(command) == command_states_map.end()) return StateType::UNKNOWN_STATE;

    return command_states_map[command];
  }
}

#endif //COMPSHOP_SRC_CLI_COMMANDS_COMMANDTOSTATETYPE_H_
