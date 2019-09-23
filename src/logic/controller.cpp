#include "controller.h"

Controller::Controller() {}

Controller& Controller::getInstance() {
    static Controller instance;
    return instance;
}

void Controller::openWindow(int control_flag) {
    if (control_flag == 1) {
        std::cout << "Opening pagination mode\n";
        auto paginationApp = Gtk::Application::create();
        paginationApp->run(paginationWindow);
    } else if (control_flag == 2) {
        std::cout << "Opening infinite scroll mode\n";
        auto scrollApp = Gtk::Application::create();
        scrollApp->run(scrollWindow);
    } else {
        std::cout << "Opening normal mode\n";
    }
}

void Controller::modeSelectWindow() {
    auto app = Gtk::Application::create();
    app->run(selectWindow);
}

void Controller::init() {
    modeSelectWindow();
}

int main() {
    Controller &controller = Controller::getInstance();
    controller.init();
    return 0;
}