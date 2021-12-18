//
// Created by Rodion Shyshkin on 19.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_STATES_COMMAND_STATES_SHOWCOMPONENTSLISTSTATE_H_
#define COMPSHOP_SRC_CLI_STATES_COMMAND_STATES_SHOWCOMPONENTSLISTSTATE_H_

#include <states/StateInterface.h>
#include <io/string_parsers/ListModifierParser.h>

class ShowComponentsListState : public StateInterface {
 public:
  ShowComponentsListState();

 public:
  StateResult Run(std::shared_ptr<Context> context) override;
  std::unique_ptr<StateInterface> SwitchState() override;
  StateType GetType() const override;
  bool ReceiveParameters(const std::shared_ptr<IOInterface> &io) override;
  bool Input(const std::shared_ptr<IOInterface> &io) override;
  void Output(const std::shared_ptr<IOInterface> &io) override;

 private:
  void ShowList(const std::vector<ComponentDTO>& list,
                const std::shared_ptr<IOInterface>& io);

 private:
  Command command_;
  ListModifier modifier_;
  unsigned int lhs_price_;
  unsigned int rhs_price_;
  ComponentType type_;
};

#endif //COMPSHOP_SRC_CLI_STATES_COMMAND_STATES_SHOWCOMPONENTSLISTSTATE_H_
