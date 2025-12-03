#include "../include/taskmanager.h"

auto TaskManager::addTask(std::string title, std::string description) -> bool{
  int m_id = m_nextId;
  
  auto [iter, inserted] = m_tasks.emplace(m_id, Task(std::move(title), std::move(description)));

  if(inserted){
    m_nextId++;
    return true;
  }

  return false;
}

void TaskManager::printTasks() const{
  for (const auto& [tId, task] : m_tasks){
    std::string done = task.m_isDone ? "DONE" : "TODO";
    std::cout<<"("<<tId + 1<<") "<< task.m_title << "\t[" << done << "]" << ":\n" << task.m_description << '\n';
  }
}

auto TaskManager::removeTask(int tId) -> bool{
  size_t removedCount = m_tasks.erase(tId);

  if(removedCount > 0){
    std::cout << "Successfully deleted task! ID: [" << tId + 1<< "]\n";
    FileManager::saveTask(m_tasks);
    return true;
  }  

  std::cout << "Could not delete task! ID: [" << tId + 1 << "]\n";
  return false;
}

auto TaskManager::markAsDone(int tId) -> bool{
  auto task = m_tasks.find(tId);

  if(task != m_tasks.end()){
    task->second.m_isDone = !task->second.m_isDone;
    return true;
  }
  
  return false;
}
