#include <StateMachine.h>
#include <io/ConsoleIO.h>
#include <api/ShopService.h>

int main() {
  std::shared_ptr<Context> context = std::make_shared<Context>(
      std::make_shared<ShopService>(), std::make_shared<ConsoleIO>());
  auto start_state = StateType::MAIN_MENU;
  auto machine = StateMachine::create(std::move(start_state), std::move(context));

  machine.execute();
  return 0;
}
