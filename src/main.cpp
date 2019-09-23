#include "logic/controller.h"

int main() {
    Controller &controller = Controller::getInstance();

    ModeSelect modeWindow(controller);
    Pagination paginationWindow(controller);
    InfiniteScroll scrollWindow(controller);
    
    controller.setModeWindow(modeWindow);
    controller.setPaginationWindow(paginationWindow);
    controller.setScrollWindow(scrollWindow);

    controller.init();
}