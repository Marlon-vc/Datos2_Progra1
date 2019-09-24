#ifndef MODE_WINDOW
#define MODE_WINDOW

#include <gtkmm-3.0/gtkmm/application.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include <gtkmm-3.0/gtkmm/label.h>
#include <gtkmm-3.0/gtkmm/box.h>
#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/image.h>
#include <iostream>

class ModeWindow: public Gtk::Window {
    public:
        ModeWindow();
        virtual ~ModeWindow();
        static void open();
    private:
        Gtk::Button paginationMode, scrollMode, normalMode;
        Gtk::Box modesContainer, container;
        Gtk::Label msg;
        void open_pag();
        void open_scroll();
        void open_normal();
        Glib::RefPtr<Gdk::Pixbuf> load_image(std::string path, int width, int height);
};

#endif