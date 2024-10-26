#include <iostream>
#include <map>
#include "huffmantree.h"

// Add any helper functions as needed


int main() {
    std::map<char, int> letter_map;
    letter_map.insert({'a', 16});
    letter_map.insert({'b', 39});
    letter_map.insert({'c', 6});
    letter_map.insert({'d', 20});
    letter_map.insert({'e', 10});
    letter_map.insert({'f', 5 });
    letter_map.insert({'g', 4 });
    HuffmanTree* tree = new HuffmanTree(letter_map);
    std::cout << "a:" + tree->get_code('a') + "\n";
    std::cout << "b:" + tree->get_code('b') + "\n";
    std::cout << "c:" + tree->get_code('c') + "\n";
    std::cout << "d:" + tree->get_code('d') + "\n";
    std::cout << "e:" + tree->get_code('e') + "\n";
    std::cout << "f:" + tree->get_code('f') + "\n";
    std::cout << "g:" + tree->get_code('g') + "\n";
    
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