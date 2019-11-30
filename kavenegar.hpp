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

#ifndef KAVENEGAR_HPP
#define KAVENEGAR_HPP

#include <iostream>
#include <exception>
#include <string>

#include "common.hpp"
#include "api.hpp"

namespace Kavenegar {

  /*!
   * \brief The MessageViewType enum
   */
  enum MessageViewType {
    Direct    = 0x0,
    Storage   = 0x1,
    SimCard   = 0x2,
    Software  = 0x3
  };

  /*!
   * \brief The Method enum
   */
  enum class Method {
    POST, GET
  };


  class KAVENEGAR_EXPORT KavenegarApi : public WebService::NetworkRequest
  {
  public:
    KavenegarApi(const Method &method, const std::string &senderLine, const std::string &apiKey);
    ~KavenegarApi();

    /*!
     * \brief apiKey
     * \return
     */
    std::string apiKey() const;

    /*!
     * \brief send function sends message from client to receptor
     * \param receptor
     * \param message
     */
    void send(const std::string &receptor, const std::string &message);

  private:
    Method          m_method;
    std::string     m_senderLine;
    std::string     m_apiKey;
    bool            m_status;
    std::string     m_date;
    MessageViewType m_type;
    std::string     m_localid;

  };

}

#endif // KAVENEGAR_HPP
