#ifndef FUNCTIONCALLNODE_H
#define FUNCTIONCALLNODE_H

#include <string>
#include <vector>
#include "node.h"

class FunctionCallNode : public Node {

public:
	FunctionCallNode(Symbol* functionSym, std::vector<Node*>* children);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);
	bool hasDeclaration(Symbol* sym);

private:
	Symbol* funSym;
};

#endif // FUNCTIONCALLNODE_H
