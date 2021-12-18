//
// Created by Rodion Shyshkin on 19.12.2020.
//

#include <states/StateFactory.h>
#include <io/string_parsers/CommandParser.h>
#include <Validator.h>
#include "ShowWorkerState.h"

ShowWorkerState::ShowWorkerState() : command_(Command::UNKNOWN) {}

StateResult ShowWorkerState::Run(std::shared_ptr<Context> context) {
  if(!ReceiveParameters(context->io_)) return StateResult::INCORRECT_INPUT;

  auto result = context->service_->GetWorker(param_);
  if(!result.has_value()) return StateResult::OPERATION_ERROR;

  ShowWorker(result.value(), context->io_);

  Output(context->io_);
  if(!Input(context->io_)) return StateResult::INCORRECT_INPUT;
  context->worker_id_ = param_;
  return StateResult::SUCCESS;
}

bool ShowWorkerState::ReceiveParameters(const std::shared_ptr<IOInterface> &io) {
  io->output("Enter worker ID: ");
  auto article = validator::ParseNumber(io->input());
  if(!article.has_value()) return false;

  param_ = article.value();
  return true;
}

bool ShowWorkerState::Input(const std::shared_ptr<IOInterface> &io) {
  command_ = command_parser::Parse(std::move(io->inputCommand()));
  if(!available_commands::IsCommandAvailable(GetType(), command_)) return false;
  return true;
}

StateType ShowWorkerState::GetType() const {
  return StateType::SHOW_WORKER;
}

void ShowWorkerState::Output(const std::shared_ptr<IOInterface> &io) {
  io->outputWithBreak("You can use now: > remove_worker, > show_workers, > mm, > exit");
  io->outputWithBreak("Enter a command: ");

}

std::unique_ptr<StateInterface> ShowWorkerState::SwitchState() {
  auto newstate = state_factory::Create(command_to_state_type::Convert(command_));
  return std::move(newstate);
}

void ShowWorkerState::ShowWorker(const WorkerDTO &dto,
                                 const std::shared_ptr<IOInterface> &io) const {
  std::string io_item;
  io_item = "========\nWorker ID:" + std::to_string(dto.GetWorkerID());
  io_item += "\nName: ";
  io_item += dto.GetName();
  io_item += "\nSalary: ";
  io_item += std::to_string(dto.GetSalary());
  io_item += "\nPhone number: ";
  io_item += dto.GetPhoneNumber();
  io_item += "\n========";
  io->outputWithBreak(io_item);
}
