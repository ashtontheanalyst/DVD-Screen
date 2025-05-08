// The main file running the program

#include <iostream>
#include "DVD.h"

int main() {
    // set the random gen. seed
    std::srand(static_cast<unsigned>(time(NULL)));

    DVD dvd; // make a variable called dvd of class DVD

    // The 'game loop'
    while (dvd.running()) {
        // backend updating goes first, think of the pixels before displaying them
        dvd.update();

        // send those pixels to the screen
        dvd.render();
    }

    return 0;
}