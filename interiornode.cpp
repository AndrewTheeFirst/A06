#include <iostream>
#include "interiornode.h"


// An interior node of a Huffman tree maintains a frequency and
// has pointers to its left and right subtrees.  It inherits its 
// frequency field from its base class.

// Add your code to implement the InteriorNode methods here.

InteriorNode::InteriorNode(double freq, HuffmanNode *lf, HuffmanNode *rt): HuffmanNode(freq){
    left = lf;
    right = rt;
};

InteriorNode::~InteriorNode(){
    delete left;
    delete right;
};

HuffmanNode* InteriorNode::get_left() const {
    return left;
};

HuffmanNode* InteriorNode::get_right() const {
    return right;
};

std::string InteriorNode::to_string() const{
	return "(" + std::to_string(get_frequency()) + ")";
};

std::string InteriorNode::get_code(char c) const{
    std::string current_code = left->get_code(c);
	if (current_code != NO_MATCH){
        return "0" + current_code;
    }
    current_code = right->get_code(c);
	if (current_code != NO_MATCH){
        return "0" + current_code;
    }
    return NO_MATCH;
};

