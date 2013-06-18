#include "identifiernode.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

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

void IdentifierNode::generateILOCCode(Node* context) {
	if (this->children->size() == 0) { // Variable
		Symbol* symbol = Scope::getSymbol(this->symbol->getText());
		Node* symbolScope = Scope::getScope(this->symbol->getText());
		std::string* varAddressRegisterName = ILOC::getRegister("@ADDR" + symbol->getText());
		std::string registerBaseAddress = (symbolScope->getNodeType() == Common::NT_PROGRAM) ? "bss" : "fp";
		std::stringstream symbolOffsetStr;
		symbolOffsetStr << symbol->getOffset();
		ILOC* instruction = new ILOC(Common::ILOC_LOADAI, registerBaseAddress, symbolOffsetStr.str(), *varAddressRegisterName, "");
		ILOC::instructions.push_back(instruction);
		this->setLastRegister(*varAddressRegisterName);
	}
}
