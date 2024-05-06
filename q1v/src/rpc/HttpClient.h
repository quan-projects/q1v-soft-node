/**
 * Copyright (c) 2012-2016, The CryptoNote developers, The Bytecoin developers
 * Copyright (c) 2021-2024, The Quan Project developers
 *
 * Complete copyright information can be found in the accompanying LICENSE file
*/

#pragma once

#include <memory>

#include <common/Base64.h>
#include <http/HttpRequest.h>
#include <http/HttpResponse.h>
#include <system/TcpConnection.h>
#include <system/TcpStream.h>
#include "JsonRpc.h"

#include "serialization/SerializationTools.h"

namespace Q1v {

    class ConnectException : public std::runtime_error {
    public:
        ConnectException(const std::string &whatArg);
    };

    class HttpClient {
    public:

        HttpClient(System::Dispatcher &dispatcher, const std::string &address, uint16_t port);

        ~HttpClient();

        void request(const HttpRequest &req, HttpResponse &res);

        bool isConnected() const;

    private:
        void connect();

        void disconnect();

        const std::string m_address;
        const uint16_t m_port;

        bool m_connected = false;
        System::Dispatcher &m_dispatcher;
        System::TcpConnection m_connection;
        std::unique_ptr<System::TcpStreambuf> m_streamBuf;
    };

    template<typename Request, typename Response>
    void invokeJsonCommand(HttpClient &client, const std::string &url, const Request &req, Response &res,
                           const std::string &user = "", const std::string &password = "") {
        HttpRequest hreq;
        HttpResponse hres;

        hreq.addHeader("Content-Type", "application/json");
        if (!user.empty() || !password.empty()) {
            hreq.addHeader("Authorization", "Basic " + Tools::Base64::encode(user + ":" + password));
        }
        hreq.setUrl(url);
        hreq.setBody(storeToJson(req));
        client.request(hreq, hres);

        if (hres.getStatus() != HttpResponse::STATUS_200) {
            throw std::runtime_error("HTTP status: " + std::to_string(hres.getStatus()));
        }

        if (!loadFromJson(res, hres.getBody())) {
            throw std::runtime_error("Failed to parse JSON response");
        }
    }

    template<typename Request, typename Response>
    void invokeJsonRpcCommand(HttpClient &client, const std::string &method, const Request &req, Response &res,
                              const std::string &user = "", const std::string &password = "") {
        try {

            JsonRpc::JsonRpcRequest jsReq;

            jsReq.setMethod(method);
            jsReq.setParams(req);

            HttpRequest httpReq;
            HttpResponse httpRes;

            httpReq.addHeader("Content-Type", "application/json");
            if (!user.empty() || !password.empty()) {
                httpReq.addHeader("Authorization", "Basic " + Tools::Base64::encode(user + ":" + password));
            }
            httpReq.setUrl("/json_rpc");
            httpReq.setBody(jsReq.getBody());

            client.request(httpReq, httpRes);

            JsonRpc::JsonRpcResponse jsRes;

            //if (httpRes.getStatus() == HttpResponse::STATUS_200) {
            jsRes.parse(httpRes.getBody());
            if (!jsRes.getResult(res)) {
                throw std::runtime_error("HTTP status: " + std::to_string(httpRes.getStatus()));
            }
            //}

        } catch (const ConnectException &) {
            throw std::runtime_error("HTTP status: CONNECT_ERROR");
        } catch (const std::exception &) {
            throw std::runtime_error("HTTP status: NETWORK_ERROR");
        }
    }

    template<typename Request, typename Response>
    void invokeBinaryCommand(HttpClient &client, const std::string &url, const Request &req, Response &res,
                             const std::string &user = "", const std::string &password = "") {
        HttpRequest hreq;
        HttpResponse hres;

        if (!user.empty() || !password.empty()) {
            hreq.addHeader("Authorization", "Basic " + Tools::Base64::encode(user + ":" + password));
        }
        hreq.setUrl(url);
        hreq.setBody(storeToBinaryKeyValue(req));
        client.request(hreq, hres);

        if (!loadFromBinaryKeyValue(res, hres.getBody())) {
            throw std::runtime_error("Failed to parse binary response");
        }
    }

}
