#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Point.h"
#include "button.h"

class App {
public:
    App(int width = 100, int height = 100, std::string name = "work"):
    width_(width), height_(height)
    {
        std::swap(name, name_);
        window_ = new sf::RenderWindow(sf::VideoMode(width_, height_), name_);
    }

    int16_t render();

private:
    int width_, height_;
    std::string name_;
    sf::RenderWindow* window_;
    enum Stage {input, points, walls, ray, play};
};
