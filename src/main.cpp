// #include "logic/controller.cpp"
// #include "gui/mode_select.cpp"
// #include "gui/infinite_scroll.cpp"
// #include "gui/normal_window.cpp"

// int main() {
//     Controller *controller = new Controller();
//     controller->init();
//     std::cout << "Done\n";
//     return 0;
// }

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