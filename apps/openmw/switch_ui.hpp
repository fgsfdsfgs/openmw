#ifndef SWITCH_UI_H
#define SWITCH_UI_H

// Include Plutonium
#include <pu/Plutonium>

// Define your main layout as a class inheriting from pu::Layout
class LayoutSettings : public pu::Layout
{
    public:
        LayoutSettings();
        ~LayoutSettings();
    private:
        // An easy way to keep objects is to have them as private pointer members
        pu::element::Menu *settingsMenu;
};

// Define your application as a class too
class MainApplication : public pu::Application
{
    public:
        MainApplication();
    private:
        // Layout instance
        LayoutSettings *layout1;
};

int openmw_main(int argc, char**argv);

#endif /* SWITCH_UI_H */