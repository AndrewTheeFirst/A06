#include <iostream>
#include <map>
#include "huffmantree.h"

// Add any helper functions as needed


int main() {
    std::map<char, int> letter_map;
    letter_map.insert({'a', 21});
    letter_map.insert({'b', 49});
    letter_map.insert({'c', 1});
    letter_map.insert({'d', 29});
    HuffmanTree* tree = new HuffmanTree(letter_map);
    std::cout << "a:" + tree->get_code('a') + "\n";
    std::cout << "b:" + tree->get_code('b') + "\n";
    std::cout << "c:" + tree->get_code('c') + "\n";
    std::cout << "d:" + tree->get_code('d') + "\n";
    
    // 1. Get the text and count all the letters in the text
    //    (place in a std::map object).

    // 2. Display the number of occurrences of each letter.

    // 3. Build the Huffman tree from the std::map of letters
    //    with their associated counts.

    // 4. Draw the Huffman tree.

    // 5. Print the Huffman codes for each letter.

    // 6. Print the number of bits required for a fixed-width
    //    encoding of the file (5 bits per letter for 26 letters).

    // 7. Print the number of bits required for a Huffman
    //    encoding of the file.
}