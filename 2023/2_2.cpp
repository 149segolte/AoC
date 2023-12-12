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
        auto spl = split(line, ":");
        auto games = split(spl[1], ";");
        int r_max = 0, g_max = 0, b_max = 0;
        for (auto game : games) {
            auto cubes = split(game, ",");
            for (auto cube : cubes) {
                auto spl = split(cube, " ");
                int val = std::stoi(spl[1]);
                if (spl[2] == "red" && val > r_max) {
                    r_max = val;
                } else if (spl[2] == "green" && val > g_max) {
                    g_max = val;
                } else if (spl[2] == "blue" && val > b_max) {
                    b_max = val;
                }
            }
        }
        sum += (r_max * g_max * b_max);
    }
    std::cout << sum << std::endl;
    return 0;
}
