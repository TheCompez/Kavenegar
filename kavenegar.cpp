#include "kavenegar.hpp"
#include "webservice/networkrequest.hpp"

namespace Kavenegar {

  KavenegarApi::KavenegarApi(const Method &method, const std::string &senderLine, const std::string &apiKey)
    : m_method(method), m_senderLine(senderLine), m_apiKey(apiKey)
  {
    //ToDo...
  }

  KavenegarApi::~KavenegarApi()
  {
  }

  std::string KavenegarApi::apiKey() const
  {
    return m_apiKey;
  }

  void KavenegarApi::send(const std::string &receptor, const std::string &message)
  {

    WebService::NetworkRequest req;
    {

      std::string query = "senderLine="
          + m_senderLine
          + "&receptor="
          + receptor
          + "&message="
          + message;

      std::string url { "https://api.kavenegar.com/v1/"
            + apiKey() + "/sms/send?receptor="
            + receptor + "&sender="
            + m_senderLine
            + "&message="
            + message
       };

      switch (m_method) {
        case Method::GET:
          req.get(url);
          break;
        case Method::POST:
          req.post(url, query);
          break;
        }
    }

  }

}
