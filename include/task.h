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

  Task(std::string title, std::string description)
    :m_title(std::move(title)),
    m_description(std::move(description)) {};
};
