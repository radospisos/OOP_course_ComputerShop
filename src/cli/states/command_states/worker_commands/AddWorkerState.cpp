//
// Created by Rodion Shyshkin on 19.12.2020.
//

#include <Validator.h>
#include <states/StateFactory.h>
#include "AddWorkerState.h"

StateResult AddWorkerState::Run(std::shared_ptr<Context> context) {
  if(!ReceiveParameters(context->io_)) return StateResult::INCORRECT_INPUT;

  auto result = context->service_->AddWorker(dto_);
  if(!result) return StateResult::OPERATION_ERROR;

  return StateResult::SUCCESS;
}

std::unique_ptr<StateInterface> AddWorkerState::SwitchState() {
  auto newstate = state_factory::Create(command_to_state_type::Convert(Command::MAINMENU));
  return std::move(newstate);
}

bool AddWorkerState::Input(const std::shared_ptr<IOInterface> &io) {
  return true;
}

void AddWorkerState::Output(const std::shared_ptr<IOInterface> &io) {

}

bool AddWorkerState::ReceiveParameters(const std::shared_ptr<IOInterface> &io) {
  io->output("Enter worker name: ");
  auto name = io->input();
  if(!validator::ValidateStringFillness(name)) return false;
  io->output("Enter worker phone number (ex.: 0994903865): ");
  auto phone = io->input();
  if(!validator::ValidateStringFillness(phone)) return false;
  io->output("Enter worker salary: ");
  auto salary = validator::ParseNumber(io->input());
  if(!salary.has_value()) return false;

  dto_ = WorkerDTO{name, phone, salary.value(), 0};

  return true;
}

StateType AddWorkerState::GetType() const {
  return StateType::ADD_WORKER;
}