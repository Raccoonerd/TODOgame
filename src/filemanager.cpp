#include "../include/filemanager.h"

 void FileManager::saveTask(const std::map<int, Task>& tasks) {
  if(!fs::exists(m_directory)){
    fs::create_directory(m_directory);
  }

  std::ofstream file(m_filename);
  if(!file.is_open()){
    std::cerr << "[FileManager] >> Error: Could not open file to save" << '\n';
    return;
  }

  for(const auto& [tId, task] : tasks){
    file<<tId<<";"
      <<task.m_title<<";"
      <<task.m_description<<";"
      <<(task.m_isDone ? 1 : 0)<<'\n';
  }
}

auto FileManager::loadTasks(int& nextIdToUpdate)  -> std::map<int, Task> {
  std::map<int, Task> tasks;
  std::ifstream file(m_filename);

  if(!fs::exists(m_filename)){
    return tasks;
  }

  if(!file.is_open()){
    std::cerr << "[FileManager] >> Error: Could not open file to read" << '\n';
    return tasks;
  }

  std::string line;
  int maxId = -1;
  
  while (std::getline(file, line)) {
    if(line.empty()) { continue; }

    size_t firstSemi = line.find(';');
    size_t secondSemi = line.find(';', firstSemi + 1);
    size_t thirdSemi = line.find(';', secondSemi + 1);

    if(firstSemi  != std::string::npos && 
      secondSemi  != std::string::npos &&
      thirdSemi   != std::string::npos){

      try {
        int tId= std::stoi(line.substr(0, firstSemi));
        std::string title = line.substr(firstSemi + 1, secondSemi - (firstSemi - 1));
        std::string desc = line.substr(secondSemi + 1, thirdSemi - (secondSemi -1));
        bool isDone = (std::stoi(line.substr(thirdSemi + 1)) != 0);

        tasks.emplace(tId, Task(std::move(title), std::move(desc), isDone));

        maxId = std::max(tId, maxId);
      } catch (...) {
        continue;
      }
    }
  }

  nextIdToUpdate = std::max(maxId + 1, 0);

  return tasks;
}
