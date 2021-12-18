//
// Created by Rodion Shyshkin on 19.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_STATES_COMMAND_STATES_SHOWCOMPONENTSTATE_H_
#define COMPSHOP_SRC_CLI_STATES_COMMAND_STATES_SHOWCOMPONENTSTATE_H_

#include <states/StateInterface.h>

class ShowComponentState : public StateInterface {
 public:
  ShowComponentState();

 public:
  StateResult Run(std::shared_ptr<Context> context) override;
  std::unique_ptr<StateInterface> SwitchState() override;
  StateType GetType() const override;
  bool ReceiveParameters(const std::shared_ptr<IOInterface> &io) override;
  bool Input(const std::shared_ptr<IOInterface> &io) override;
  void Output(const std::shared_ptr<IOInterface> &io) override;

 private:
  void ShowComponent(const ComponentDTO& dto,
                     const std::shared_ptr<IOInterface> &io) const;

 private:
  Command command_;

  std::string param_;
};

#endif //COMPSHOP_SRC_CLI_STATES_COMMAND_STATES_SHOWCOMPONENTSTATE_H_
