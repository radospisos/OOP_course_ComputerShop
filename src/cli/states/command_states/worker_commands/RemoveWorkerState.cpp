//
// Created by Rodion Shyshkin on 19.12.2020.
//

#include <states/StateFactory.h>
#include "RemoveWorkerState.h"

StateResult RemoveWorkerState::Run(std::shared_ptr<Context> context) {
  if(context->worker_id_ == 0) throw std::runtime_error("error");

  auto result = context->service_->RemoveWorker(context->worker_id_);
  if(!result) return StateResult::OPERATION_ERROR;

  return StateResult::SUCCESS;
}

bool RemoveWorkerState::ReceiveParameters(const std::shared_ptr<IOInterface> &io) {
  return true;
}

std::unique_ptr<StateInterface> RemoveWorkerState::SwitchState() {
  auto newstate = state_factory::Create(command_to_state_type::Convert(Command::MAINMENU));
  return std::move(newstate);
}

bool RemoveWorkerState::Input(const std::shared_ptr<IOInterface> &io) {
  return true;
}

void RemoveWorkerState::Output(const std::shared_ptr<IOInterface> &io) {

}

StateType RemoveWorkerState::GetType() const {
  return StateType::REMOVE_WORKER;
}