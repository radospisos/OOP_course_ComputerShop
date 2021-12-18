#include <iostream>
#include <memory_model/storage/workers/Worker.h>
#include <memory_model/storage/ShopView.h>
#include <memory_model/storage/components/component_types/RAM.h>
#include <StateMachine.h>
#include <io/ConsoleIO.h>
#include <api/ShopService.h>

int main() {
  /*auto k = std::make_unique<ShopStorage>();
  auto k2 = std::make_unique<ShopView>();
  auto k3 = std::make_unique<WorkerIDGenerator>();
  ComponentDTO dto = ComponentDTO::CreateRAM(20, 40);
  auto model = ShopModel{std::move(k), std::move(k2), std::move(k3)};

  std::cout << model.AddComponent(dto);
  std::cout << "Hello, World!" << std::endl;*/


 /* auto k = std::make_unique<ShopModel>();
  auto k2 = WorkerDTO{"ivan", "0994903865", 5000, 1};
  auto res = k->AddWorker(k2);
  std::cout << res << std::endl;
  auto res2 = k->GetAllWorkers();
  std::cout << res2.size() << std::endl;
  auto res3 = k->GetWorker(1);
  std::cout << res3.has_value() << std::endl;*/
/*
  auto k = std::make_unique<ShopStorage>();
  auto k2 = WorkerDTO{"ivan", "0994903865", 5000, 1};
  auto k3 = model_api_utils::ConvertWorkerDTOToEntity(k2, 1);
  k->AddWorker(k3);
  std::cout << k->GetAllWorkers().size() << std::endl;
*/


  std::shared_ptr<Context> context = std::make_shared<Context>(
      std::make_shared<ShopService>(), std::make_shared<ConsoleIO>());
  auto start_state = StateType::MAIN_MENU;
  auto machine = StateMachine::create(std::move(start_state), std::move(context));

  machine.execute();
  return 0;
}
