#ifndef APP_CONTROLLER
#define APP_CONTROLLER

#include <gtkmm-3.0/gtkmm/application.h>
#include <iostream>

#include "../gui/mode_select.h"
#include "../gui/pagination.h"
#include "../gui/infinite_scroll.h"

class Controller {
    public:
        Controller();
        void init();

    private:
        ModeSelect selectWindow;
        Pagination paginationWindow;
        InfiniteScroll scrollWindow;
        void openWindow(int control_flag);
        void modeSelectWindow();
};

#endif