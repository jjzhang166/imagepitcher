#pragma once

struct PostItem {
  PostItem(std::string _name, std::string _sep, std::string _val)
    : name(_name)
    , separator(_sep)
    , value(_val)
  {}

  std::string name;
  std::string separator;
  std::string value;
};

class CHttpPost
{
public:
  CHttpPost(void);
  virtual ~CHttpPost(void);

  void setBoundary(const std::string& _boundary) { boundary_ = _boundary; }
  void setURL(const std::string& _url) { url_ = _url; }
  void setPath(const std::string& _path) { path_ = _path; }
  void setContent(const std::string& _content) { content_ = _content; }
  void setUserAgent(const std::string& _userAgent) { userAgent_ = _userAgent; }
  void setPort(const std::string& _port) { port_ = _port; }
  void addHeader(const std::string& _section, PostItem item);
  void registerSectionSeparator(const std::string& _section, const std::string& _sep);

  bool doPost(void);
  const std::string& getResponse() const { return response_; }

private:
  typedef std::unordered_map<std::string, std::list<PostItem>> headerHash;
  headerHash customHeader_;
  typedef std::unordered_map<std::string, std::string> sectionSepHash;
  sectionSepHash sectionSepHash_;

  boost::asio::io_service io_service_;
  std::string content_;
  std::string url_;
  std::string path_;
  std::string boundary_;
  std::string userAgent_;
  std::string port_;

  std::string response_;
};