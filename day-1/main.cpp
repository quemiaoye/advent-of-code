#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>

int productOfTwoNumbers(std::unordered_set<int>& input, const int sum) {
    for (int cur : input) {
        if (input.find(sum - cur) != input.end()) {
            return cur * (sum - cur);
        }
    }
    return 0;
}

int productOfThreeNumbers(std::unordered_set<int>& input, const int sum) {
    for (int cur : input) {
        int complement = sum - cur;
        int multiply_two = productOfTwoNumbers(input, complement);
        if (multiply_two != 0) {
            return multiply_two * cur;
        }
    }
    return 0;
}

int main() {
    std::ifstream file;
    file.open("/Users/hazelque/Desktop/advent-of-code/day-1/input.txt");

    int sum = 2020;
    std::unordered_set<int> input;

    std::string str;
    if (file.is_open()) {
        while (std::getline(file, str)) {
            int num = std::stoi(str);
            input.insert(num);
        }
        file.close();
    }

    int first_sum = productOfTwoNumbers(input, sum);
    std::cout << "Product of two numbers that add to " << sum << " is: " << first_sum << std::endl;
    int second_sum = productOfThreeNumbers(input, sum);
    std::cout << "Product of three numbers that add to " << sum << " is: " << second_sum << std::endl;


    return 0;
}