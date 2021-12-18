//
// Created by Rodion Shyshkin on 13.12.2020.
//

#include "WorkerIDGenerator.h"

WorkerIDGenerator::WorkerIDGenerator() : ids_amount_(0) {}

unsigned int WorkerIDGenerator::GenerateID() { return ++ids_amount_; }