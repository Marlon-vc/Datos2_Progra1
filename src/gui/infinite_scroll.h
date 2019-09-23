#ifndef INFINITE_SCROLL_WINDOW
#define INFINITE_SCROLL_WINDOW

#include <gtkmm-3.0/gtkmm/application.h>
#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include <iostream>
#include "../logic/controller.h"

class InfiniteScroll: public Gtk::Window {
    public:
        InfiniteScroll(Controller &c);
        virtual ~InfiniteScroll();
        void run(std::vector<std::string> data);
    private:
        Controller &controller;
        std::vector<std::string> data;
        Gtk::Button openWindow;
};

#endif