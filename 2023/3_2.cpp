#include <fstream>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

struct part {
    std::string val;
    int pos;
};

std::vector<part> split(std::string s, std::string de) {
    std::string str = s;
    size_t pos = 0;
    int loc = 0;
    std::vector<part> tokens;
    while ((pos = str.find_first_of(de)) != std::string::npos) {
        if (pos != 0) tokens.push_back({str.substr(0, pos), loc});
        loc += pos + 1;
        str.erase(0, pos + 1);
    }
    tokens.push_back({str, loc});
    return tokens;
}

int main() {
    std::ifstream input("3.in");
    std::vector<std::string> lines;
    while (!input.eof()) {
        std::string line;
        getline(input, line);
        lines.push_back(line);
    }
    lines.pop_back();

    int sum = 0;
    for (const auto [i, line] : std::views::enumerate(lines)) {
        auto spl = split(line, ".!@#$%^&*()-_+=|\\/\"';:,<>?~`");
        for (part p : spl) {
            int num = 0;
            try {
                num = std::stoi(p.val);
            } catch (std::invalid_argument const& ex) {
                continue;
            }
            int symbols = 0;
            std::vector<int> cols(p.val.length() + 2);
            std::iota(cols.begin(), cols.end(), p.pos - 1);
            for (int col : cols) {
                if (col < 0 || col >= line.length()) continue;
                if (i - 1 >= 0 && !std::isalnum(lines[i - 1][col]) && lines[i - 1][col] != '.') symbols++;
                if (!std::isalnum(line[col]) && line[col] != '.') symbols++;
                if (i + 1 < lines.size() && !std::isalnum(lines[i + 1][col]) && lines[i + 1][col] != '.') symbols++;
            }
            if (symbols) sum += num;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
