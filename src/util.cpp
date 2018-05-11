#include <vector>
#include <string>
#include <ostream>
#include <sstream>
#include <regex>
#include <cstdlib>
#include <map>
#include "util.hpp"

QueryMap Util::tokenizeQuery(const std::string& query) {
  if (!queryMap_.empty()) {
    queryMap_.clear();
  }
  std::stringstream in(query);
  std::string item;
  while (std::getline(in, item, AMPERSAND_DELIM)) {
    std::size_t prev = 0, pos;
    if ((pos = item.find_first_of(EQUALS_DELIM, prev)) != std::string::npos) {
      if (pos > prev) {
        queryMap_.emplace(item.substr(0, pos), item.substr(pos + 1, item.size()));
      }
    }
  }
  return queryMap_;
}

// A little ugly way
// to find query symbols from url
bool Util::manyInOne(const std::string& src, const std::string& queryStr) {
  bool isPresent = false;
  std::string::const_iterator queryStrIter = queryStr.cbegin();
  for (; queryStrIter != queryStr.cend(); queryStrIter++) {
    if (src.find(*queryStrIter) != std::string::npos) {
      isPresent = true;
    }
  }
  return isPresent;
}







