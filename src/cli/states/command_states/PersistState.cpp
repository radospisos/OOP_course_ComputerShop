//
// Created by Rodion Shyshkin on 19.12.2020.
//

#include <Validator.h>
#include <states/StateFactory.h>
#include "PersistState.h"

PersistState::PersistState(const PersistType &type) {
  type_ = type;
}

StateResult PersistState::Run(std::shared_ptr<Context> context) {
  if(!ReceiveParameters(context->io_)) return StateResult::INCORRECT_INPUT;

  if(PersistType::SAVE == type_) {
    auto result = context->service_->SaveToFile(filepath_);
    if(!result) return StateResult::OPERATION_ERROR;
  }
  else if(PersistType::LOAD == type_) {
    auto result = context->service_->LoadFromFile(filepath_);
    if(!result) return StateResult::OPERATION_ERROR;
  }
  return StateResult::SUCCESS;
}

std::unique_ptr<StateInterface> PersistState::SwitchState() {
  auto newstate = state_factory::Create(command_to_state_type::Convert(Command::MAINMENU));
  return std::move(newstate);
}

bool PersistState::Input(const std::shared_ptr<IOInterface> &io) {
  return true;
}

void PersistState::Output(const std::shared_ptr<IOInterface> &io) {

}

bool PersistState::ReceiveParameters(const std::shared_ptr<IOInterface> &io) {
  io->output("Enter filepath: ");
  filepath_ = io->input();
  return validator::ValidateStringFillness(filepath_);
}

StateType PersistState::GetType() const {
  if(type_ == PersistType::SAVE) return StateType::SAVE_TO_FILE;
  else return StateType::LOAD_FROM_FILE;
}