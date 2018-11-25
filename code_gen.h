//
// Created by gd on 2018/11/25.
//

#ifndef HSP_SRC_CODE_GEN_H
#define HSP_SRC_CODE_GEN_H

#include "node.h"
#include "parser.hh"
#include "llvs/value.h"

class CodeGen {
 public:
  void Generate(NBlock &block) {
    llvs::Value *g = new llvs::Value(true);
    block.genFP(*g);
  }
};


#endif //HSP_SRC_CODE_GEN_H
