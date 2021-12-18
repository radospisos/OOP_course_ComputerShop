//
// Created by Rodion Shyshkin on 18.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_STATES_STATEFACTORY_H_
#define COMPSHOP_SRC_CLI_STATES_STATEFACTORY_H_

#include <states/command_states/ExitState.h>
#include <states/command_states/MainMenuState.h>
#include <states/command_states/component_commands/AddComponentState.h>
#include <states/command_states/component_commands/ShowComponentState.h>
#include <states/command_states/component_commands/ShowComponentsListState.h>
#include <states/command_states/component_commands/RemoveComponentState.h>
#include <states/command_states/worker_commands/AddWorkerState.h>
#include <states/command_states/worker_commands/ShowWorkersListState.h>
#include <states/command_states/worker_commands/ShowWorkerState.h>
#include <states/command_states/worker_commands/RemoveWorkerState.h>
#include <states/command_states/PersistState.h>
#include "StateType.h"

namespace state_factory {
  namespace states_map {
    static std::map<StateType, std::unique_ptr<StateInterface>> create() {
      std::map<StateType, std::unique_ptr<StateInterface>> states;
      states[StateType::EXIT_STATE] = std::make_unique<ExitState>();

      states[StateType::MAIN_MENU] = std::make_unique<MainMenuState>();

      states[StateType::ADD_COMPONENT] = std::make_unique<AddComponentState>();
      states[StateType::SHOW_COMPONENTS_LIST] = std::make_unique<ShowComponentsListState>();
      states[StateType::SHOW_COMPONENT] = std::make_unique<ShowComponentState>();
      states[StateType::REMOVE_COMPONENT] = std::make_unique<RemoveComponentState>();

      states[StateType::ADD_WORKER] = std::make_unique<AddWorkerState>();
      states[StateType::SHOW_WORKERS_LIST] = std::make_unique<ShowWorkersListState>();
      states[StateType::SHOW_WORKER] = std::make_unique<ShowWorkerState>();
      states[StateType::REMOVE_WORKER] = std::make_unique<RemoveWorkerState>();

      states[StateType::SAVE_TO_FILE] = std::make_unique<PersistState>(PersistType::SAVE);
      states[StateType::LOAD_FROM_FILE] = std::make_unique<PersistState>(PersistType::LOAD);
      return states;
    }
  }

  static std::unique_ptr<StateInterface> Create(const StateType &type) {
    auto states_map = states_map::create();
    if(states_map.find(type) == states_map.end()) return nullptr;
    return std::move(states_map[type]);
  }
}

#endif //COMPSHOP_SRC_CLI_STATES_STATEFACTORY_H_
