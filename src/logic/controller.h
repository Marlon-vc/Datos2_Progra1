#ifndef APP_CONTROLLER
#define APP_CONTROLLER

#include <gtkmm-3.0/gtkmm/application.h>
#include "../gui/mode_select.h"
#include "../gui/pagination.h"
#include "../gui/infinite_scroll.h"

class Controller {
    public:
        void init();
        static Controller &getInstance();
        void setModeWindow(ModeSelect &window);
        void setPaginationWindow(Pagination &window);
        void setScrollWindow(InfiniteScroll &window);
        Controller(Controller const&) = delete;
        void operator=(Controller const&) = delete;
    private:
        Controller();
        ModeSelect &selectWindow;
        Pagination &paginationWindow;
        InfiniteScroll &scrollWindow;
        void openWindow(int control_flag);
        void modeSelectWindow();
};

#endif