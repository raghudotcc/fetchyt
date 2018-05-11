#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <memory>
#include <sstream>
#include <ostream>
#include <cstdint>
#include <map>
#include <curl/curl.h>
#include "fetchyt.hpp"
#include "util.hpp"



void fetchyt::argCheck(int argc, char** argv) {
	if (argc >= MAX_ARG_COUNT) {
		if (!std::regex_match(argv[1], validUrl)) {
			// TODO(raghu): need to allow provision for options in future
			usage();
			handleExit("Please Enter Valid a URL");
		}
	}
	else {
		usage();
		handleExit("Please enter valid number of arguments");
	}
	// set the url for further access if it is right
	// Here the assumption is argv[1] is always the URL
	setUrl(argv[1]);
}

void fetchyt::handleExit(const std::string& message) {
	const std::string suggestion = "Suggestion: " + message + "\n";
	std::cout << suggestion;
	std::exit(EXIT_FAILURE);
}

// Snips out video id out of given url
void fetchyt::parseVideoId(const std::string& url) {
	const std::string querySymbol("\"?&/<%=");
   Util *util = Util::getInstance();
	if (url.find("youtube") != std::string::npos ||
    util->manyInOne(url, querySymbol)) {
		// this means we can go ahead and parse the content after www.youtube.com/
		std::smatch videoIdMatch;

		if ((std::regex_search(url, videoIdMatch, validVideoId[0])) ||
			(std::regex_search(url, videoIdMatch, validVideoId[1])) ||
			(std::regex_search(url, videoIdMatch, validVideoId[2]))) {
			setVideoId(videoIdMatch[videoIdMatch.size() - 1].str());
		}
	}
}

// Helper function for downloadVideoInfo to write CURL data to a string
size_t getBody(void* in, size_t size, size_t nmemb, std::string* out) {
	size_t r = size * nmemb;
	out->append((char*)in, r);
	return r;
}

// Downloads video information and populates Raw Query Map for further use
void fetchyt::downloadVideoInfo() {
	const std::string infoUrl = baseInfoUrl + getVideoId();
	std::string videoInfo;
	CURL* curl; // we need not worry about memory management, curl cleanup does it for us
	CURLcode res;
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	if (curl) {
		// do not use this proxy always, use it only when you are accessing it behind firewall
		// TODO(raghu): support options to enter proxy
		// fetchyt --proxy http://web.proxy.in.hpecorp.net:8080 http://youtube/com/get_video_info?video_id=videoId_
		// curl_easy_setopt(curl, CURLOPT_PROXY, "http://web-proxy.in.hpecorp.net:8080");
		curl_easy_setopt(curl, CURLOPT_URL, infoUrl.c_str());

#ifdef SKIP_PEER_VERIFICATION
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
#endif // SKIP_PEER_VERIFICATION
#ifdef SKIP_HOSTNAME_VERIFICATION
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif // SKIP_HOSTNAME_VERIFICATION
		// curl_easy_setopt(curl, CURLOPT_ENCODING, "UTF-8");
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getBody);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &videoInfo);

		res = curl_easy_perform(curl);
		if (res != CURLE_OK) {
			std::cerr << "Connection Failed." << std::endl
				<< "Traceback: " << curl_easy_strerror(res) << std::endl;
			usage();
			handleExit(curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	setVideoInfo(videoInfo);
  Util *util = Util::getInstance();
	setRawQueryMap(util->tokenizeQuery(getVideoInfo()));
	curl_global_cleanup();
	curl = NULL;
}

// decodes the URL encoded FMT Stream and puts it in a map
void fetchyt::decodeFmtStream() {
	// bad algorithm, not sure what MSVC uses to perform find. From the look of it, it is 
	// normal linear scan. 
	// This could take :
	// O(sizeof take queryMap_ * (sizeof queryMap_ * sizeof urlEncodedFmtStream))
	// TODO(raghu): upgrade the find algorithm with boyre_moore_horspool for efficient parsing/find
	// running the below code n number of rounds so that we are completely devoid of hex encodings. 
	// Main reason is double encoding found in url_encoded_fmt_stream
	const QueryMap& rawQueryMap = getRawQueryMap();
	auto queryIter = rawQueryMap.find("url_encoded_fmt_stream_map");
	std::string urlEncodedFmtStream;
	if (queryIter != rawQueryMap.end()) {
		urlEncodedFmtStream = queryIter->second;
		while (urlEncodedFmtStream.find("%") != std::string::npos) {
			for (auto& dMap : decodeMap) {
				size_t prev = 0, pos;
				while ((pos = urlEncodedFmtStream.find(dMap.first, prev)) != std::string::npos) {
					if (pos > prev) {
						urlEncodedFmtStream.replace(pos, dMap.first.size(), dMap.second);
					}
					prev = pos - 1; // to accomodate same symbol parsing in double encoding. 
									// ex: %2525 --> %.cursor.25, 
									// hence push the cursor one step back so it becomes .cursor.%25
				}
			}
		}
	}
	// TODO(raghu): check if not empty before setting it to map;
	Util *util = Util::getInstance();
	setFmtStreamMap(util->tokenizeQuery(urlEncodedFmtStream));
}

// Our aim is right now to just stick to lower bound
// We won't manage the video quality
// Maybe a thing for future if youtube doesn't change its process
void fetchyt::decodeUrl() {
	std::string url = getUrl();
	Util *util = Util::getInstance();
	parseVideoId(url);
	downloadVideoInfo();
	decodeFmtStream();

	QueryMap fmtStreamMap = getFmtStreamMap();
	for (auto& i : fmtStreamMap)
		std::cout << "&" << i.first << "=" << i.second << std::endl;
}

//	Mutators
void fetchyt::setUrl(const std::string& url) {
	url_ = url;
}

void fetchyt::setVideoId(const std::string& videoId) {
	videoId_ = videoId;
}

void fetchyt::setVideoInfo(const std::string& videoInfo) {
	videoInfo_ = videoInfo;
}

void fetchyt::setRawQueryMap(QueryMap queryMap) {
	rawQueryMap_ = queryMap;
}

void fetchyt::setFmtStreamMap(QueryMap queryMap) {
	urlEncodedFmtStreamMap_ = queryMap;
}

void fetchyt::setDecodedUrl(const std::string& decodedUrl) {
	decodedUrl_ = decodedUrl;
}

// Accessors
std::string fetchyt::getDecodedUrl() {
	// TODO(raghu): return url returned by decodedUrl;
	std::string url = getUrl();
	return url;
}

std::string fetchyt::getUrl() const {
	return url_;
}

std::string fetchyt::getVideoId() const {
	return videoId_;
}

std::string fetchyt::getVideoInfo() const {
	return videoInfo_;
}

QueryMap fetchyt::getRawQueryMap() const {
	return rawQueryMap_;
}

QueryMap fetchyt::getFmtStreamMap() const {
	return urlEncodedFmtStreamMap_;
}
