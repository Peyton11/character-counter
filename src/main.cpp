// main.cpp
// Parses a file of text to caculate how many times a characters appears.

#include <iostream>
#include <map>
#include <fstream>

int main(int argc, char* argv[]) {

    std::map<char, int> characterCounter;

    std::ifstream file("../examples/example.txt");
    if (!file) {
        std::cerr << "Unable to open file\n";
        return 1;
    }

    char ch;
    while (file.get(ch)) {
        ++characterCounter[ch];
    }

    file.close();

    int totalCount = 0;

    // Output results
    std::cout << "Charcter Counts:\n";
    for (auto it = characterCounter.begin(); it != characterCounter.end(); ++it) {

        totalCount += it->second;

        // Special case for spaces
        if (it->first == ' ')
            std::cout << "space: " << it->second << '\n';
        // Special case for newlines
        else if (it->first == '\n')
            std::cout << "newline: " << it->second << '\n';
        else
            std::cout << it->first << ": " << it->second << '\n';
    }
    std::cout << "Total characters: " << totalCount << '\n';

    return 0;
}