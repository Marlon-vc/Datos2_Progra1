#ifndef PAGINATION_WINDOW
#define PAGINATION_WINDOW

#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/button.h>

class Pagination: public Gtk::Window {
    public:
        Pagination();
        virtual ~Pagination();
        static void open();
    private:
};

#endif