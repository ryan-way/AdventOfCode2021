#include <string>

namespace Parsing
{
  template<class T> T fromString(std::string str);
  int getOptionIndex(int argc, const char* argv[], std::string option);
  std::string getCommandLineOption(int argc, const char* argv[], std::string option, std::string def);
  int getCommandLineOption(int argc, const char* argv[], std::string option, int def);
  bool getCommandLineOption(int argc, const char* argv[], std::string option, bool def);
};
