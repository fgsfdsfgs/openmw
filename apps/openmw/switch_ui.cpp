#include "switch_ui.hpp"

MainApplication *amain;

LayoutSettings::LayoutSettings() : pu::Layout()
{
    // Create the textblock with the text we want
    this->settingsMenu = new pu::element::Menu(0, 80, 1280, {255,255,255,255}, 10, 6);
    this->settingsMenu->SetScrollbarColor({102,153,204,255});
    // Add the textblock to the layout's element container. IMPORTANT! this MUST be done, having them as members is not enough (just a simple way to keep them)
    this->Add(this->settingsMenu);
    this->SetElementOnFocus(this->settingsMenu);

    pu::element::MenuItem *settings = new pu::element::MenuItem("Start Game");
    settings->AddOnClick([]() { amain->Close(); }, KEY_A);
    this->settingsMenu->AddItem();
}

LayoutSettings::~LayoutSettings() 
{
    delete this->settingsMenu;
}

MainApplication::MainApplication() {
    this->layout1 = new LayoutSettings();
    // Load the layout. In applications layouts are loaded, not added into a container (you don't select a added layout, just load it from this function)
    this->LoadLayout(this->layout1);
}

int main(int argc, char**argv) {

    amain = new MainApplication();
    amain->Show();
    // IMPORTANT! free the application to destroy allocated memory and to finalize graphics.
    delete amain;

    return openmw_main(argc, argv);
}