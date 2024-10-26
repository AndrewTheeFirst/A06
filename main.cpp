#include <iostream>
#include <map>
#include <cctype>
#include "huffmantree.h"

void get_letters(std::map<char, int>* counts){
    char ch;
    while(std::cin.get(ch)){
        if (std::isalpha(ch)){
            ch = static_cast<char>(std::toupper(ch));
            auto pair = counts->find(ch);
            if (pair != counts->end()){
                pair->second += 1;
            }
            else{
                counts->insert({ch, 1});
            }
        }
    }
}

// returns the number of bits required to store the alphabetic letters in the document
// using a fixed-width encoding (5 bits are necessary to represent 26 different letters)
int print_occurences(std::map<char, int>* counts){
    std::cout << "Counts:\n-------\n";
    auto end = counts->end();
    int occurences;
    int total = 0;
    for (auto location = counts->begin(); location != end; ++location){
        occurences = location->second;
        std::cout << location->first << ": " << occurences << "\n";
        total += occurences;
    }
    std::cout << "Total = " << total << "\n";
    return total * 5;
}

// returns number of bits required to store the alphabetic
// letters in the document the constructed Huffman variable-length encoding
int print_codes(std::map<char, int>* counts, std::map<char, std::string>* codes, HuffmanTree* tree){
    int total_bits = 0;
    auto end = counts->end();
    char ch;
    std::string code;
    std::cout << "\n";
    for (auto location = counts->begin(); location != end; ++location){
        ch = location->first;
        code = tree->get_code(ch);
        std::cout << ch << ": " << code << "\n";
        codes->insert({ch, code});
        total_bits += code.length() * location->second;
    }
    std::cout << "\n";
    return total_bits;
}


int main() {
    std::map<char, int> counts;
    std::map<char, std::string> codes;
    get_letters(&counts);
    int total_fixed_bits = print_occurences(&counts);
    HuffmanTree* tree = new HuffmanTree(counts);
    tree->draw();
    int total_variable_bits = print_codes(&counts, &codes, tree);
    std::cout << "  Fixed encoding: " << total_fixed_bits << " bits\n";
    std::cout << "Huffman encoding: " << total_variable_bits << " bits\n";
}