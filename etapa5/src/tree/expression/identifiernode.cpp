#include "identifiernode.h"
#include <stdio.h>
#include <iostream>

IdentifierNode::IdentifierNode(Symbol* symbol):
	ExpressionNode("Expressao idenficador", Common::EX_IDENTIFIER), symbol(symbol) {
	// TODO check the data type
	Symbol* sym = Scope::getSymbol(symbol->getText());
	this->dataType = sym->getDataType();
}

IdentifierNode::IdentifierNode(Symbol* symbol, std::vector<Node*>* expressionList):
	ExpressionNode("Expressao idenficador", Common::EX_IDENTIFIER), symbol(symbol) {
	// TODO check the data type	
	this->addChildren(expressionList);
	Symbol* sym = Scope::getSymbol(symbol->getText());
	this->dataType = sym->getDataType();
}

void IdentifierNode::printSourceCode(const std::string& end) {
	if (this->children->size() == 0)
		fprintf(this->flexOut, "%s", symbol->getText().c_str());
	else {
		fprintf(this->flexOut, "%s", symbol->getText().c_str());
		for (unsigned int i = 0; i < this->children->size(); i++) {
			fprintf(this->flexOut, "%s", "[");
			this->children->at(i)->printSourceCode("");
			fprintf(this->flexOut, "%s", "]");
		}
	}
}

void IdentifierNode::generateILOCCode() {
	if (this->children->size() == 1) {
		this->children->at(0)->generateILOCCode();
	}
}
