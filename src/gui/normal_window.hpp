#ifndef NORMAL_WINDOW
#define NORMAL_WINDOW

#include <gtkmm-3.0/gtkmm/window.h>

class NormalWindow: public Gtk::Window {
    public:
        NormalWindow();
        virtual ~NormalWindow();
        static void open();
    private:
};

#endif