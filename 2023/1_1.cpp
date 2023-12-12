#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream input("1.in");
    vector<string> lines;
    while (!input.eof()) {
        string line;
        getline(input, line);
        lines.push_back(line);
    }

    int sum = 0;
    for (int i = 0; i < lines.size(); i++) {
        char first = '0';
        for (string::iterator it = lines[i].begin(); it != lines[i].end(); ++it) {
            if (isdigit(*it)) {
                first = *it;
                break;
            }
        }
        char last = '0';
        for (string::reverse_iterator it = lines[i].rbegin(); it != lines[i].rend(); ++it) {
            if (isdigit(*it)) {
                last = *it;
                break;
            }
        }
        int num = stoi(string(1, first) + last);
        cout << num << endl;
        sum += num;
    }
    cout << sum << endl;
    return 0;
}
