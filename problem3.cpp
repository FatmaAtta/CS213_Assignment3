// File name: A3_SheetPb03_20220834.cpp
// Purpose:
// Author(s): muntasir gaafar
// ID(s): 20220834
// Section: S10
// Date: December 6 2023
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

// A function that cleans a word of punctuation and non-alphanumeric characters
string clean_word(string word) {
    string result = "";
    for (char c : word) {
        if (isalnum(c) || c == '-') { // Keep alphanumeric and hyphen characters
            result += tolower(c); // Convert to lowercase
        }
    }
    return result;
}

// A function that creates a frequency table for a file using STL map
void create_frequency_table(string filename) {
    // Open the input file
    ifstream input(filename);
    if (input.fail()) {
        cout << "Failed to open the file " << filename << endl;
        return;
    }

    // Create a map to store the word and its frequency
    map<string, int> frequency_table;

    // Read the file word by word
    string word;
    while (input >> word) {
        // Clean the word
        word = clean_word(word);

        // If the word is not empty, increment its frequency in the map
        if (!word.empty()) {
            frequency_table[word]++;
        }
    }

    // Close the input file
    input.close();

    // Print the frequency table
    cout << "Frequency table for the file " << filename << ":" << endl;
    for (auto pair : frequency_table) {
        cout << pair.first << " : " << pair.second << endl;
    }
}

// The main function
int main() {
    // Ask the user to enter the file name
    cout << "Enter the file name: ";
    string filename;
    cin >> filename;

    // Create the frequency table for the file
    create_frequency_table(filename);

    return 0;
}
