
#include "../logic/controller.h"
#include "pagination.h"

Pagination::Pagination(Controller &c): controller(c) {
    show_all_children();
    set_title("Pagination");
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

