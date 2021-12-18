//
// Created by Rodion Shyshkin on 18.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_CONTEXT_CONTEXT_H_
#define COMPSHOP_SRC_CLI_CONTEXT_CONTEXT_H_

#include <io/IOInterface.h>
#include <api/ServiceInterface.h>
#include "ListModifier.h"
/*
struct ListBuffer {
  ListBuffer() : modifier_(ListModifier::UNKNOWN),
  lhs_price_(0), rhs_price_(0), type_(ComponentType::UNKNOWN) {}

  ListModifier modifier_;
  unsigned int lhs_price_;
  unsigned int rhs_price_;
  ComponentType type_;
};*/

struct Context {
  Context(const std::shared_ptr<ServiceInterface>& service,
          const std::shared_ptr<IOInterface>& io) {
    service_ = service;
    io_ = io;
    component_article_ = "";
    worker_id_ = 0;
  }

  std::string component_article_;
  unsigned int worker_id_;

  std::shared_ptr<ServiceInterface> service_;
  std::shared_ptr<IOInterface> io_;
};

#endif //COMPSHOP_SRC_CLI_CONTEXT_CONTEXT_H_
