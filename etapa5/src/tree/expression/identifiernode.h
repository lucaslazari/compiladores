#ifndef IDENTIFIERNODE_H
#define IDENTIFIERNODE_H

#include <string>
#include <vector>
#include "expressionnode.h"
#include "../../symbol.h"
#include "../../iloc.h"

class IdentifierNode : public ExpressionNode {

public:
	IdentifierNode(Symbol* symbol);
	IdentifierNode(Symbol* symbol, std::vector<Node*>* expressionList);
	void printSourceCode(const std::string& end);
	std::string evaluate();
	void generateILOCCode();

private:
	Symbol* symbol;
	Common::DataType dataType;
	std::string value;
};

#endif // IDENTIFIERNODE_H
