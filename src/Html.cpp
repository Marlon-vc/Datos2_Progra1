#include <iostream>
#include <curl/curl.h>
#include <string>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void) {
    CURL *curl;
    CURLcode result;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com/");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        result = curl_easy_perform(curl);
        //Check for errors
        if (result != CURLE_OK) {
            std::cout << "failed\n";
        }
        curl_easy_cleanup(curl);

        std::cout << "result:\n" << readBuffer << "\n";
    }
    return 0;
}
