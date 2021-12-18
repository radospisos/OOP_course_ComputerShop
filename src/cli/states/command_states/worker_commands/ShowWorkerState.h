//
// Created by Rodion Shyshkin on 19.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_STATES_COMMAND_STATES_SHOWWORKERSTATE_H_
#define COMPSHOP_SRC_CLI_STATES_COMMAND_STATES_SHOWWORKERSTATE_H_

#include <states/StateInterface.h>

class ShowWorkerState : public StateInterface {
 public:
  ShowWorkerState();

 public:
  StateResult Run(std::shared_ptr<Context> context) override;
  std::unique_ptr<StateInterface> SwitchState() override;
  StateType GetType() const override;
  bool ReceiveParameters(const std::shared_ptr<IOInterface> &io) override;
  bool Input(const std::shared_ptr<IOInterface> &io) override;
  void Output(const std::shared_ptr<IOInterface> &io) override;

 private:
  void ShowWorker(const WorkerDTO& dto,
                     const std::shared_ptr<IOInterface> &io) const;

 private:
  Command command_;

  unsigned int param_;
};

#endif //COMPSHOP_SRC_CLI_STATES_COMMAND_STATES_SHOWWORKERSTATE_H_
