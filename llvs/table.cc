//
// Created by gd on 2018/11/25.
//

#include "table.h"
#include <string>

namespace llvs {

void Table::Insert(std::map<std::string, std::string> entry) {
  entries.push_back(entry);
}

void Table::SetSchema(std::vector<std::string> inputs, std::vector<std::string> outputs) {
  this->inputs = inputs;
  this->outputs = outputs;
}

void Table::Print() {
  printf("| pri | ");
  for (auto i = this->inputs.begin(); i != this->inputs.end(); ++i) {
    printf(" %s |", (*i).c_str());
  }
  for (auto i = this->outputs.begin(); i != this->outputs.end(); ++i) {
    printf(" %s |", (*i).c_str());
  }
  printf("\n");
  for (auto i = this->entries.begin(); i != this->entries.end(); ++i) {
    printf("| %s |", (*i).find("pri")->second.c_str());
    for (auto j = this->inputs.begin(); j != this->inputs.end(); ++j) {
      printf(" %s |", (*i).find((*j))->second.c_str());
    }
    for (auto j = this->outputs.begin(); j != this->outputs.end(); ++j) {
      printf(" %s |", (*i).find((*j))->second.c_str());
    }
  }
}

}
