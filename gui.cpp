#include "gui.hpp"

Gui::Gui(){
    set_title("Passwword Hasher");
    set_default_size(300, 100);

    input.set_placeholder_text("Enter password to hash");

    std::array<std::string, 8> algorithms;
    algorithms[0] = "MD5";
    algorithms[1] = "SHA-256";
    algorithms[2] = "SHA-512";
    algorithms[3] = "SHA-3";
    algorithms[4] = "BLAKE2b";
    algorithms[5] = "Argon2";
    algorithms[6] = "Bcrypt";
    algorithms[7] = "Scrypt";


    for (int i = 0; i < algorithms.size(); i++) {
        hash_algorithm_dropdown.append(algorithms[i]);
    }

    //hash_algorithm_dropdown.append("MD5");
    //hash_algorithm_dropdown.append("SHA-256");
    //hash_algorithm_dropdown.append("SHA-512");
    hash_algorithm_dropdown.set_active(0);

    // Configure button
    button.set_label("Hash");
    button.signal_clicked().connect(sigc::mem_fun(*this, &Gui::on_button_clicked));

    // Add to container in a logical order:
    // Dropdown -> Input -> Button
    box.set_spacing(10); // Add some space between widgets
    box.pack_start(hash_algorithm_dropdown, Gtk::PackOptions::PACK_SHRINK);
    box.pack_start(input);
    box.pack_end(button, Gtk::PackOptions::PACK_SHRINK);

    add(box);

    //label.set_text("Hello, gtkmm!");
    show_all_children();
}

Gui::~Gui(){

}

void Gui::on_button_clicked(){
    // Get the selected hash algorithm from the dropdown
    Glib::ustring selected_algorithm = hash_algorithm_dropdown.get_active_text();

    // Get the text from the input field
    Glib::ustring password_to_hash = input.get_text();
}
