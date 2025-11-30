#include "../include/taskmanager.h"

auto main () -> int {
  
  TaskManager& manager = TaskManager::getInstance();
  
  manager.addTask("Zakupy", "Kupic mleko i chleb");

  manager.printTasks();

  return 0;
}
