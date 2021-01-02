#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <list>
#include <unordered_map>
#include <unordered_set>

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

const std::unordered_map<std::string, const std::function<bool(const std::string &)>> validator{
        {"byr", [](const std::string &value) -> bool { return std::stoi(value) >= 1920 && std::stoi(value) <= 2002; }},
        {"iyr", [](const std::string &value) -> bool { return std::stoi(value) >= 2010 && std::stoi(value) <= 2020; }},
        {"eyr", [](const std::string &value) -> bool { return std::stoi(value) >= 2020 && std::stoi(value) <= 2030; }},
        {"hgt", [](const std::string &value) -> bool {
            std::smatch match;
            if (regex_match(value.cbegin(), value.cend(), match, std::regex("([0-9]+)(cm|in)"))) {
                if (match[2].str() == "cm") {
                    int height = std::stoi(match[1].str());
                    return height >= 150 && height <= 193;
                }
                if (match[2].str() == "in") {
                    int height = std::stoi(match[1].str());
                    return height >= 59 && height <= 76;
                }
            }
            return false;
        }},
        {"hcl", [](const std::string &value) -> bool {
            return regex_match(value.cbegin(), value.cend(), std::regex("#([0-9]|[a-f]){6}"));
        }},
        {"ecl", [](const std::string &value) -> bool {
            const std::list<std::string> valid_eye_colors{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
            return std::find(valid_eye_colors.cbegin(), valid_eye_colors.cend(), value) != valid_eye_colors.end();
        }},
        {"pid", [](const std::string &value) -> bool {
            return regex_match(value.cbegin(), value.cend(), std::regex("[0-9]{9}"));
        }},
};


bool isValidPassport(std::unordered_map<std::string, std::string> entry) {
    for (const auto &field : entry) {
        if (field.first == "cid") continue;
        if (!validator.at(field.first)(field.second)) return false;
    }
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