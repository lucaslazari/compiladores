#ifndef FUNCTIONCALLNODE_H
#define FUNCTIONCALLNODE_H

#include <string>
#include <vector>
#include "node.h"

class FunctionCallNode : public Node {

public:
	FunctionCallNode(const std::string& functionName, std::vector<Node*>* children);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);

private:
	std::string functionName;
};

#endif // FUNCTIONCALLNODE_H
