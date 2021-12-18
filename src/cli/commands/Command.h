//
// Created by Rodion Shyshkin on 19.12.2020.
//

#ifndef COMPSHOP_SRC_CLI_COMMANDS_COMMAND_H_
#define COMPSHOP_SRC_CLI_COMMANDS_COMMAND_H_

enum class Command {
  UNKNOWN,
  MAINMENU,
  ADDWORKER,
  ADDCOMPONENT,
  GETWORKERSLIST,
  GETWORKER,
  GETCOMPONENTSLIST,
  GETCOMPONENT,
  REMOVECOMPONENT,
  REMOVEWORKER,
  EDIT,
  SAVE,
  LOAD,
  EXIT
};

#endif //COMPSHOP_SRC_CLI_COMMANDS_COMMAND_H_