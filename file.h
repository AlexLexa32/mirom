#ifndef MIROM_FILE_H
#define MIROM_FILE_H

#include <fstream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "light.h"

inline void save(const int& n, const std::vector<sf::VertexArray>& walls, light ray,
                 const std::string& name) {
    std::ofstream fout(name);
    fout << n << '\n';
    for (auto& wall : walls) {
        fout << wall[0].position.x << ' ' << wall[0].position.y << ' ';
        fout << wall[1].position.x << ' ' << wall[1].position.y << '\n';
    }
    auto rgp = ray.GetPoints();
    fout << rgp.first.x << ' ' << rgp.first.y << '\n';
    fout << rgp.second.x << ' ' << rgp.second.y << '\n';
}

inline void read(int& n, std::vector<sf::VertexArray>& walls, light& ray,
                 const std::string& name) {
    std::ifstream fin(name);//🥖🥖🥖🥖🥖🐟🐟
    fin >> n;
    for (auto& wall : walls) {
        fin >> wall[0].position.x >> wall[0].position.y;
        fin >> wall[1].position.x >> wall[1].position.y;
    }
    auto rgp = ray.GetPoints();
    fin >> rgp.first.x >> rgp.first.y;
    fin >> rgp.second.x >> rgp.second.y;
    ray = light(rgp.first, rgp.second);
}

#endif MIROM_FILE_H
