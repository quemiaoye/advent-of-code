#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int getNumber(const std::string& input, int low, int high, char low_char) {
    if (input.length() == 1) {
        return input[0] == low_char ? low : high;
    }

    return input[0] == low_char ?
           getNumber(input.substr(1), low, (low + high + 1) / 2 - 1, low_char) :
           getNumber(input.substr(1), (low + high + 1) / 2, high, low_char);
}

int main() {
    std::ifstream file;
    file.open("/Users/hazelque/Desktop/advent-of-code/day-5/input.txt");

    std::string str;
    int highest_seat_id = 0;
    std::vector<int> seat_ids;
    if (file.is_open()) {
        while (std::getline(file, str)) {
            std::string row = str.substr(0, 7);
            std::string col = str.substr(7);

            int row_num = getNumber(row, 0, 127, 'F');
            int col_num = getNumber(col, 0, 7, 'L');

            int result = row_num * 8 + col_num;
            seat_ids.push_back(result);

            if (result > highest_seat_id) highest_seat_id = result;
        }
        file.close();
    }

    int prev_id = 0;
    std::sort(seat_ids.begin(), seat_ids.end());
    for (const auto& id : seat_ids) {
        if (prev_id != 0 && id != prev_id + 1) {
            std::cout << "Missing seat number: " << id - 1 << std::endl;
        }
        prev_id = id;
    }

    std::cout << "The highest seat ID is: " << highest_seat_id << std::endl;

    return 0;
}