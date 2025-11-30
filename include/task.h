#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <fstream>
#include <filesystem>

struct Task{
  std::string m_title;
  std::string m_description;
  bool m_isDone = false;

  Task(std::string title, std::string description, bool isDone = false)
    :m_title(std::move(title)),
    m_description(std::move(description)),
    m_isDone(isDone)
    {};
};
