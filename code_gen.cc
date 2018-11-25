//
// Created by gd on 2018/11/25.
//

#include "code_gen.h"
#include "llvs/instructions.h"

llvs::Value *NBlock::genFP(llvs::Value &guard)  {
  printf("block\n");
  for (auto s = statements.begin(); s != statements.end(); ++s) {
    (**s).genFP(guard);
  }

  return NULL;
}

llvs::Value *NBinaryOperator::genFP(llvs::Value &guard) {
  printf("binary %d\n", op);
  switch (op) {
    case TCEQ:
      printf("eq\n");
      break;
  }
}

llvs::Value *NIfStatement::genFP(llvs::Value &guard) {
  llvs::AssignInst *ai = new llvs::AssignInst();
  ai->guard = new llvs::Value(true);
  llvs::Value *g = new llvs::Value(true);
  ai->inputs.push_back(condition.genFP(*g));
  llvs::Value *g1 = new llvs::Value("g1");
  ai->outputs.push_back(g1);
  ai->GenTable();

  trueBlock.genFP(*g1);

  return NULL;
}