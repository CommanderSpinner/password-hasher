#include "gui.hpp"

Gui::Gui(){
    set_title("Passwword Hasher");
    set_default_size(300, 100);

    input.set_placeholder_text("");

    // Configure button
    button.set_label("Click me!");
    button.signal_clicked().connect(sigc::mem_fun(*this, &Gui::on_button_clicked));

    // Add to container
    //box.pack_start(label);
    box.pack_start(input);
    box.pack_start(button);
    add(box);

    //label.set_text("Hello, gtkmm!");
    show_all_children();
}

Gui::~Gui(){

}

void Gui::on_button_clicked(){
}
