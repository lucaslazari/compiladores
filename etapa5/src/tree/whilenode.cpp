#include "whilenode.h"
#include <stdio.h>

WhileNode::WhileNode(Node *expression, Node *command): Node("Enquanto", Common::NT_WHILE) {
	this->addChild(expression);
	this->addChild(command);
}

void WhileNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", "enquanto (");
	this->children->at(0)->printSourceCode("");
	fprintf(this->flexOut, "%s", ")\n");
	this->children->at(1)->printSourceCode(";\n");
}

void WhileNode::generateILOCCode(Node* context) {}

std::string WhileNode::getFalseLabel() const {
	return falseLabel;
}

void WhileNode::setFalseLabel(const std::string &value) {
	falseLabel = value;
}

std::string WhileNode::getTrueLabel() const {
	return trueLabel;
}

void WhileNode::setTrueLabel(const std::string &value) {
	trueLabel = value;
}
