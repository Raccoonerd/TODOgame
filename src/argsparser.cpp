#include "../include/argsparser.h"

ArgsParser::ArgsParser(int argc, char* argv[]){
  args.reserve(static_cast<size_t>(argc));

  for(int i = 0; i < argc; i++){
    args.emplace_back(argv[i]);
  }
}

void ArgsParser::parse_and_execute(TaskManager& tmgr){
  const std::string command = args[1];

  if (command == "-a" || command == "--add") {
    if(args.size() < 3){
      std::cerr<<"Error: Title is required"<<'\n';
      std::cerr<<R"(Usage: ./todo -a "title" ["description"])"<<'\n';
      return;
    }

    std::string title = args[2];
    std::string description = args.size() > 3 ? args[3] : "";
    tmgr.addTask(title, description);

  } else if(command == "-l" || command == "--list"){
    tmgr.printTasks();

  } else if(command == "-c" || command == "--complete"){
    if(args.size() < 3){
      std::cerr<<"Error: Task number required"<<'\n';
      std::cerr<<"Usage: ./todo -c [task_id]"<<'\n';
      return;
    }

    try {
      int index = std::stoi(args[2]) - 1;
      tmgr.markAsDone(index);
    }
    catch (const std::exception&) {
      std::cerr<<"Error: Invalid task number"<<'\n';
    }

  } else if(command == "-h" || command == "--help"){
    print_help();

  } else if(command == "-r" || command == "--remove"){
    if(args.size() < 3){
      std::cerr<<"Error: Task number required"<<'\n';
      std::cerr<<"Usage: ./todo -r [task_id]"<<'\n';
      return;
    }

    try {
      int index = std::stoi(args[2]) - 1;
      tmgr.removeTask(index);
    }
    catch (const std::exception&) {
      std::cerr<<"Error: Invalid task number"<<'\n';
    }

  } else {
    std::cerr<<"Unknown Command"<<'\n';
    print_help();
  }
}

void ArgsParser::print_help(){
  std::cout<<R"(
================================================
 _____ ___  ____   ___    _     ___ ____ _____ 
|_   _/ _ \|  _ \ / _ \  | |   |_ _/ ___|_   _|
  | || | | | | | | | | | | |    | |\___ \ | |  
  | || |_| | |_| | |_| | | |___ | | ___) || |  
  |_| \___/|____/ \___/  |_____|___|____/ |_|  
================================================
  
  Usage:
    ./todo [option] ...

  Options:
    -a, --add     Add task to list by using this
                  option then type title and
                  description

    -l, --list    Display tasks list

    -c,           Mark task as completed. Need to
    --complete    put id afterwards

    -r, --remove  Remove task by typing id after
                  this option

    -h, --help    Display this page

  Examples:
    ./todo --add "Wash the dishes" "By tomorrow"
    ./todo -a "Call mechanic"
    ./todo -l
    ./todo -r 1
    ./todo -c 2
  )"<<'\n';
}
