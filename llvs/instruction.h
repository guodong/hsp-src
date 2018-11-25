//
// Created by gd on 2018/11/25.
//

#ifndef HSP_SRC_INSTRUCTION_H
#define HSP_SRC_INSTRUCTION_H

#include <vector>
#include "value.h"

namespace llvs {

class Instruction {
 public:
  std::vector<llvs::Value*> inputs;
  std::vector<llvs::Value*> outputs;
  void *table;
  Value *guard;
  void GenTable();
};

}

#endif //HSP_SRC_INSTRUCTION_H
