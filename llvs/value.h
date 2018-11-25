//
// Created by gd on 2018/11/25.
//

#ifndef HSP_SRC_VALUE_H
#define HSP_SRC_VALUE_H

#include <string>

namespace llvs {

class Value {
 public:
  int value;
  std::string str;
  std::string name;

  Value(int value) : value(value) {}
  Value(std::string value) : str(value) {}

};

}

#endif //HSP_SRC_VALUE_H
