//
// Created by Rodion Shyshkin on 19.12.2020.
//

#include <states/StateFactory.h>
#include "RemoveComponentState.h"

StateResult RemoveComponentState::Run(std::shared_ptr<Context> context) {
  if(context->component_article_.empty()) throw std::runtime_error("error");

  auto result = context->service_->RemoveComponent(context->component_article_);
  if(!result) return StateResult::OPERATION_ERROR;

  return StateResult::SUCCESS;
}

bool RemoveComponentState::ReceiveParameters(const std::shared_ptr<IOInterface> &io) {
  return true;
}

std::unique_ptr<StateInterface> RemoveComponentState::SwitchState() {
  auto newstate = state_factory::Create(command_to_state_type::Convert(Command::MAINMENU));
  return std::move(newstate);
}

bool RemoveComponentState::Input(const std::shared_ptr<IOInterface> &io) {
  return true;
}

void RemoveComponentState::Output(const std::shared_ptr<IOInterface> &io) {

}

StateType RemoveComponentState::GetType() const {
  return StateType::REMOVE_COMPONENT;
}