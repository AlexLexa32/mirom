#include "App.h"

int16_t App::render() {
    Stage stage = input;
    //input
    Label label(100, 70, 20, 0, sf::Color::Transparent, sf::Color::Transparent);
    label.setText("select number of points:");
    std::vector<Button1> buttons(7, Button1(40, 70));
    for (int i = 3; i <= 9; ++i) {
        buttons[i-3].setText('0'+i);
        buttons[i-3].setPos(30+(i-3)*45, 90);
    }
    int angl_num = 0;

    //poinsts
    std::vector<sf::VertexArray> polygon;
    bool kostil = true;
    int cur_ind = 0;

    //walls
    int16_t wall_number = 0;

    //ray
    Point<double> vec_start(-1, -1);
    Point<double> vec_end(-1, -1);
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(0,0);
    line[1].position = sf::Vector2f(100,150);
    line[0].color = sf::Color::Blue;
    line[1].color = sf::Color::Cyan;

    //play
    math_vector r(0, 0);
    while (window_->isOpen()) {
        sf::Event event;
        sf::Vector2i m_pozition = sf::Mouse::getPosition(*window_);
        while (window_->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_->close();
        }

        switch (stage) {
            case input:
                window_->clear();
                label.draw(*window_);
                for (int i = 3; i <= 9; ++i) {
                    buttons[i-3].draw(*window_);
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if (buttons[i - 3].Pressed(m_pozition)) {
                            angl_num = i;
                            polygon.resize(i);
                            label.setText("click on the corners of the room:");
                            kostil = false;
                            stage = points;
                        }
                    }
                }
                break;
            case points:
                window_->clear();
                label.draw(*window_);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (kostil) {
                        kostil = false;
                        if (cur_ind == 0) {
                            for (int i = 0; i < angl_num; ++i) {
                                sf::VertexArray q(sf::Lines, 2);
                                polygon[i] = sf::VertexArray(sf::Lines, 2);
                                polygon[i][0].position = sf::Vector2f(m_pozition.x,
                                                                      m_pozition.y);
                                polygon[i][1].position = sf::Vector2f(m_pozition.x,
                                                                      m_pozition.y);
                            }
                        } else {
                            polygon[cur_ind-1][1].position = sf::Vector2f(m_pozition.x,
                                                                          m_pozition.y);
                            polygon[cur_ind][0].position = sf::Vector2f(m_pozition.x,
                                                                        m_pozition.y);
                        }
                        cur_ind++;
                        if (cur_ind == angl_num) {
                            label.setText("select wall types:");
                            stage = walls;
                        }
                    }
                } else {
                    kostil = true;
                }
                for (auto& elem : polygon) {
                    window_->draw(elem);
                }
                break;
            case walls:
                window_->clear();
                for (auto& elem : polygon) {
                    window_->draw(elem);
                }

                stage = ray;
                break;
            case ray:
                window_->clear();
                if (kostil && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (vec_start.x == -1) {
                        vec_start = Point<double>(m_pozition.x, m_pozition.y);
                        vec_end = Point<double>(-1, -1);
                        line[0].position = sf::Vector2f(vec_start.x, vec_start.y);
                        line[1].position = sf::Vector2f(vec_end.x, vec_end.y);
                    } else {
                        vec_end = Point<double>(m_pozition.x, m_pozition.y);
                        line[0].position = sf::Vector2f(vec_start.x, vec_start.y);
                        line[1].position = sf::Vector2f(vec_end.x, vec_end.y);
                    }
                } else if (!(sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
                    kostil = true;
                }
                if (vec_end.x != -1) {
                    window_->draw(line);
                    if (!(sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
                        r = math_vector(vec_start/1234, vec_end/1234);
                        window_->clear();
                        for (auto& elem : polygon) {
                            window_->draw(elem);
                        }
                        stage = play;
                    }
                }
                for (auto& elem : polygon) {
                    window_->draw(elem);
                }

                break;
            case play:
                sf::RectangleShape pixel(sf::Vector2f(1, 1));
                pixel.setPosition(vec_start.x, vec_end.y);
                pixel.setFillColor(sf::Color::Yellow);
                window_->draw(pixel);
                vec_start = r.GetPointImage(vec_start);

                break;
        }


        window_->display();
    }
    return 0;
}