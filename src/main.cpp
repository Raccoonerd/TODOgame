#include "../include/argsparser.h"

auto main (int argc, char* argv[]) -> int {
  
  TaskManager& tmgr = TaskManager::getInstance();

  ArgsParser argpar(argc, argv);

  argpar.parse_and_execute(tmgr);

  return 0;
}
