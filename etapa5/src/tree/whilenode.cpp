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

void WhileNode::generateILOCCode() {
	// while condição
	this->children->at(0)->generateILOCCode();
	// faça...
	this->children->at(1)->generateILOCCode();
}

void WhileNode::printILOC() {}