#include <iostream>
#include <fstream>
#include <unordered_set>

int main() {
    std::ifstream file;
    file.open("/Users/hazelque/Desktop/advent-of-code/day-6/input.txt");

    std::string str;
    int total_unique_yes = 0;
    bool skip_next_line = false;
    std::unordered_set<char> common_yes_questions;
    if (file.is_open()) {
        while (std::getline(file, str)) {
            if (str.empty()) {
                total_unique_yes += common_yes_questions.size();
                common_yes_questions.clear();
                skip_next_line = false;
                continue;
            }

            if (skip_next_line) continue;

            if (common_yes_questions.empty()) {
                for (const auto &cur : str) {
                    common_yes_questions.insert(cur);
                }
            } else {
                std::unordered_set<char> current_yes_questions;
                for (const auto& cur : str) {
                    current_yes_questions.insert(cur);
                }

                for (const auto& q : common_yes_questions) {
                    if (current_yes_questions.find(q) == current_yes_questions.end()) {
                        common_yes_questions.erase(q);
                    }
                }

                if (common_yes_questions.empty()) {
                    skip_next_line = true;
                }
            }
        }

        total_unique_yes += common_yes_questions.size();
        file.close();
    }

    std::cout << "The number of questions to which anyone answered 'yes' is: " << total_unique_yes;

    return 0;
}