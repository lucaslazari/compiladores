#include "literalnode.h"
#include <stdio.h>
#include <sstream>

LiteralNode::LiteralNode(const std::string& literal, const Common::DataType& dataType):
	ExpressionNode("Expressao literal", Common::EX_LITERAL, dataType), literal(literal) {}

void LiteralNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", literal.c_str());
}

void LiteralNode::generateILOCCode() {
	if (this->parent->getNodeType() == Common::NT_ASSIGNMENT) {
		std::string registerName = ILOC::getRegister(literal);
		ILOC* instruction = new ILOC(Common::ILOC_LOADI, literal, "", registerName, "");
		this->instructions->push_back(instruction);
		this->setLastRegister(registerName);
	}
}

void LiteralNode::printILOC() {
	for (unsigned int i = 0; i < this->instructions->size(); i++)
		fprintf(this->flexOut, "%s", this->instructions->at(i)->codeline().c_str());
}