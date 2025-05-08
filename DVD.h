// This is the declaration for the DVD class

#pragma once // compile once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <ctime> // for our random generator
#include <iostream>

class DVD {
    private:
        // VARIABBLES -------------------------------------------------------
        // Window
        sf::RenderWindow * window; // our application window as a whole
        sf::VideoMode videoMode; // this helps make our application screen
        sf::Event ev; // This event var. is used for tracking things like button presses, keys, etc.

        // Logo
        float x, y;
        float xspd, yspd; // increments
        int r, g, b, a;
        sf::Color color;
        sf::Texture texture;
        sf::Sprite logo;


        // INITIALIZATION ---------------------------------------------------
        void initVariables();
        void initWindow();
        void initDVD();

    public:
        DVD(); // Constructor, sets up the inital class and initializes
        virtual ~DVD(); // Destructor, cleans everything up at the end

        // ACCESSORS -------------------------------------------------------
        const bool running() const; // looks into the private section and pulls a value into public

        // FUNCTIONS -------------------------------------------------------        
        void pollEvents();
        
        void changeColor();
        void updateDVD();
        void update();
        
        void render();
};