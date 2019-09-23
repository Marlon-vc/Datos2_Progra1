#ifndef PAGINATION_WINDOW
#define PAGINATION_WINDOW

#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include "../logic/controller.h"

class Pagination: public Gtk::Window {
    public:
        Pagination();
        Pagination(Controller &c);
        virtual ~Pagination();
    private:
        Controller &controller;
        Gtk::Button openWindow;
        void open();
};

#endif