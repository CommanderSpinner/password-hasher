#include "gui.hpp"

int main(int argc, char** argv){
    auto app = Gtk::Application::create(argc, argv, "");
    Gui window;
    return app->run(window);
}
