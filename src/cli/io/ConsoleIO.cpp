//
// Created by Rodion Shyshkin on 18.12.2020.
//

#include <iostream>
#include "ConsoleIO.h"

std::string ConsoleIO::input() {
  std::string stringInput;
  std::getline(std::cin, stringInput);
  return stringInput;
}

std::string ConsoleIO::inputCommand() {
  std::cout << ">> ";
  return input();
}

void ConsoleIO::output(const std::string &string) {
  std::cout << string;
}

void ConsoleIO::outputWithBreak(const std::string &string) {
  output(string);
  std::cout << std::endl;
}