/*
  The MIT License (MIT)

  Copyright (c) 2019 Kambiz Asadzadeh

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
 */

#ifndef NETWORKREQUEST_HPP
#define NETWORKREQUEST_HPP

#include "common.hpp"
#include <iostream>
#include <string>
#include <map>
#include <curl/curl.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

/*!
* \brief Network Manager of Curl
*/

namespace WebService {

  template <typename T>
  /**
   * @brief isset function checks any data values.
   * @param t
   * @return bool
   */
  [[maybe_unused]] static auto isset(T t)
  {
    if (const auto it = t; it != T{})
      // on success
      return true;
    else
      // on false...
      return false;
  }


  /**
 * @brief The HttpRowHeader struct
 * @details HTTP headers allow the client and the server to pass additional information with the request or the response.
 *  An HTTP header consists of its case-insensitive name followed by a colon ':', then by its value (without line breaks). Leading white space before the value is ignored.
 */

  struct HttpRowHeader {
  public:

    /*!
     * \brief The HTTP Authorization request header contains the credentials to authenticate a user agent with a server,
     *  usually after the server has responded with a 401 Unauthorized status and the WWW-Authenticate header.
     */
    inline static std::string Authorization = "Authorization";

    /*!
     * \brief USER_AGENT Contains a characteristic string that allows the network protocol peers to identify the application type, operating system,
     *  software vendor or software version of the requesting software user agent.
     */
    inline static std::string USER_AGENT =  "User-Agent";

    /*!
     * \brief The Keep-Alive general header allows the sender to hint about how the connection may be used to set a timeout and a maximum amount of requests.
     */
    inline static std::string KEEP_ALIVE = "Keep-Alive";
  };

  /*!
 * \brief The Http row types is here.
 */
  struct HttpRowTypes {

  public:

    /*!
     * \brief Basic is a common type for Authentication.
     */
    inline static std::string  Basic = "Basic";

  };

  /*!
 * \brief The Content-Type entity header is used to indicate the media type of the resource.
 */
  struct ContentTypeHeader {

  public:

    /*!
     * \brief The Media type of the body of the request (used with POST and PUT requests).
     * Default. All characters are encoded before sent (spaces are converted to "+" symbols, and special characters are converted to ASCII HEX values)
     */
    inline static std::string  APPLICATION_X_WWW_FROM_URLENCODED = "Content-Type: application/x-www-form-urlencoded";

    /*!
     * \brief The MIME type of this content
     * Spaces are converted to "+" symbols, but no special characters are encoded
     */
    inline static std::string  TEXT_HTML = "Content-Type: text/plain";

    /*!
     * \brief The XHtml type of this content
     */
    inline static std::string  APPLICATION_XHTML = "Content-Type: application/xhtml+xml";

    /*!
     * \brief The Xml type of this content
     */
    inline static std::string  APPLICATION_XML = "Content-Type: application/xml";

    /*!
     * \brief The JSon type of this content
     */
    inline static std::string  APPLICATION_JSON = "Content-Type: application/json";


    /*!
     * \brief No characters are encoded.
     * This value is required when you are using forms that have a file upload control.
     */
    inline static std::string  MULTIPART_FROM_DATA =  "Content-Type: multipart/form-data";
  };


  //class NetworkRequest;
  /*!
* \brief NetworkRequest class
*/
  class KAVENEGAR_EXPORT NetworkRequest
  {
  public:

    NetworkRequest  ();  //! NetworkRequest default constructor.
    ~NetworkRequest ();  //! NetworkRequest destructor.

    /*!
     * \brief Authorazation function.
     * \param username
     * \param password
     */
    void setAuthorazation   (const std::string &username, const std::string &password);

    /*!
     * \brief Result function for set result.
     * \param res
     */
    void setResult          (const std::string &res);

    /*!
     * \brief Progress function for set percent of progress
     * \param val
     */
    void setProgress        (const int &val);

    /*!
     * brief WriteCallback : https://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
     * \details This callback function gets called by libcurl as soon as there is data received that needs to be saved.
     * - For most transfers, this callback gets called many times and each invoke delivers another chunk of data.
     * - ptr points to the delivered data, and the size of that data is nmemb; size is always 1.
     * \param contents
     * \param size
     * \param nmemb
     * \param userp
     * \return
     */
    static size_t WriteCallback(char *data, size_t size, size_t nmemb, std::string *buffer);

    /*!
     * \brief The ContentTypes enum
     */
    enum class Headers {
      X_Urlencoded,
      JSon,
      Html,
      XHtml,
      Xml,
      MultiPart
    };

    /*!
     * \brief setContentType
     */
    void setContentType(Headers c);

    /*!
     * \brief The HTTP_METHOD enum
     * \param GET is used to request data from a specified resource.
     * \param POST is used to send data to a server to create/update a resource.
     * \param PUT is used to send data to a server to create/update a resource.
     * \param DELETE_EX method deletes the specified resource.
     * \param HEAD is almost identical to GET, but without the response body.
     * \param OPTIONS method describes the communication options for the target resource.
     * \param PATCH method is a request method supported by the HTTP protocol for making partial changes to an existing resource.
     */
    enum class HTTP_METHOD {
      GET,
      POST,
      PUT,
      DELETE_EX,
      HEAD,
      OPTIONS,
      PATCH
    };

    /*!
     * Message:	Successful Description:
     * 200 OK	The request is OK (this is the standard response for successful HTTP requests)
     * 201 Created	The request has been fulfilled, and a new resource is created
     * 202 Accepted	The request has been accepted for processing, but the processing has not been completed
     * 203 Non-Authoritative Information	The request has been successfully processed, but is returning information that may be from another source
     * 204 No Content	The request has been successfully processed, but is not returning any content
     * 205 Reset Content	The request has been successfully processed, but is not returning any content, and requires that the requester reset the document view
     * 206 Partial Content	The server is delivering only part of the resource due to a range header sent by the client
    */
    enum class HTTP_MESSAGE_SUCCESS {
      OK              = 200,
      Created         = 201,
      Accepted        = 202,
      Non_AI          = 203,
      No_Content      = 204,
      Reset_Content   = 205,
      Partial_Content = 206
    };

    /*!
     * Message:	Redirection Description:
     * 300 Multiple Choices	A link list. The user can select a link and go to that location. Maximum five addresses
     * 301 Moved Permanently	The requested page has moved to a new URL
     * 302 Found	The requested page has moved temporarily to a new URL
     * 303 See Other	The requested page can be found under a different URL
     * 304 Not Modified	Indicates the requested page has not been modified since last requested
     * 306 Switch Proxy	No longer used
     * 307 Temporary Redirect	The requested page has moved temporarily to a new URL
     * 308 Resume Incomplete	Used in the resumable requests proposal to resume aborted PUT or POST requests
    */
    enum class HTTP_MESSAGE_REDIRECTION {
      MultipleChoices     = 300,
      MovedPermanently    = 301,
      FoundNewUrl         = 302,
      See_Other           = 303,
      Not_Modified        = 304,
      Switch_Proxy        = 306,
      Temporary_Redirect  = 307,
      Resume_Incomplete   = 308
    };

    /*!
     * \brief get method for send request
     * \param url is api uri
     */
    void get(const std::string &url);

    /*!
     * \brief post method for send request
     * \param url is api uri
     * \param query is parameters
     */
    void post(const std::string &url, const std::string &query);

    /*!
     * \brief Returns result of network request.
     * \return result of data.
     */
    std::string getResult();

  private:
    inline static std::string result;

    std::string headerType;

    /*!
     * \brief always cleanup method for End a libcurl easy handle
     */
    void clean();

    /*!
     * \brief global libcurl cleanup
     */
    void cleanGlobal();

  protected:

    CURL        *curl;
    CURLcode    res;
    std::string readBuffer;
    struct curl_slist *ctype_list = nullptr;


  };

} //!WebService

#endif // NETWORKREQUEST_HPP
