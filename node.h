//
// Created by gd on 2018/11/25.
//

#ifndef HSP_SRC_NODE_H
#define HSP_SRC_NODE_H

#include <vector>
#include <string>
#include "llvs/value.h"

class NStatement;
class NBlock;

typedef std::vector<NStatement *> StatementList;

class Node {
 public:
  virtual ~Node() {}
  virtual llvs::Value *genFP(llvs::Value&) { return NULL; }

};

class NExpression : public Node {

};

class NStatement : public Node {
};

class NBlock : public Node {
 public:
  StatementList statements;
  NBlock() {}
  llvs::Value *genFP(llvs::Value&);
};

class NIfStatement : public NStatement {
 public:
  NExpression &condition;
  NBlock &trueBlock;
  NBlock &falseBlock;
  int hasElse;

  NIfStatement(NExpression &condition, NBlock &trueBlock)
      : condition(condition), trueBlock(trueBlock), falseBlock(trueBlock) { hasElse = 0; }

  NIfStatement(NExpression &condition, NBlock &trueBlock, NBlock &falseBlock)
      : condition(condition), trueBlock(trueBlock), falseBlock(falseBlock) { hasElse = 1; };

  llvs::Value *genFP(llvs::Value&);
};

class NIdentifier : public NExpression {
 public:
  std::string name;
  NIdentifier(const std::string &name) : name(name) {}
  void genFP() {
    printf("id\n");
  }
};

class NVariableDeclaration : public NStatement {
 public:
  const NIdentifier &type;
  NIdentifier &id;
  NExpression *assignmentExpr;
  NVariableDeclaration(const NIdentifier &type, NIdentifier &id) :
      type(type), id(id) { assignmentExpr = NULL; }
  NVariableDeclaration(const NIdentifier &type, NIdentifier &id, NExpression *assignmentExpr) :
      type(type), id(id), assignmentExpr(assignmentExpr) {};

};

class NInteger : public NExpression {
 public:
  long long value;
  NInteger(long long value) : value(value) {}
  void genFP() {
    printf("int\n");
  }
};

class NAssignment : public NExpression {
 public:
  NIdentifier &lhs;
  NExpression &rhs;
  NAssignment(NIdentifier &lhs, NExpression &rhs) :
      lhs(lhs), rhs(rhs) {};

};

class NBinaryOperator : public NExpression {
 public:
  int op;
  NExpression &lhs;
  NExpression &rhs;
  NBinaryOperator(NExpression &lhs, int op, NExpression &rhs)
      : lhs(lhs), op(op), rhs(rhs) {};

  llvs::Value *genFP(llvs::Value&);
};

#endif //HSP_SRC_NODE_H
