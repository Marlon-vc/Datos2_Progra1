#include "mode_select.hpp"

ModeWindow::ModeWindow():
container(Gtk::ORIENTATION_VERTICAL),
modesContainer(Gtk::ORIENTATION_HORIZONTAL),
msg("Selecciona el modo de la aplicación") {
    container.pack_start(msg);
    //Set buttons images
    static Gtk::Image img1 = Gtk::Image(load_image("/home/marlon/TEC/II Semestre 2019/Datos II/Datos2_Progra1/res/steps.png", 50, 50));
    paginationMode.set_image(img1);
    static Gtk::Image img2 = Gtk::Image(load_image("/home/marlon/TEC/II Semestre 2019/Datos II/Datos2_Progra1/res/scroll.png", 50, 50));
    scrollMode.set_image(img2);
    static Gtk::Image img3 = Gtk::Image(load_image("/home/marlon/TEC/II Semestre 2019/Datos II/Datos2_Progra1/res/sad.png", 50, 50));
    normalMode.set_image(img3);

    //Set buttons callbacks
    paginationMode.signal_clicked().connect(sigc::mem_fun(*this, &ModeWindow::open_pag));
    scrollMode.signal_clicked().connect(sigc::mem_fun(*this, &ModeWindow::open_scroll));
    normalMode.signal_clicked().connect(sigc::mem_fun(*this, &ModeWindow::open_normal));

    modesContainer.pack_start(paginationMode);
    modesContainer.pack_start(scrollMode);
    modesContainer.pack_start(normalMode);
    container.pack_start(modesContainer);
    add(container);
    show_all_children();
    set_title("Selección de modo");
    set_default_size(300, 150);
    set_resizable(false);

}

ModeWindow::~ModeWindow() {

}

void ModeWindow::open_pag() {
    std::cout << "Opening pagination window\n";
    close();
    Pagination::open();
}

void ModeWindow::open_scroll() {
    std::cout << "Opening scroll window\n";
    close();
    InfiniteScroll::open();
}

void ModeWindow::open_normal() {
    std::cout << "Opening normal window\n";
    close();
    NormalWindow::open();
}

Glib::RefPtr<Gdk::Pixbuf> ModeWindow::load_image(std::string path, int width, int height) {
    return Gdk::Pixbuf::create_from_file(path, width, height);
}

void ModeWindow::open() {
    auto app = Gtk::Application::create("org.tecflix.mode");
    static ModeWindow window;
    app->run(window);
}