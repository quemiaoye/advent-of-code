#include <fstream>
#include <iostream>

long treesOnSlope(int right, int down) {
    std::ifstream file;
    file.open("/Users/hazelque/Desktop/advent-of-code/day-3/input.txt");

    int num_trees = 0;
    if (file.is_open()) {
        std::string str;
        int cur_pos = 0;
        int down_counter = down;
        while (std::getline(file, str)) {
            if (down_counter != 1) {
                down_counter--;
                continue;
            }
            int new_pos = cur_pos + right;
            if (new_pos > str.length() - 1) {
                new_pos %= str.length();
            }
            char cur_symbol = str.at(new_pos);
            cur_pos = new_pos;
            char tree = '#';
            if (cur_symbol == tree) num_trees++;
            down_counter = down;
        }
        file.close();
    }
    return num_trees;
}

int main() {
    long long total =
            treesOnSlope(1, 1) * treesOnSlope(3, 1) * treesOnSlope(5, 1) * treesOnSlope(7, 1) * treesOnSlope(1, 2);

    std::cout << "Number of trees is: " << total;

    return 0;
}