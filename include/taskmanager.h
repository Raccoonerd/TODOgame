#include "filemanager.h"

class TaskManager{
  inline static int m_nextId = 0;
  std::map<int,Task> m_tasks;

  TaskManager(){
    m_tasks = FileManager::loadTasks(m_nextId);
  }

public:
  
  ~TaskManager(){
    FileManager::saveTask(m_tasks);
  }

  static auto getInstance() -> TaskManager&{
    static TaskManager instance;
    return instance;
  }

  TaskManager(const TaskManager&) = delete;
  void operator=(const TaskManager&) = delete;

  TaskManager(TaskManager&&) = delete;
  void operator=(TaskManager&&) = delete;


  auto addTask(std::string title, std::string description) -> bool;
  void printTasks() const;
};

