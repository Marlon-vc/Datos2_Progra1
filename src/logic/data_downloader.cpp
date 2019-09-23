#include "data_downloader.h"

std::string DataDownloader::download(std::string url) {
    return download(url.c_str());
}

std::string DataDownloader::download(const char *url) {
    CURL *curl;
    CURLcode result;
    std::string readBuffer;
    std::cout << "URL: " << url << "\n"; 

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        std::cout << "Initialized..\n";
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        result = curl_easy_perform(curl);
        //Check for errors
        if (result != CURLE_OK) {
            std::cout << "Failed to download " << url << "\n";
            return "";
        }
        curl_easy_cleanup(curl);
    }

    std::cout << "Download finished..\n";
    return readBuffer;
}

size_t DataDownloader::writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    std::string data = DataDownloader::download("https://www.example.com");
    std::cout << data << std::endl;

    //### Image saving ###//
    // std::ofstream myfile;
    // myfile.open("image2.png");
    // myfile << data;
    // myfile.close();
    return 0;
}
