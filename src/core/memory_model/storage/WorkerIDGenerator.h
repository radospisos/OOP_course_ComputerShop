//
// Created by Rodion Shyshkin on 13.12.2020.
//

#ifndef COMPSHOP_SRC_CORE_WORKERIDGENERATOR_H_
#define COMPSHOP_SRC_CORE_WORKERIDGENERATOR_H_

class WorkerIDGenerator {
 public:
  WorkerIDGenerator();

 public:
  unsigned int GenerateID();

 private:
  unsigned int ids_amount_;
};

#endif //COMPSHOP_SRC_CORE_WORKERIDGENERATOR_H_
