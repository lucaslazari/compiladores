#ifndef OPERATIONNODE_H
#define OPERATIONNODE_H

#include "expressionnode.h"
#include "../common.h"

class OperationNode : public ExpressionNode {

public:
	OperationNode(const Common::OperationType& operationType, Node* leftSide, Node* rightSide);
	void printSourceCode(const std::string& end);
	std::string evaluate();
	void generateILOCCode();

private:
	Common::OperationType operationType;
	std::string value;
};

#endif // OPERATIONNODE_H
