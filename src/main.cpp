#include <iostream>
#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <memory>
#include <sstream>
#include <ostream>
#include <cstdint>
#include <map>
#include "curl/curl.h"
#include "fetchyt.hpp"
#include "util.hpp"

Util *Util::util_ = NULL;

int main(int argc, char **argv) {
  fetchyt fetchyt;
  std::string url;

  fetchyt.argCheck(argc, argv);
  url = argv[1];
  fetchyt.decodeUrl();

  std::cin.get();

  Util *util = Util::getInstance();
  util->cleanupInstance(); // we don't want the singleton to leak memory
  return 0;
}

