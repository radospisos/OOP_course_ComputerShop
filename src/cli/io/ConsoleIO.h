//
// Created by Rodion Shyshkin on 18.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_IO_CONSOLEIO_H_
#define COMPSHOP_SRC_CLI_IO_CONSOLEIO_H_

#include "IOInterface.h"

class ConsoleIO : public IOInterface {
 public:
  std::string     input()                                 override;
  std::string     inputCommand()                          override;
  void            output(const std::string&)              override;
  void            outputWithBreak(const std::string &)    override;
};

#endif //COMPSHOP_SRC_CLI_IO_CONSOLEIO_H_
