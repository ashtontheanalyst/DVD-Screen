// This is the actual brains behind the DVD class

#include "DVD.h"
#include <iostream>

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


// making the DVD logo appear
void DVD::initDVD() {
    // End program if the DVD logo file doesn't load in
    if (!texture.loadFromFile("dvdLogo.png")) {
        std::cout << "ERROR: Could not load image, check path to image in code." << '\n';
    }

    this->x = rand() % 300; // first frame x val. of logo is bet 0 and 300 pix
    this->y = rand() % 300;

    this->logo.setTexture(this->texture);
    this->logo.setPosition(this->x, this->y);
    this->logo.scale(sf::Vector2f(0.125, 0.125));
}




// PUBLIC -------------------------------------------------------------------

// First thing to run in main, building the class
DVD::DVD() {
    this->initVariables();
    this->initWindow();
    this->initDVD();
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


// update the DVD pos.
void DVD::updateDVD() {
    this->logo.setPosition(this->x, this->y);
}


// Our backend brain logic, making the pixels and stuff
void DVD::update() {
    this->pollEvents(); // Since it's a blank screen we're just checking to see if there was any input
    // this->updateDVD();
}


// Put the pixels on the screen
void DVD::render() {
    this->window->clear(sf::Color(0, 0, 0, 255)); // Gives us a black screen, refreshes every second

    this->window->draw(this->logo); // put the logo on the screen

    this->window->display(); // put the render to screen
}