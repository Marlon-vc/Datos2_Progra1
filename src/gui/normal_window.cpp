#include "normal_window.hpp"

NormalWindow::NormalWindow() {
    set_title("No pagination");
}

NormalWindow::~NormalWindow() {
    
}

void NormalWindow::open() {
    auto app = Gtk::Application::create();
    static NormalWindow window;
    app->run(window);
}