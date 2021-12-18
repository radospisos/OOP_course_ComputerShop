//
// Created by Rodion Shyshkin on 18.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_STATES_STATEINTERFACE_H_
#define COMPSHOP_SRC_CLI_STATES_STATEINTERFACE_H_

#include <memory>
#include <set>
#include <Context.h>
#include <states/StateType.h>
#include <states/StateResult.h>
#include <commands/CommandToStateType.h>

class StateInterface {
 public:
  virtual ~StateInterface() = default;

 public:
  virtual StateResult                         Run(std::shared_ptr<Context> context) = 0;
  virtual std::unique_ptr<StateInterface>     SwitchState() = 0;
  virtual StateType                           GetType() const = 0;
  virtual bool ReceiveParameters(const std::shared_ptr<IOInterface> &io) = 0;
  virtual bool                                Input(const std::shared_ptr<IOInterface> &io) = 0;
  virtual void                                Output(const std::shared_ptr<IOInterface> &io) = 0;
};

#endif //COMPSHOP_SRC_CLI_STATES_STATEINTERFACE_H_
