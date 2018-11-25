//
// Created by gd on 2018/11/25.
//

#ifndef HSP_SRC_PROGRAM_H
#define HSP_SRC_PROGRAM_H

#include <vector>
#include "value.h"

namespace llvs {

class Program {
 public:
  std::vector<llvs::Value*> instructions;
};

}



#endif //HSP_SRC_PROGRAM_H
