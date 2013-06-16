#include "literalnode.h"
#include <stdio.h>
#include <sstream>

LiteralNode::LiteralNode(const std::string& literal, const Common::DataType& dataType):
	ExpressionNode("Expressao literal", dataType), literal(literal) {}

void LiteralNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", literal.c_str());
}

void LiteralNode::generateILOCCode() {
	int registerIndex = ILOC::getRegister(literal);
	std::stringstream registerName;
	registerName << 'r' << registerIndex;
	ILOC* instruction = new ILOC(Common::ILOC_LOADI, literal, NULL, registerName.str(), NULL);
	this->instructions->push_back(instruction);
}
