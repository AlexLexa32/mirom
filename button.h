//
// Created by macbook on 15.05.2024.
//

#ifndef BUTTTON_H
#define BUTTTON_H

#pragma GCC optimize("Ofast,unroll-loops,mfma,mavx,mavx2")
#pragma GCC target("avx,avx2,fma")
#pragma once
#include "label.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <algorithm>

class Button1 {
private:
    int height_, width_;
    float x_, y_;
    std::string txt_;
    sf::Color clr_;
    int sz_;
public:
    Button1(int width = 1, int height = 1, int x = 0, int y = 0, sf::Color clr = sf::Color::White) {
        height_ = height;
        width_ = width;
        clr_ = clr;
        x_ = x;
        y_ = y;
        txt_ = "";
        sz_ = 80;
    }
    Button1(const Button1& other) {
        height_ = other.height_;
        width_ = other.width_;
        clr_ = other.clr_;
        x_ = other.x_;
        y_ = other.y_;
        txt_ = other.txt_;
        sz_ = other.sz_;
    }
    ~Button1() = default;
    void setPos(int x, int y) {
        x_ = x;
        y_ = y;
    }
    void draw (sf::RenderWindow& window) {
        sf::Font font;
        font.loadFromFile("pobeda-regular1.ttf");
        sf::RectangleShape tmp(sf::Vector2f(width_, height_));
        tmp.setPosition(x_, y_);
        tmp.setFillColor(clr_);
        window.draw(tmp);
        sf::Text txt;
        txt.setString(txt_);
        txt.setFont(font);
        txt.setFillColor(sf::Color::Black);
        txt.setCharacterSize(sz_);
        txt.setPosition(x_+5, y_-13);
        window.draw(txt);
    }
    void setSZ(int sz) {
        sz_ = sz;
    }
    bool Pressed(float x, float y) {
        return x <= x_+width_ && x >= x_ && y <= y_+height_ && y >= y_;
    }
    bool Pressed(sf::Vector2i q) {
        return Pressed(q.x, q.y);
    }
    void setText(const std::string& s) {
        txt_ = s;
    }
    void setText(char s) {
        txt_ = s;
    }
};

class Button2 {
private:
    float r_;
    float x_, y_;
    std::string txt_;
    sf::Color clr_;
    float sz_;
public:
    Button2(int r = 1, int x = 0, int y = 0, sf::Color clr = sf::Color::White) {
        r_ = r;
        clr_ = clr;
        x_ = x;
        y_ = y;
        txt_ = "";
        sz_ = r * 1.7;
    }
    Button2(const Button2& other) {
        r_ = other.r_;
        clr_ = other.clr_;
        x_ = other.x_;
        y_ = other.y_;
        txt_ = other.txt_;
    }
    ~Button2() = default;
    void draw (sf::RenderWindow& window) {
        sf::Font font;
        font.loadFromFile("pobeda-regular1.ttf");
        sf::CircleShape tmp(r_);
        tmp.setPosition(x_-r_/2, y_-r_/2);
        tmp.setFillColor(clr_);
        window.draw(tmp);
        sf::Text txt;
        txt.setString(txt_);
        txt.setFont(font);
        txt.setFillColor(sf::Color::Red);
        txt.setCharacterSize(sz_*0.7);
        txt.setPosition(x_-r_*0.5, y_-r_*0.5);
        window.draw(txt);
    }
    void setSZ(int sz) {
        sz_ = sz;
    }
    void operator+=(float x) {
        r_ += x;
        sz_ += x * 2;
    }
    bool Pressed(float x, float y) {
        return (x-x_)*(x-x_) + (y-y_)*(y-y_) < r_*r_;
    }
    void setText(std::string s) {
        txt_ = s;
    }
};


#endif /* BUTTON_H */
