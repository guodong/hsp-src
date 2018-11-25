//
// Created by gd on 2018/11/25.
//

#include "instruction.h"
#include "table.h"
namespace llvs {

void Instruction::GenTable() {
  llvs::Table table;
  std::vector<std::string> schemaI;
  std::vector<std::string> schemaO;
  for (auto i = inputs.begin(); i != inputs.end(); ++i) {
    schemaI.push_back((**i).name);
  }
  for (auto i = outputs.begin(); i != outputs.end(); ++i) {
    schemaO.push_back((**i).name);
  }
  table.SetSchema(schemaI, schemaO);
}

}

