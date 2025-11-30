#include "task.h"

namespace fs = std::filesystem;



class FileManager{
  inline static const std::string m_directory = "data";
  inline static const std::string m_filename = "data/tasks.dat";

public:

  static void saveTask(const std::map<int, Task>& tasks);
  static auto loadTasks(int& nextIdToUpdate) -> std::map<int, Task>;
};
