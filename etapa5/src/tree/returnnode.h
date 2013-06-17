#ifndef RETURNNODE_H
#define RETURNNODE_H

#include "node.h"

class ReturnNode : public Node {

public:
	ReturnNode(Node* expression);
	void printSourceCode(const std::string& end);
	void generateILOCCode();
	void printILOC();
};

#endif // RETURNNODE_H
