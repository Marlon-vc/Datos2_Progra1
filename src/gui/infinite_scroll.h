#ifndef INFINITE_SCROLL_WINDOW
#define INFINITE_SCROLL_WINDOW

#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/button.h>

class Controller;

class InfiniteScroll: public Gtk::Window {
    public:
        InfiniteScroll();
        virtual ~InfiniteScroll();
        static void open();
    private:
};

#endif