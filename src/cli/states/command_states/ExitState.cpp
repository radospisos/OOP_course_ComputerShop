//
// Created by Rodion Shyshkin on 19.12.2020.
//

#include "ExitState.h"

StateResult ExitState::Run(std::shared_ptr<Context> context) {
  Output(context->io_);
  return StateResult::SUCCESS;
}

std::unique_ptr<StateInterface> ExitState::SwitchState() {
  return nullptr;
}

bool ExitState::ReceiveParameters(const std::shared_ptr<IOInterface> &io) {
  return true;
}

bool ExitState::Input(const std::shared_ptr<IOInterface> &io) {
  return true;
}

void ExitState::Output(const std::shared_ptr<IOInterface> &io) {
  io->outputWithBreak("State machine finished.");
}

StateType ExitState::GetType() const {
  return StateType::EXIT_STATE;
}