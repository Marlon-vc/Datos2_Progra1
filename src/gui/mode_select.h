#ifndef MODE_SELECT_WINDOW
#define MODE_SELECT_WINDOW

#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include <gdkmm-3.0/gdkmm/pixbuf.h>
#include <gtkmm-3.0/gtkmm/image.h>
#include <gtkmm-3.0/gtkmm/label.h>
#include <gtkmm-3.0/gtkmm/box.h>
#include <iostream>
#include "../logic/controller.h"

class ModeSelect: public Gtk::Window {
    public:
        ModeSelect(Controller &controller);
        virtual ~ModeSelect();
    private:
        Controller &controller;
        Gtk::Button paginationMode, scrollMode, normalMode;
        Gtk::Box modesContainer, container;
        Gtk::Label msg;
        void pag();
        void scroll();
        void normal();
        Glib::RefPtr<Gdk::Pixbuf> load_image(std::string path, int width, int height);
};

#endif