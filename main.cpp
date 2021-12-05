#include <vector>
#include <iostream>
#include <string>
#include <exception>

template <class T> T fromString(std::string str) {
  if(std::is_same<T, std::string>::value) return str;
  else if(std::is_same<T, int>::value) return stoi(str);
  else throw "Unsupported type";
}

int getOptionIndex(int argc, char* argv[], std::string option) {
  for(int i = 0; i < argc; i ++) {
    std::string target = argv[i];
    if(0 == target.find(option)) {
      return i;
    }
  }
  return -1;
}

std::string getCommandLineOption(int argc, char *argv[], std::string option, std::string def) {
  int index = getOptionIndex(argc, argv, option);
  if(index == -1) return def;
  if(index > argc - 1) throw "Expected Argument for option: " + option;
  return std::string(argv[index+1]);
}

int getCommandLineOption(int argc, char *argv[], std::string option, int def) {
  int index = getOptionIndex(argc, argv, option);
  if(index == -1) return def;
  if(index > argc - 1) throw "Expected Argument for option: " + option;
  return std::stoi(std::string(argv[index+1]));
}

bool getCommandLineOption(int argc, char *argv[], std::string option, bool def) {
  int index = getOptionIndex(argc, argv, option);
  if(index == -1) return def;
  if(index > argc - 1) throw "Expected Argument for option: " + option;
  return true;
}

int main(int argc, char *argv[]) {
  int day  = getCommandLineOption(argc, argv, "-d", 1);
  int part = getCommandLineOption(argc, argv, "-p", 1);
  bool test = getCommandLineOption(argc, argv, "-t", true);
}
