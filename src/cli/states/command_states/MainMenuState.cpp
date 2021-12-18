//
// Created by Rodion Shyshkin on 19.12.2020.
//

#include <io/string_parsers/CommandParser.h>
#include <commands/CommandToStateType.h>
#include <states/StateFactory.h>
#include "MainMenuState.h"

MainMenuState::MainMenuState() : command_(Command::UNKNOWN) {

}

StateResult MainMenuState::Run(std::shared_ptr<Context> context) {
  context->component_article_ = "";
  context->worker_id_ = 0;
  Output(context->io_);
  if(!Input(context->io_)) return StateResult::INCORRECT_INPUT;

  return StateResult::SUCCESS;
}

bool MainMenuState::Input(const std::shared_ptr<IOInterface> &io) {
  command_ = command_parser::Parse(std::move(io->inputCommand()));
  if(!available_commands::IsCommandAvailable(GetType(), command_)) return false;
  return true;
}

void MainMenuState::Output(const std::shared_ptr<IOInterface> &io) {
  io->outputWithBreak("You can use now: > add_worker, > show_workers, "
                      "> add_component, > show_components, > save, > load, > exit");
  io->outputWithBreak("Enter a command: ");

}

bool MainMenuState::ReceiveParameters(const std::shared_ptr<IOInterface> &io) {
  return true;
}

std::unique_ptr<StateInterface> MainMenuState::SwitchState() {
  auto newstate = state_factory::Create(command_to_state_type::Convert(command_));
  return std::move(newstate);
}

StateType MainMenuState::GetType() const {
  return StateType::MAIN_MENU;
}