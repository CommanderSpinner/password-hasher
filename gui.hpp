#pragma once

#include <gtkmm.h>

class Gui : public Gtk::Window{
public:
    Gui();
    ~Gui();

protected:
    void on_button_clicked();

    Gtk::Box box{Gtk::ORIENTATION_VERTICAL, 10};
    Gtk::Button button;
    Gtk::Entry input;
    Gtk::ComboBoxText hash_algorithm_dropdown;
};
