#ifndef NORMAL_WINDOW
#define NORMAL_WINDOW

#include <gtkmm-3.0/gtkmm/window.h>
#include "../logic/controller.h"

class NormalWindow: public Gtk::Window {
    public:
        NormalWindow(Controller &c);
        virtual ~NormalWindow();
    private:
        Controller &controller;
};

#endif