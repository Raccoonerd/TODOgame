#include "../include/taskmanager.h"

auto main () -> int {
  
  TaskManager& manager = TaskManager::getInstance();
  
  manager.addTask("Task", "Description");

  manager.addTask("Hello", "World");

  manager.printTasks();

  manager.removeTask(0);

  manager.markAsDone(1);

  manager.printTasks();

  return 0;
}
