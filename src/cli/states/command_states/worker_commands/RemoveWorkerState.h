//
// Created by Rodion Shyshkin on 19.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_STATES_COMMAND_STATES_REMOVEWORKERSTATE_H_
#define COMPSHOP_SRC_CLI_STATES_COMMAND_STATES_REMOVEWORKERSTATE_H_

#include <states/StateInterface.h>

class RemoveWorkerState : public StateInterface {
 public:
  StateResult Run(std::shared_ptr<Context> context) override;
  std::unique_ptr<StateInterface> SwitchState() override;
  StateType GetType() const override;
  bool ReceiveParameters(const std::shared_ptr<IOInterface> &io) override;
  bool Input(const std::shared_ptr<IOInterface> &io) override;
  void Output(const std::shared_ptr<IOInterface> &io) override;
};

#endif //COMPSHOP_SRC_CLI_STATES_COMMAND_STATES_REMOVEWORKERSTATE_H_
