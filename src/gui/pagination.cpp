
#include "../logic/controller.h"
#include "pagination.h"

Pagination::Pagination(Controller &c): openWindow("Click!"), controller(c) {
    openWindow.signal_clicked().connect(sigc::mem_fun(*this, &Pagination::open));
    add(openWindow);
    show_all_children();
    set_title("Pagination");
}

Pagination::~Pagination() {}

void Pagination::open() {
    std::cout << "Hello\n";
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

