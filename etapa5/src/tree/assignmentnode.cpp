#include "assignmentnode.h"
#include <stdio.h>
#include <sstream>
#include "expression/expressionnode.h"

AssignmentNode::AssignmentNode(const std::string& varName, Node* expressionAssigned):
	Node("Atribuicao"), varName(varName) {
	this->addChild(expressionAssigned);;
	this->generateILOCInstructions();
}

AssignmentNode::AssignmentNode(const std::string& varName, std::vector<Node*>* expressionIndexList, Node* expressionAssigned):
	Node("Atribuicao"), varName(varName) {
	this->addChildren(expressionIndexList);
	this->addChild(expressionAssigned);
	this->generateILOCInstructions();
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

void AssignmentNode::generateILOCCode() {
	if (this->children->size() == 1) {
		this->children->at(0)->generateILOCCode();
	} else if (this->children->size() == 2) {
		this->children->at(0)->generateILOCCode();
		this->children->at(1)->generateILOCCode();
	}
}

void AssignmentNode::generateILOCInstructions() {
	Symbol* symbol = Scope::getSymbol(varName);
	int registerIndex = ILOC::requestRegister(varName);
	std::stringstream registerNameStream;
	registerNameStream << registerIndex;
	/*ILOC* instructionOne = new ILOC(Common::ILOC_LOADI, );
	ILOC* instructionTwo = new ILOC();*/
}