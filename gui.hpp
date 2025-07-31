#pragma once

#include <gtkmm.h>
#include "gui.hpp"

class Gui : public Gtk::Window{
public:
    Gui();
    ~Gui();

protected:
    void on_button_clicked();

    Gtk::Box box{Gtk::ORIENTATION_VERTICAL, 10};
    //Gtk::Label label;
    Gtk::Button button;
};
