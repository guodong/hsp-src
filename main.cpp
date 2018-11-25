#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <llvs/table.h>
#include "node.h"
#include "code_gen.h"

extern NBlock* programBlock;
extern int yyparse();
extern FILE *yyin;

int main(int argc, char* argv[]) {
//  printf("%s", argv[1]);
  FILE *fp = fopen(argv[1], "r");
  if (!fp) {
    printf("cannot open %s\n", argv[1]);
    return -1;
  }
  yyin = fp;
  yyparse();

  fclose(fp);

  CodeGen g;
  g.Generate(*programBlock);

  llvs::Table table;
  std::vector<std::string> inputs;
  std::vector<std::string> outputs;
  inputs.push_back("dstIp");
  inputs.push_back("dstPort");
  inputs.push_back("fwID");
  table.SetSchema(inputs, outputs);
  std::map<std::string, std::string> entry;
  entry["pri"] = "1";
  entry["dstIp"] = "10.10.10.1";
  entry["dstPort"] = "80";
  entry["fwID"] = "2";
  table.Insert(entry);

  table.Print();

  return 0;
}