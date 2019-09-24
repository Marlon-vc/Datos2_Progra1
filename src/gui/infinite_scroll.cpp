#include "infinite_scroll.hpp"

InfiniteScroll::InfiniteScroll() {
    set_title("Scroll");
}

InfiniteScroll::~InfiniteScroll() {

}

void InfiniteScroll::open() {
    auto app = Gtk::Application::create();
    static InfiniteScroll window;
    app->run(window);
}

