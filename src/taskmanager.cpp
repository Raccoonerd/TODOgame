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
    std::cout<<"("<<tId + 1<<")"<< task.m_title << ":\n" << task.m_description << '\n';
  }
}
