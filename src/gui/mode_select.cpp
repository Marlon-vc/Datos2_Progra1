#include "mode_select.h"

ModeSelect::ModeSelect(Controller &controller): 
container(Gtk::ORIENTATION_VERTICAL),
modesContainer(Gtk::ORIENTATION_HORIZONTAL), 
msg("Selecciona el modo de la aplicación"), controller(controller) {
    container.pack_start(msg);
    //Set buttons images
    Gtk::Image *img1 = new Gtk::Image(load_image("/home/marlon/TEC/II Semestre 2019/Datos II/Datos2_Progra1/res/steps.png", 50, 50));
    paginationMode.set_image(*img1);
    Gtk::Image *img2 = new Gtk::Image(load_image("/home/marlon/TEC/II Semestre 2019/Datos II/Datos2_Progra1/res/scroll.png", 50, 50));
    scrollMode.set_image(*img2);
    Gtk::Image *img3 = new Gtk::Image(load_image("/home/marlon/TEC/II Semestre 2019/Datos II/Datos2_Progra1/res/sad.png", 50, 50));
    normalMode.set_image(*img3);

    //Set buttons callbacks
    paginationMode.signal_clicked().connect(sigc::mem_fun(*this, &ModeSelect::pag));
    scrollMode.signal_clicked().connect(sigc::mem_fun(*this, &ModeSelect::scroll));
    normalMode.signal_clicked().connect(sigc::mem_fun(*this, &ModeSelect::normal));

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

ModeSelect::~ModeSelect() {}

void ModeSelect::pag() {
    std::cout << "Opening pagination mode\n";
    close();
}

void ModeSelect::scroll() {
    std::cout << "Opening scroll mode\n";
    close();
}

void ModeSelect::normal() {
    std::cout << "Opening normal mode\n";
    close();
}

Glib::RefPtr<Gdk::Pixbuf> ModeSelect::load_image(std::string path, int width, int height) {
    return Gdk::Pixbuf::create_from_file(path, width, height);
}
