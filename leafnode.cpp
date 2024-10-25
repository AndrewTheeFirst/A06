#include "leafnode.h"

LeafNode::LeafNode(char ch, double freq) : HuffmanNode(freq) {
	character = ch;
}

std::string LeafNode::to_string() const{
	return "[" + std::string(1, character) + ":" + std::to_string(get_frequency()) + "]";
};

std::string LeafNode::get_code(char c) const{
	if (c != character){ return NO_MATCH; }
		return NO_MATCH;
	return "";
};

