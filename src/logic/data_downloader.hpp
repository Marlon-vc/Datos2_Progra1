#ifndef DOWNLOADER
#define DOWNLOADER

#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
//#include <myhtml/api.h>
//#include <libxml2/libxml/HTMLparser.h>


class DataDownloader {
    public:
        static std::string download(std::string url);
        static std::string download(const char *url);
    private:
        static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp);
};

#endif