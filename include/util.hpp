#ifndef __UTIL_HPP__
#define __UTIL_HPP__
#define AMPERSAND_DELIM '&'
#define EQUALS_DELIM '='

using QueryMap = std::multimap<std::string, std::string>;


class Util {
public:
  static Util *getInstance() {
    if (util_ == NULL)  util_ = new Util;
    return util_;
  }
  static void cleanupInstance() {
    delete util_;
    util_ = NULL;
  }
  QueryMap tokenizeQuery(const std::string& query);
  bool manyInOne(const std::string& src, const std::string& query_str);
private:
  static Util* util_;
  QueryMap queryMap_;
};

#endif // __UTIL_HPP__