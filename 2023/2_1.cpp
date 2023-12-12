#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string s, std::string de) {
    std::string str = s;
    size_t pos = 0;
    std::vector<std::string> tokens;
    while ((pos = str.find(de)) != std::string::npos) {
        tokens.push_back(str.substr(0, pos));
        str.erase(0, pos + de.length());
    }
    tokens.push_back(str);
    return tokens;
}

int main() {
    int r_max = 12, g_max = 13, b_max = 14;
    std::ifstream input("2.in");
    std::vector<std::string> lines;
    while (!input.eof()) {
        std::string line;
        getline(input, line);
        lines.push_back(line);
    }
    lines.pop_back();

    int sum = 0;
    for (auto line : lines) {
        bool flag = false;
        auto spl = split(line, ":");
        int id = std::stoi(split(spl[0], " ")[1]);
        auto games = split(spl[1], ";");
        for (auto game : games) {
            auto cubes = split(game, ",");
            for (auto cube : cubes) {
                auto spl = split(cube, " ");
                if (spl[2] == "red") {
                    flag = std::stoi(spl[1]) > r_max;
                } else if (spl[2] == "green") {
                    flag = std::stoi(spl[1]) > g_max;
                } else if (spl[2] == "blue") {
                    flag = std::stoi(spl[1]) > b_max;
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) continue;
        sum += id;
    }
    std::cout << sum << std::endl;
    return 0;
}
