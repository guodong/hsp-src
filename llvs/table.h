//
// Created by gd on 2018/11/25.
//

#ifndef HSP_SRC_TABLE_H
#define HSP_SRC_TABLE_H

#include <map>
#include <vector>

namespace llvs {

class Table {
  std::vector<std::string> inputs;
  std::vector<std::string> outputs;
  std::vector<std::map<std::string, std::string>> entries;

 public:
  void SetSchema(std::vector<std::string> inputs, std::vector<std::string> outputs);
  void Insert(std::map<std::string, std::string> entry);
  void Print();
};

}



#endif //HSP_SRC_TABLE_H
