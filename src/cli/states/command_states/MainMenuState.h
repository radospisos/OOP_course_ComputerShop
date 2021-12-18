//
// Created by Rodion Shyshkin on 19.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_STATES_COMMANDSTATES_MAINMENUSTATE_H_
#define COMPSHOP_SRC_CLI_STATES_COMMANDSTATES_MAINMENUSTATE_H_

#include <states/StateInterface.h>
#include <commands/AvailableCommand.h>

class MainMenuState : public StateInterface {
 public:
  MainMenuState();

 public:
  StateResult Run(std::shared_ptr<Context> context) override;
  std::unique_ptr<StateInterface> SwitchState() override;
  StateType GetType() const override;
  bool ReceiveParameters(const std::shared_ptr<IOInterface> &io) override;
  bool Input(const std::shared_ptr<IOInterface> &io) override;
  void Output(const std::shared_ptr<IOInterface> &io) override;

 private:
  Command command_;
};

#endif //COMPSHOP_SRC_CLI_STATES_COMMANDSTATES_MAINMENUSTATE_H_
