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

HuffmanTree::HuffmanTree(const std::map<char, int>& counts){
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, compare_function> queue;
    auto begin = counts.begin(), end = counts.end();
    int total_num_chars = 0;
    double char_frequency;
    for (auto location = begin; location != end; location++){
        total_num_chars += location->second;
    }
    for (auto location = begin; location != end; location++){
        char_frequency = static_cast<double>(location->second) / total_num_chars;
        HuffmanNode* node = new LeafNode(location->first, char_frequency);
        queue.push(node);
    }

    HuffmanNode* left, * right, * head;
    for (int size = queue.size(); size > 1; size--){
        left = queue.top();
        queue.pop();
        right = queue.top();
        queue.pop();
        head = new InteriorNode(left->get_frequency() + right->get_frequency(), left, right);
        queue.push(head);
    }
    root = head;
};

void HuffmanTree::draw() const{
};

std::string HuffmanTree::get_code(char ch) const{
    return root->get_code(ch);
};