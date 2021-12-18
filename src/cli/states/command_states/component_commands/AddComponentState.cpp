//
// Created by Rodion Shyshkin on 19.12.2020.
//

#include <io/string_parsers/ComponentTypeParser.h>
#include <Validator.h>
#include <states/StateFactory.h>
#include "AddComponentState.h"

StateResult AddComponentState::Run(std::shared_ptr<Context> context) {
  if(!ReceiveParameters(context->io_)) return StateResult::INCORRECT_INPUT;

  auto result = context->service_->AddComponent(dto_);
  if(!result) return StateResult::OPERATION_ERROR;

  return StateResult::SUCCESS;
}

bool AddComponentState::ReceiveParameters(const std::shared_ptr<IOInterface> &io) {
  io->output("Enter compomnent price: ");
  auto price = validator::ParseNumber(io->input());
  if(!price.has_value()) return false;
  io->output("Enter component type [cpu/graphics_card/hard_disk/mother_plate/ram]: ");
  auto type = component_type_parser::Parse(std::move(io->input()));
  if(type == ComponentType::UNKNOWN) return false;
  if(ComponentType::PROCCESSOR == type) {
    io->output("Enter minimal frequency: ");
    auto minfreq = validator::ParseDoubleNumber(io->input());
    if (!minfreq.has_value()) return false;
    io->output("Enter maximal frequency: ");
    auto maxfreq = validator::ParseDoubleNumber(io->input());
    if (!maxfreq.has_value()) return false;
    io->output("Enter cores amount: ");
    auto coresnum = validator::ParseNumber(io->input());
    if (!coresnum.has_value()) return false;
    io->output("Does it have cooler? [y/n]: ");
    auto cooler = validator::ParseFlag(io->input());
    if (!cooler.has_value()) return false;

    dto_ = ComponentDTO::CreateProcessor(minfreq.value(), maxfreq.value(),
                                         coresnum.value(), cooler.value(), price.value(), "");
  }
  else if(ComponentType::RAM == type) {
    io->output("Enter memory capacity: ");
    auto memcap = validator::ParseNumber(io->input());
    if(!memcap.has_value()) return false;
    io->output("Enter frequency: ");
    auto freq = validator::ParseNumber(io->input());
    if(!freq.has_value()) return false;

    dto_ = ComponentDTO::CreateRAM(memcap.value(), freq.value(), price.value(), "");
  }
  else if(ComponentType::MOTHERPLATE == type) {
    io->output("Enter maximal RAM capacity: ");
    auto maxram = validator::ParseNumber(io->input());
    if(!maxram.has_value()) return false;
    io->output("Enter socket: ");
    auto socket = io->input();
    if(!validator::ValidateStringFillness(socket)) return false;

    dto_ = ComponentDTO::CreateMotherPlate(maxram.value(), socket, price.value(), "");
  }
  else if(ComponentType::HARDDISK == type) {
    io->output("Enter capacity: ");
    auto capac = validator::ParseNumber(io->input());
    if(!capac.has_value()) return false;
    io->output("Enter turns/minute: ");
    auto tpermin = validator::ParseNumber(io->input());
    if(!tpermin.has_value()) return false;
    io->output("Is it SSD? [y/n]: ");
    auto ssdflag = validator::ParseFlag(io->input());
    if(!ssdflag.has_value()) return false;

    dto_ = ComponentDTO::CreateHardDisk(capac.value(), tpermin.value(), ssdflag.value(),
                                        price.value(), "");
  }
  else if(ComponentType::GRAPHICSCARD == type) {
    io->output("Enter memory capacity: ");
    auto capac = validator::ParseNumber(io->input());
    if(!capac.has_value()) return false;
    io->output("Enter core frequency: ");
    auto corefreq = validator::ParseNumber(io->input());
    if(!corefreq.has_value()) return false;
    io->output("Enter memory frequency: ");
    auto memfreq = validator::ParseNumber(io->input());
    if(!memfreq.has_value()) return false;
    io->output("Enter amount of display ports: ");
    auto dpnum = validator::ParseNumber(io->input());
    if(!dpnum.has_value()) return false;

    dto_ = ComponentDTO::CreateGraphicsCard(capac.value(), corefreq.value(),
                                            memfreq.value(), dpnum.value(), price.value(), "");
  }
  else throw std::runtime_error("not full coverage of enum.");
  return true;
}

std::unique_ptr<StateInterface> AddComponentState::SwitchState() {
  auto newstate = state_factory::Create(command_to_state_type::Convert(Command::MAINMENU));
  return std::move(newstate);
}

void AddComponentState::Output(const std::shared_ptr<IOInterface> &io) {

}

bool AddComponentState::Input(const std::shared_ptr<IOInterface> &io) {
  return true;
}

StateType AddComponentState::GetType() const {
  return StateType::ADD_COMPONENT;
}