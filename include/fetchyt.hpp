#ifndef __fetchyt_HPP__
#define __fetchyt_HPP__

using QueryMap = std::multimap<std::string, std::string>;
using RawMap = std::map<std::string, std::string>;
const std::size_t MAX_ARG_COUNT = 2;
const std::regex validUrl("^(http:\\/\\/www\\.|https:\\/\\/www\\.|http:\\/\\/|https:\\/\\/)?[a-z0-9]+([\\-\\.]{1}[a-z0-9]+)*\\.[a-z]{2,5}(:[0-9]{1,5})?(\\/.*)?$");
const std::vector<std::regex> validVideoId {
  std::regex("(?:v|embed|watch\?v)(?:=|\\/)([^\"&?/=%]{11})"),
  std::regex("(?:=|/)([^\"&?/=%]{11})"),
  std::regex("([^\"&?/=%]{11})")
};
const std::string baseInfoUrl = "http://youtube.com/get_video_info?video_id=";
const RawMap decodeMap =
{
  { "%21", "!" },
  { "%22", "\"" },
  { "%23", "#" },
  { "%24", "$" },
  { "%25", "%" },
  { "%26", "&" },
  { "%27", "'" },
  { "%28", "(" },
  { "%29", ")" },
  { "%2A", "*" },
  { "%2B", "+" },
  { "%2C", "," },
  { "%2D", "-" },
  { "%2E", "." },
  { "%2F", "/" },
  { "%3A", ":" },
  { "%3B", ";" },
  { "%3C", "<" },
  { "%3D", "=" },
  { "%3E", ">" },
  { "%3F", "?" },
  { "%40", "@" },
  { "%5B", "[" },
  { "%5C", "\\" },
  { "%5D", "]" },
  { "%5E", "^" },
  { "%5F", "_" },
  { "%60", "`" },
  { "%7B", "{" },
  { "%7C", "|" },
  { "%7D", "}" },
  { "%7E", "~" }
};

const RawMap encodeMap =
{
  { "!" , "%21" },
  { "\"", "%22" },
  { "#" , "%23" },
  { "$" , "%24" },
  { "'" , "%27" },
  { "(" , "%28" },
  { ")" , "%29" },
  { "*" , "%2A" },
  { "+" , "%2B" },
  { "," , "%2C" },
  { ";" , "%3B" },
  { "<" , "%3C" },
  { ">" , "%3E" },
  { "@" , "%40" },
  { "[" , "%5B" },
  { "\\", "%5C" },
  { "]" , "%5D" },
  { "^" , "%5E" },
  { "_" , "%5F" },
  { "`" , "%60" },
  { "{" , "%7B" },
  { "|" , "%7C" },
  { "}" , "%7D" },
  { "~" , "%7E" }
};

class fetchyt {
 public:
  void argCheck(int argc, char** argv);
  void decodeFmtStream();
  void handleExit(const std::string& message);
  void parseVideoId(const std::string& url);
  void downloadVideoInfo();
  void decodeUrl();
  //size_t getBody(void* in, size_t size, size_t nmemb, std::string* out);
  //mutators
  void setUrl(const std::string& url);
  void setVideoId(const std::string& videoId);
  void setVideoInfo(const std::string& videoInfo);
  void setFmtStreamMap(QueryMap queryMap);
  void setRawQueryMap(QueryMap queryMap);
  void setDecodedUrl(const std::string& decodedUrl);
  // Accessors 
  std::string getDecodedUrl();
  std::string getUrl() const;
  std::string getVideoId() const;
  std::string getVideoInfo() const;
  QueryMap getRawQueryMap() const;
  QueryMap getFmtStreamMap() const;
private:
  inline void usage() { std::cout << "Usage: fetchyt <video-url> [video-url...]\n"; std::cin.get(); }
  // data members
  std::string url_;
  std::string videoId_;
  std::string videoInfo_;
  std::string decodedUrl_;
  QueryMap rawQueryMap_;
  QueryMap urlEncodedFmtStreamMap_;
};

#endif // __fetchyt_HPP__
