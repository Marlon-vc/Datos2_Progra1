#include "pagination.hpp"

Pagination::Pagination() {
    set_title("Pagination");
    show_all_children();
}

Pagination::~Pagination() {
    
}

void Pagination::open() {
    auto app = Gtk::Application::create();
    static Pagination window;
    app->run(window);
}

// Code to open a secondary window
// void Pagination::open() {
//     std::cout << "Opening window..\n";
//     InfiniteScroll scroll;
//     std::vector<std::string> data;
//     data.push_back("hello");
//     std::cout << "Waiting window..\n";
//     scroll.run(data);
//     std::cout << "Done with other window..\n";
// }

