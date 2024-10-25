#include <string>
#include <iostream>
#include <queue>   // For std::priority_queue

#include "huffmantree.h"
#include "leafnode.h"
#include "interiornode.h"
#include "tree_printer.h"

struct compare_function{
    bool operator()(HuffmanNode* node1, HuffmanNode* node2){
        return (node1->get_frequency() > node2->get_frequency());
    }
};

std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, compare_function> queue1;

// Implement the methods of the HuffmanTree class here.

// You will use a std::priority_queue to assist the Huffman
// tree construction.