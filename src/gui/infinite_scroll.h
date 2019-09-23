#ifndef INFINITE_SCROLL_WINDOW
#define INFINITE_SCROLL_WINDOW

#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include "../logic/controller.h"

class InfiniteScroll: public Gtk::Window {
    public:
        InfiniteScroll();
        InfiniteScroll(Controller &c);
        virtual ~InfiniteScroll();
    private:
        Controller &controller;
};

#endif