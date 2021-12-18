//
// Created by Rodion Shyshkin on 19.12.2020.
//

#include <io/string_parsers/CommandParser.h>
#include <commands/AvailableCommand.h>
#include <states/StateFactory.h>
#include "ShowComponentsListState.h"
#include <Validator.h>
#include <io/string_parsers/ComponentTypeParser.h>
#include <iostream>

ShowComponentsListState::ShowComponentsListState() : command_(Command::UNKNOWN),
                                                    type_(ComponentType::UNKNOWN) {

}

StateResult ShowComponentsListState::Run(std::shared_ptr<Context> context) {
  context->component_article_ = "";
  if(!ReceiveParameters(context->io_)) return StateResult::INCORRECT_INPUT;
 /* context->list_buffer_.modifier_ = modifier_;
  context->list_buffer_.rhs_price_ = rhs_price_;
  context->list_buffer_.lhs_price_ = lhs_price_;
  context->list_buffer_.type_ = type_;*/

  std::vector<ComponentDTO> result;
  if(ListModifier::PRICE_RANGE == modifier_) {
    result = context->service_->GetComponentsInPriceRange(lhs_price_, rhs_price_);
  }
  else if(ListModifier::PRICE_SORTED == modifier_) {
    result = context->service_->GetComponentsSortedByPrice();
  }
  else if(ListModifier::BY_TYPE == modifier_) {
    result = context->service_->GetComponentsByType(type_);
  }
  else if(ListModifier::ALL == modifier_) {
    result = context->service_->GetAllComponents();
  }

  ShowList(result, context->io_);

  Output(context->io_);
  if(!Input(context->io_)) return StateResult::INCORRECT_INPUT;

  return StateResult::SUCCESS;
}

bool ShowComponentsListState::ReceiveParameters(const std::shared_ptr<IOInterface> &io) {
  io->output("Enter list configuration [all/price_sorted/price_range/by_type]: ");
  modifier_ = list_modifier_parser::Parse(std::move(io->input()));
  if(ListModifier::UNKNOWN == modifier_) return false;
  if(ListModifier::PRICE_RANGE == modifier_) {
    io->output("Enter left border of price: ");
    auto lhs = validator::ParseNumber(io->input());
    if(!lhs.has_value()) return false;
    lhs_price_ = lhs.value();
    io->output("Enter right border of price: ");
    auto rhs = validator::ParseNumber(io->input());
    if(!rhs.has_value()) return false;
    if(rhs.value() < lhs_price_) return false;
    rhs_price_ = rhs.value();

  }
  else if(ListModifier::BY_TYPE == modifier_) {
    io->output("Enter component type [cpu/graphics_card/hard_disk/mother_plate/ram]: ");
    auto type = component_type_parser::Parse(std::move(io->input()));
    if(type == ComponentType::UNKNOWN) return false;
    type_ = type;
  }
  return true;
}

std::unique_ptr<StateInterface> ShowComponentsListState::SwitchState() {
  auto newstate = state_factory::Create(command_to_state_type::Convert(command_));
  return std::move(newstate);
}

bool ShowComponentsListState::Input(const std::shared_ptr<IOInterface> &io) {
  command_ = command_parser::Parse(std::move(io->inputCommand()));
  if(!available_commands::IsCommandAvailable(GetType(), command_)) return false;
  return true;
}

void ShowComponentsListState::Output(const std::shared_ptr<IOInterface> &io) {
  io->outputWithBreak("You can use now: > view_component, > mm, > exit");
  io->outputWithBreak("Enter a command: ");

}

StateType ShowComponentsListState::GetType() const {
  return StateType::SHOW_COMPONENTS_LIST;
}

void ShowComponentsListState::ShowList(const std::vector<ComponentDTO>& list,
                                 const std::shared_ptr<IOInterface>& io) {
  if(!list.empty()) {
    for (unsigned int i = 0; i < list.size(); ++i) {
      std::string io_item = "- Component type: " + component_type_parser::ParseToString(list[i].GetComponentType());
      io_item += ". Price: ";
      io_item += std::to_string(list[i].GetPrice());
      io_item += ". Article: ";
      io_item += list[i].GetArticle();
      io->outputWithBreak(io_item);
    }
  } else io->outputWithBreak(" --> No components <--");
}