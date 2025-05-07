// This is the actual brains behind the DVD class

#include "DVD.h"

// PRIVATE ------------------------------------------------------------------

void DVD::initVariables() {
    this->window = nullptr;
}


void DVD::initWindow() {
    // Size of our application window screen
    this->videoMode.height = 600;
    this->videoMode.width = 800;

    // Using the SFML library, make a window 600x800 pixels from 'videoMode', titlebar, and a close button
    this->window = new sf::RenderWindow(this->videoMode, "Please Enter DVD . . .    Press 'ESC' to Exit", sf::Style::Titlebar | sf::Style::Close);
}




// PUBLIC -------------------------------------------------------------------

// First thing to run in main, building the class
DVD::DVD() {
    this->initVariables();
    this->initWindow();
}


// Deallocates everything once the program is FULLY done
DVD::~DVD() {
    delete this->window;
}


// Accessor, checking on the window private value, seeing if it's open and returning a bool
const bool DVD::running() const {
    return this->window->isOpen();
}


// Tracking all the pending events going on with the computer; i.e. hitting 'ESC' or close
void DVD::pollEvents() {
    while(this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            // Close application if the X button in the title bar is clicked
            case sf::Event::Closed:
                this->window->close();
                break;
            
            // Close app. if 'ESC' key is pressed
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                break;
        }
    }
}


// Our backend brain logic, making the pixels and stuff
void DVD::update() {
    this->pollEvents(); // Since it's a blank screen we're just checking to see if there was any input
}


// Put the pixels on the screen
void DVD::render() {
    this->window->clear(sf::Color(0, 0, 0, 255)); // Gives us a black screen, refreshes every second
    
    this->window->display(); // put the render to screen
}