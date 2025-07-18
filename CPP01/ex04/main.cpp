#include "../Formatting.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {
    if (argc != 4){
        std::cerr << RED << "ERROR » " << CYAN << "Usage: " << YELLOW;
        std::cerr << argv[0] << " <filename> <to_replace> <replace_by>" << RESET << std::endl;
        return 1;
    }

    std::string file(argv[1]);
    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(file.append(".replace").c_str());
    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << RED << "ERROR » " << YELLOW << "Could not open file " << RESET << std::endl;
        return 1;
    }

    std::string toReplace(argv[2]);
    if (toReplace.empty()) {
        std::cerr << RED << "ERROR » " << YELLOW << "String <to_replace> cannot be empty" << RESET << std::endl;
        return 1;
    }
    std::string replaceBy(argv[3]);
    std::string line;

    while (std::getline(inputFile, line)) {
    std::string result;
    std::size_t pos = 0;
    std::size_t found;
    while ((found = line.find(toReplace, pos)) != std::string::npos) {
        result.append(line, pos, found - pos);
        result.append(replaceBy);
        pos = found + toReplace.length();
    }
    result.append(line, pos, line.length() - pos);
    outputFile << result << std::endl;
}

    inputFile.close();
    outputFile.close();

    std::cout << GREEN << "File " << YELLOW << argv[1] << GREEN << " has been processed and saved as " << YELLOW << file << RESET << std::endl;

    return 0;
}