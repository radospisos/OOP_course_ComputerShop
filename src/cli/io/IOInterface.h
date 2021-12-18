//
// Created by Rodion Shyshkin on 18.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_IO_IOINTERFACE_H_
#define COMPSHOP_SRC_CLI_IO_IOINTERFACE_H_

#include <string>

class IOInterface {
 public:
  virtual ~IOInterface() {}

 public:
  virtual std::string input() = 0;
  virtual std::string inputCommand() = 0;
  virtual void output(const std::string&) = 0;
  virtual void outputWithBreak(const std::string&) = 0;
};

#endif //COMPSHOP_SRC_CLI_IO_IOINTERFACE_H_
