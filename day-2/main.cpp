#include <fstream>
#include <iostream>

bool checkPasswordValidity(std::string input) {
    // Break down the input
    std::string delimiter = ": ";
    size_t pos = input.find(delimiter);
    std::string numOccurrences = input.substr(0, pos);
    std::string password = input.erase(0, pos + delimiter.length());

    // Break down the number of occurrences of a specific letter
    char letter = numOccurrences.back();
    delimiter = " ";
    std::string frequency = numOccurrences.substr(0, numOccurrences.find(delimiter));

    // Find the upper and lower bounds of the frequency
    delimiter = "-";
    pos = frequency.find(delimiter);
    int first = std::stoi(frequency.substr(0, pos));
    int second = std::stoi(frequency.erase(0, pos + delimiter.length()));

    // Part two
    char firstLetter = password.at(first - 1);
    char secondLetter = password.at(second - 1);

    return (firstLetter == letter) != (secondLetter == letter);
}

int main() {
    std::ifstream file;
    file.open("/Users/hazelque/Desktop/advent-of-code/day-2/input.txt");

    std::string str;
    int num_valid_passwords = 0;
    if (file.is_open()) {
        while (std::getline(file, str)) {
            if (checkPasswordValidity(str)) num_valid_passwords++;
        }
        file.close();
    }

    std::cout << "Number of valid passwords is: " << num_valid_passwords;

    return 0;
}