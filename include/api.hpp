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

#ifndef API_HPP
#define API_HPP

#include <iostream>
#include <string>

#include "common.hpp"
#include "webservice/networkrequest.hpp"

namespace Kavenegar {

  class KAVENEGAR_EXPORT Api : public WebService::NetworkRequest
  {
  public:
    Api();
    ~Api();

    /*!
     * \brief The State enum
     */
    enum State { ESCAPED, UNESCAPED };

    /*!
     * \brief The Normal ReturnCode enum
     * \details : https://kavenegar.com/rest.html
     */
    enum ReturnCode {
      Ret200    = 200, // Number 200 is normal status [Success mode]
      Ret400    = 400,
      Ret401    = 401,
      Ret402    = 402,
      Ret403    = 403,
      Ret404    = 404,
      Ret405    = 405,
      Ret406    = 406,
      Ret407    = 407,
      Ret409    = 409,
      Ret411    = 411,
      Ret412    = 412,
      Ret413    = 413,
      Ret414    = 414,
      Ret415    = 415,
      Ret416    = 416,
      Ret417    = 417,
      Ret418    = 418,
      Ret419    = 419,
      Ret422    = 422,
      Ret424    = 424,
      Ret426    = 426,
      Ret428    = 428,
      Ret431    = 431,
      Ret432    = 432
    };

    /*!
     * \brief whitespace_reduce
     * \param str with reduce string
     * \return
     */
    std::string whitespace_reduce(std::string str);

    /*!
     * \brief whitespace_leading
     * \param str with leading string
     * \return
     */
    std::string whitespace_leading(std::string str);

    /*!
     * \brief escapeJSON
     * \param input for escaping from json template
     * \return
     */
    std::string escapeJSON(const std::string& input);

    /*!
     * \brief unescapeJSON
     * \param input for unscaping json template
     * \return
     */
    std::string unescapeJSON(const std::string& input);

  };

  /*!
   * \brief The ApiException class
   */
  class KAVENEGAR_EXPORT ApiException : private Api {
  public:
    ApiException();
    ~ApiException();

    /*!
     * \brief getMessage function will return message from Kavenegar Server.
     * \return string
     */
    std::string getMessage();

    /*!
     * \brief getCode function will return status code number from Kavenegar Server.
     * \return
     */
    int getCode();

    /*!
     * \brief setMessage
     * \param message
     */
    void setMessage(const std::string &message);

    /*!
     * \brief setCode
     * \param code
     */
    void setCode(const int &code);

  private:
    inline static std::string m_message;
    inline static int m_code;

  };

}

#endif // API_HPP
