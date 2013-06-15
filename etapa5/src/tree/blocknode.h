#ifndef BLOCONODE_H
#define BLOCONODE_H

#include <vector>
#include "node.h"

class BlockNode : public Node {

public:
	BlockNode();
	BlockNode(bool isNewScope);
	void printSourceCode(const std::string& end);
	void generateILOCCode();
};

#endif // BLOCONODE_H
