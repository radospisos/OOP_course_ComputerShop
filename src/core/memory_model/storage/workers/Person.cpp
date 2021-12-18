//
// Created by Rodion Shyshkin on 13.12.2020.
//

#include "Person.h"

Person::Person(const std::string &name,
               const PhoneNumber &number) :
               name_(name), phone_number_(number) {}

std::string Person::GetName() const { return name_; }

PhoneNumber Person::GetPhoneNumber() const { return phone_number_; }