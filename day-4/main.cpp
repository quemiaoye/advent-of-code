#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, std::string> processEntry(std::vector<std::string> entry) {
    std::vector<std::string> tokens;
    std::string delimiter = " ";
    for (std::string line : entry) {
        while (line.find(delimiter) != std::string::npos) {
            size_t pos = line.find(delimiter);
            std::string token = line.substr(0, pos);
            tokens.push_back(token);
            line.erase(0, pos + delimiter.length());
        }
        tokens.push_back(line);
    }

    std::unordered_map<std::string, std::string> passport;
    delimiter = ":";
    for (std::string token : tokens) {
        size_t pos = token.find(delimiter);
        std::string field = token.substr(0, pos);
        std::string value = token.erase(0, pos + delimiter.length());
        passport.insert(std::make_pair(field, value));
    }

    return passport;
}

bool passportHasEnoughFields(std::unordered_map<std::string, std::string> entry) {
    bool cid_present = false;
    if (entry.find("cid") != entry.end()) {
        cid_present = true;
    }
    int numFields = entry.size();

    return (numFields == 7 && !cid_present) || numFields == 8;
}

bool isValidNumber(std::string& value, int start, int end) {
    int year = std::stoi(value);
    return year >= start && year <= end;
}

bool isValidHeight(std::string& height) {
    std::string num;
    std::string unit;
    for (char cur : height) {
        if (isdigit(cur)) num.push_back(cur);
        else unit.push_back(cur);
    }
    if (unit != "cm" || unit != "in") return false;
    if (unit == "cm") {
        return isValidNumber(num, 150, 193);
    }
    if (unit == "in") {
        return isValidNumber(num, 59, 76);
    }
}

bool isValidPassport(std::unordered_map<std::string, std::string> entry) {
    bool is_valid = false;
    if (!isValidNumber(entry.at("byr"), 1920, 2002)) return is_valid;
    if (!isValidNumber(entry.at("iyr"), 2010, 2020)) return is_valid;
    if (!isValidNumber(entry.at("iyr"), 2020, 2030)) return is_valid;
    if (!isValidHeight(entry.at("hgt"))) return is_valid;
    return true;
}

bool checkPassportValidity(std::unordered_map<std::string, std::string> entry) {
    if (!passportHasEnoughFields(entry)) return false;
    return isValidPassport(entry);
}

int main() {
    std::ifstream file;
    file.open("/Users/hazelque/Desktop/advent-of-code/day-4/input.txt");

    std::string str;
    std::vector<std::string> entry;
    int num_valid_passports = 0;
    if (file.is_open()) {
        while (std::getline(file, str)) {
            if (str.empty()) {
                if (checkPassportValidity(processEntry(entry))) num_valid_passports++;
                entry.clear();
            } else {
                entry.push_back(str);
            }
        }
        if (checkPassportValidity(processEntry(entry))) num_valid_passports++;
        file.close();
    }

    std::cout << "Number of valid passports is: " << num_valid_passports << std::endl;

    return 0;
}