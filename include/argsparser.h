#include "taskmanager.h"
#include <vector>

class ArgsParser{
  std::vector<std::string> args;
  static void print_help();

public:
  ArgsParser(int argc, char* argv[]);

  void parse_and_execute(TaskManager& tmgr);
};
