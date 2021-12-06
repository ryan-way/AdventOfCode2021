#include <string>
#include <vector>
#include <sstream>

namespace Parsing
{
  std::vector<int> csvLineToVector(std::string draw);
  template<class T> T fromString(std::string str);
  int getOptionIndex(int argc, const char* argv[], std::string option);
  std::string getCommandLineOption(int argc, const char* argv[], std::string option, std::string def);
  int getCommandLineOption(int argc, const char* argv[], std::string option, int def);
  bool getCommandLineOption(int argc, const char* argv[], std::string option, bool def);
};
