#include "gui/pagination.cpp"
#include "gui/infinite_scroll.cpp"
#include "gui/normal_window.cpp"
#include "gui/mode_select.cpp"


int main() {
    // auto app = Gtk::Application::create("org.tecflix.mode");
    // ModeWindow window;
    // app->run(window);
    ModeWindow::open();
    return 0;
}