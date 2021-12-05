#include "parsing.h"

int Parsing::getOptionIndex(int argc, const char* argv[], std::string option) {
  for(int i = 0; i < argc; i ++) {
    std::string target = argv[i];
    if(std::string::npos != target.find(option)) {
      return i;
    }
  }
  return -1;
}

std::string Parsing::getCommandLineOption(int argc, const char *argv[], std::string option, std::string def) {
  int index = getOptionIndex(argc, argv, option);
  if(index == -1) return def;
  if(index > argc - 1) throw "Expected Argument for option: " + option;
  return std::string(argv[index+1]);
}

int Parsing::getCommandLineOption(int argc, const char *argv[], std::string option, int def) {
  int index = getOptionIndex(argc, argv, option);
  if(index == -1) return def;
  if(index > argc - 1) throw "Expected Argument for option: " + option;
  return std::stoi(std::string(argv[index+1]));
}

bool Parsing::getCommandLineOption(int argc, const char *argv[], std::string option, bool def) {
  int index = getOptionIndex(argc, argv, option);
  if(index == -1) return def;
  return true;
}
