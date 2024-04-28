/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#ifndef HTTPPARSER_H_
#define HTTPPARSER_H_

#include <iostream>
#include <map>
#include <string>
#include "HttpRequest.h"
#include "HttpResponse.h"

namespace Q1v {

//Blocking HttpParser
    class HttpParser {
    public:
        HttpParser() {};

        void receiveRequest(std::istream &stream, HttpRequest &request);

        void receiveResponse(std::istream &stream, HttpResponse &response);

        static HttpResponse::HTTP_STATUS parseResponseStatusFromString(const std::string &status);

    private:
        void readWord(std::istream &stream, std::string &word);

        void readHeaders(std::istream &stream, HttpRequest::Headers &headers);

        bool readHeader(std::istream &stream, std::string &name, std::string &value);

        size_t getBodyLen(const HttpRequest::Headers &headers);

        void readBody(std::istream &stream, std::string &body, const size_t bodyLen);
    };

} //namespace Q1v

#endif /* HTTPPARSER_H_ */
