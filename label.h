#pragma GCC optimize("Ofast,unroll-loops,mfma,mavx,mavx2")
#pragma GCC target("avx,avx2,fma")
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

#ifndef LABEL_H
#define LABEL_H

class Label {
private:
    int height_, width_;
    float x_, y_;
    std::string txt_;
    sf::Color clr_;
    sf::Color clr2_;
    int sz_;
    bool inp_in_this_;
public:
    Label(int width = 1, int height = 1, int x = 0, int y = 0, sf::Color clr = sf::Color::White, sf::Color clr2 = sf::Color::White) {
        height_ = height;
        width_ = width;
        clr_ = clr;
        clr2_ = clr2;
        x_ = x;
        y_ = y;
        txt_ = "";
        sz_ = 45;
        inp_in_this_ = false;
    }
    Label(const Label& other) {
        height_ = other.height_;
        width_ = other.width_;
        clr_ = other.clr_;
        clr2_ = other.clr2_;
        x_ = other.x_;
        y_ = other.y_;
        txt_ = other.txt_;
        inp_in_this_ = false;
    }
    ~Label() = default;
    void setPos(int x, int y) {
        x_ = x;
        y_ = y;
        return;
    }

    void draw (sf::RenderWindow& window) {
        sf::Font font;
        font.loadFromFile("pobeda-regular1.ttf");
        sf::RectangleShape tmp(sf::Vector2f(width_, height_));
        tmp.setPosition(x_, y_);
        if (inp_in_this_) {
            tmp.setFillColor(clr2_);
        } else {
            tmp.setFillColor(clr_);
        }
        window.draw(tmp);
        sf::Text txt;
        txt.setString(txt_);
        txt.setFont(font);
        txt.setFillColor(sf::Color::White);
        if (clr_ == sf::Color::Black) {
            txt.setFillColor(sf::Color::White);
        }
        txt.setCharacterSize(sz_);
        txt.setPosition(x_+2, y_);
        window.draw(txt);
    }
    void setSZ(int sz) {
        sz_ = sz;
    }
    void setIIT(bool flag) {
        inp_in_this_ = flag;
    }
    bool inpInThis() {
        return inp_in_this_;
    }
    bool Pressed(float x, float y) {
        //inp_in_this_ = x <= x_+width_ && x >= x_ && y <= y_+height_ && y >= y_;
        return x <= x_+width_ && x >= x_ && y <= y_+height_ && y >= y_;
    }
    std::string& txt() {
        return txt_;
    }
    inline void move(float x) {
        x_ += x;
    }
    void push_back(char x) {
        if (x >= '0' && x <= '9') {
            if (txt_.size() < 7) {
                txt_.push_back(x);
            }
        }
    }
    void pop_back() {
        if (txt_.size() > 0) {
            txt_.pop_back();
        }
    }
    void setText(std::string s) {
        txt_ = s;
    }

};

#endif //LABEL_H