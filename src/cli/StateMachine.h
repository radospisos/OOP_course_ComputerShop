//
// Created by Rodion Shyshkin on 18.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_STATEMACHINE_H_
#define COMPSHOP_SRC_CLI_STATEMACHINE_H_

#include <states/StateInterface.h>

class StateMachine {
 public:
  static StateMachine create(StateType &&start_state,
                             std::shared_ptr<Context>&& context);

  void execute();

 private:
  StateMachine(StateType&& state, std::shared_ptr<Context>&& context);

 private:
  std::unique_ptr<StateInterface> state_;
  std::shared_ptr<Context> context_;
  StateType start_state_;
};

#endif //COMPSHOP_SRC_CLI_STATEMACHINE_H_
