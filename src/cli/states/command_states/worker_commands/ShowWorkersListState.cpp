//
// Created by Rodion Shyshkin on 19.12.2020.
//

#include <io/string_parsers/CommandParser.h>
#include <commands/AvailableCommand.h>
#include <states/StateFactory.h>
#include <Validator.h>
#include <io/string_parsers/WorkersListModifierParser.h>
#include "ShowWorkersListState.h"
#include <iostream>

ShowWorkersListState::ShowWorkersListState() : command_(Command::UNKNOWN) {

}

StateResult ShowWorkersListState::Run(std::shared_ptr<Context> context) {
  context->worker_id_ = 0;
  if(!ReceiveParameters(context->io_)) return StateResult::INCORRECT_INPUT;

  std::vector<WorkerDTO> result;
  if(modifier_ == WorkersListModifier::ALL) {
    result = context->service_->GetAllWorkers();
  }
  else if(modifier_ == WorkersListModifier::SALARY_SORTED) {
    result = context->service_->GetWorkersSortedBySalary();
  }
  else if(modifier_ == WorkersListModifier::BY_NAME) {
    result = context->service_->GetWorkersByName(name_);
  }

  ShowList(result, context->io_);

  Output(context->io_);
  if(!Input(context->io_)) return StateResult::INCORRECT_INPUT;

  return StateResult::SUCCESS;
}

bool ShowWorkersListState::ReceiveParameters(const std::shared_ptr<IOInterface> &io) {
  io->output("Enter list configuration [all/salary_sorted/by_name]: ");
  modifier_ = workers_list_modifier_parser::Parse(std::move(io->input()));
  if(WorkersListModifier::UNKNOWN == modifier_) return false;
  if(WorkersListModifier::BY_NAME == modifier_) {
    io->output("Enter name: ");
    auto name = io->input();
    if(!validator::ValidateStringFillness(name)) return false;
    name_ = name;
  }
  return true;
}

std::unique_ptr<StateInterface> ShowWorkersListState::SwitchState() {
  auto newstate = state_factory::Create(command_to_state_type::Convert(command_));
  return std::move(newstate);
}

bool ShowWorkersListState::Input(const std::shared_ptr<IOInterface> &io) {
  command_ = command_parser::Parse(std::move(io->inputCommand()));
  if(!available_commands::IsCommandAvailable(GetType(), command_)) return false;
  return true;
}

void ShowWorkersListState::Output(const std::shared_ptr<IOInterface> &io) {
  io->outputWithBreak("You can use now: > view_worker, > mm, > exit");
  io->outputWithBreak("Enter a command: ");

}

StateType ShowWorkersListState::GetType() const {
  return StateType::SHOW_WORKERS_LIST;
}

void ShowWorkersListState::ShowList(const std::vector<WorkerDTO> &list,
                                    const std::shared_ptr<IOInterface> &io) {
  if(!list.empty()) {
    for (unsigned int i = 0; i < list.size(); ++i) {
      std::string io_item = "- ID: " + std::to_string(list[i].GetWorkerID());
      io_item += ". Salary: ";
      io_item += std::to_string(list[i].GetSalary());
      io_item += ". Name: ";
      io_item += list[i].GetName();
      io_item += ". Phone number: ";
      io_item += list[i].GetPhoneNumber();
      io->outputWithBreak(io_item);
    }
  } else io->outputWithBreak(" --> No components <--");
}