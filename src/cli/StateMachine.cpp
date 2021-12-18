//
// Created by Rodion Shyshkin on 18.12.2020.
//

#include <states/StateFactory.h>
#include "StateMachine.h"

StateMachine StateMachine::create(StateType &&start_state, std::shared_ptr<Context>&& context) {
  return StateMachine{std::move(start_state), std::move(context)};
}

StateMachine::StateMachine(StateType&& start_state, std::shared_ptr<Context>&& context)
    :
    context_(context) {
  state_ = state_factory::Create(start_state);
  start_state_ = start_state;
}

void StateMachine::execute() {
  while(state_->GetType() != StateType::EXIT_STATE) {
    auto result = state_->Run(context_);
    if(result == StateResult::SUCCESS) {
      state_ = state_->SwitchState();
    }
    else if(result == StateResult::INCORRECT_INPUT) {
      context_->io_->outputWithBreak("Incorrect input!");
      state_ = state_factory::Create(start_state_);
    }
    else if(result == StateResult::OPERATION_ERROR) {
      context_->io_->outputWithBreak("Operation error!");
      state_ = state_factory::Create(start_state_);
    }
    else throw std::runtime_error("Not all enum is coveraged by if-else in CommandStateMachine.");
  }
}