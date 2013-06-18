#include "assignmentnode.h"
#include <stdio.h>
#include <sstream>
#include "expression/expressionnode.h"

AssignmentNode::AssignmentNode(const std::string& varName, Node* expressionAssigned):
	Node("Atribuicao", Common::NT_ASSIGNMENT), varName(varName) {
	this->addChild(expressionAssigned);
}

AssignmentNode::AssignmentNode(const std::string& varName, std::vector<Node*>* expressionIndexList, Node* expressionAssigned):
	Node("Atribuicao", Common::NT_ASSIGNMENT), varName(varName) {
	this->addChildren(expressionIndexList);
	this->addChild(expressionAssigned);
}

void AssignmentNode::printSourceCode(const std::string& end) {
	if (this->children->size() == 1) {
		fprintf(this->flexOut, "%s", this->varName.c_str());
		fprintf(this->flexOut, "%s", " = ");
		this->children->at(0)->printSourceCode("");
		fprintf(this->flexOut, "%s", end.c_str());
	} else {
		fprintf(this->flexOut, "%s", this->varName.c_str());
		for (unsigned int i = 0; i < this->children->size() - 1; i++) {
			fprintf(this->flexOut, "%s", "[");
			this->children->at(i)->printSourceCode("");
			fprintf(this->flexOut, "%s", "]");
		}
		fprintf(this->flexOut, "%s", " = ");
		this->children->at(this->children->size()-1)->printSourceCode("");
		fprintf(this->flexOut, "%s", end.c_str());
	}
}

void AssignmentNode::generateILOCCode(Node* context) {
	if (this->children->size() == 1) { // Variable
		Symbol* symbol = Scope::getSymbol(varName);
		Node* symbolScope = Scope::getScope(varName);
		Node* expressionAssigned = this->children->at(0);
		std::string registerBaseAddress = (symbolScope->getNodeType() == Common::NT_PROGRAM) ? "bss" : "fp";
		std::stringstream symbolOffsetStr;
		symbolOffsetStr << symbol->getOffset();
		expressionAssigned->generateILOCCode(this);
		ILOC* instruction = new ILOC(Common::ILOC_STOREAI, expressionAssigned->getLastRegister(), "", registerBaseAddress, symbolOffsetStr.str());
		this->instructions->push_back(instruction);
	}
}