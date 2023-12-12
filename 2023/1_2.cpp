#include <algorithm>
#include <array>
#include <climits>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>
using namespace std;

const array<string, 20> digits = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "zero",
                                  "1",   "2",   "3",     "4",    "5",    "6",   "7",     "8",     "9",    "0"};

int value(string str) {
    int size = str.length();
    int index = find(digits.begin(), digits.end(), str) - digits.begin();
    if (size > 1) {
        index += 10;
    }
    return stoi(digits[index]);
}

int main() {
    ifstream input("1.in");
    vector<string> lines;
    while (!input.eof()) {
        string line;
        getline(input, line);
        lines.push_back(line);
    }
    lines.pop_back();

    int sum = 0;
    for (int i = 0; i < lines.size(); i++) {
        array<int, 20> front_pos{};
        for (auto const [ind, digit] : views::enumerate(digits)) {
            front_pos[ind] = lines[i].find(digit);
            if (front_pos[ind] == -1) {
                front_pos[ind] = 100;
            }
        }
        int first = value(digits[min_element(front_pos.begin(), front_pos.end()) - front_pos.begin()]);
        array<int, 20> back_pos{};
        for (auto const [ind, digit] : views::enumerate(digits)) {
            back_pos[ind] = lines[i].rfind(digit);
            if (back_pos[ind] == -1) {
                back_pos[ind] = -100;
            }
        }
        for (auto x : back_pos) {
            cout << x << " ";
        }
        int last = value(digits[max_element(back_pos.begin(), back_pos.end()) - back_pos.begin()]);
        int num = (first * 10) + last;
        cout << num << endl;
        sum += num;
    }
    cout << sum << endl;
    return 0;
}
