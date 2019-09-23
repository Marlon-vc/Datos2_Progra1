#include "infinite_scroll.h"

InfiniteScroll::InfiniteScroll(Controller &c): openWindow("Click!"), controller(c) {
    set_title("Scroll");
}

InfiniteScroll::~InfiniteScroll() {

}

void InfiniteScroll::run(std::vector<std::string> data) {
    this->data = data;
    std::cout << "Data received: " << data[0] << "\n";
    auto app = Gtk::Application::create();
    app->run(*this);
}
