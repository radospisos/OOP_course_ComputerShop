//
// Created by Rodion Shyshkin on 19.12.2020.
//

#include <commands/AvailableCommand.h>
#include <io/string_parsers/CommandParser.h>
#include <states/StateFactory.h>
#include <Validator.h>
#include <io/string_parsers/ComponentTypeParser.h>
#include "ShowComponentState.h"

ShowComponentState::ShowComponentState() : command_(Command::UNKNOWN) {

}

StateResult ShowComponentState::Run(std::shared_ptr<Context> context) {
  if(!ReceiveParameters(context->io_)) return StateResult::INCORRECT_INPUT;

  auto result = context->service_->GetComponent(std::move(param_));
  if(!result.has_value()) return StateResult::OPERATION_ERROR;

  ShowComponent(result.value(), context->io_);

  Output(context->io_);
  if(!Input(context->io_)) return StateResult::INCORRECT_INPUT;
  context->component_article_ = param_;
  return StateResult::SUCCESS;
}

bool ShowComponentState::ReceiveParameters(const std::shared_ptr<IOInterface> &io) {
  io->output("Enter article: ");
  auto article = io->input();
  if(!validator::ValidateStringFillness(article)) return false;

  param_ = article;
  return true;
}

std::unique_ptr<StateInterface> ShowComponentState::SwitchState() {
  auto newstate = state_factory::Create(command_to_state_type::Convert(command_));
  return std::move(newstate);
}

bool ShowComponentState::Input(const std::shared_ptr<IOInterface> &io) {
  command_ = command_parser::Parse(std::move(io->inputCommand()));
  if(!available_commands::IsCommandAvailable(GetType(), command_)) return false;
  return true;
}

void ShowComponentState::Output(const std::shared_ptr<IOInterface> &io) {
  io->outputWithBreak("You can use now: > remove_component, > show_components, > mm, > exit");
  io->outputWithBreak("Enter a command: ");

}

StateType ShowComponentState::GetType() const {
  return StateType::SHOW_COMPONENT;
}

void ShowComponentState::ShowComponent(const ComponentDTO &dto,
                                       const std::shared_ptr<IOInterface> &io) const {
  std::string io_item;
  io_item = "========\nArticle: " + dto.GetArticle() + "\nComponent type: ";
  io_item += component_type_parser::ParseToString(dto.GetComponentType());
  io_item += "\nPrice: ";
  io_item += std::to_string(dto.GetPrice());
  if(dto.GetMemoryCapacity().has_value()) {
    io_item += "\nMemory Capacity: ";
    io_item += std::to_string(dto.GetMemoryCapacity().value());
  }
  if(dto.GetFrequency().has_value()) {
    io_item += "\nFrequency: ";
    io_item += std::to_string(dto.GetFrequency().value());
  }
  if(dto.GetMinimalFrequency().has_value()) {
    io_item += "\nMinimal frequency: ";
    io_item += std::to_string(dto.GetMinimalFrequency().value());
  }
  if(dto.GetMaximalFrequency().has_value()) {
    io_item += "\nMaximal frequency: ";
    io_item += std::to_string(dto.GetMaximalFrequency().value());
  }
  if(dto.GetCoresNumber().has_value()) {
    io_item += "\nCores amount: ";
    io_item += std::to_string(dto.GetCoresNumber().value());
  }
  if(dto.GetCoolerFlag().has_value()) {
    io_item += "\nCooler presence: ";
    if(dto.GetCoolerFlag().value()) io_item += "yes";
    else io_item += "no";
  }
  if(dto.GetMaxRam().has_value()) {
    io_item += "\nMaximal RAM capacity: ";
    io_item += std::to_string(dto.GetMaxRam().value());
  }
  if(dto.GetSocket().has_value()) {
    io_item += "\nSocket: ";
    io_item += dto.GetSocket().value();
  }
  if(dto.GetCapacity().has_value()) {
    io_item += "\nCapacity: ";
    io_item += std::to_string(dto.GetCapacity().value());
  }
  if(dto.GetTurnsPerMinute().has_value()) {
    io_item += "\nTurns per minute: ";
    io_item += std::to_string(dto.GetTurnsPerMinute().value());
  }
  if(dto.GetSSDFlag().has_value()) {
    io_item += "\nHard Disk type: ";
    if(dto.GetSSDFlag().value()) io_item += "SSD";
    else io_item += "HHD";
  }
  if(dto.GetCoreFrequency().has_value()) {
    io_item += "\nCore frequency: ";
    io_item += std::to_string(dto.GetCoreFrequency().value());
  }
  if(dto.GetMemoryFrequency().has_value()) {
    io_item += "\nMemory frequency: ";
    io_item += std::to_string(dto.GetMemoryFrequency().value());
  }
  if(dto.GetDisplayPortsNum().has_value()) {
    io_item += "\nAmount of display ports: ";
    io_item += std::to_string(dto.GetDisplayPortsNum().value());
  }
  io_item += "\n========";
  io->outputWithBreak(io_item);
}