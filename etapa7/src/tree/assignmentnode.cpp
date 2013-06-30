#include "assignmentnode.h"
#include <stdio.h>
#include <sstream>
#include "expression/expressionnode.h"
#include "expression/identifiernode.h"

AssignmentNode::AssignmentNode(Symbol* varAssigned, Node* expressionAssigned):
	Node("Atribuicao", Common::NT_ASSIGNMENT), varSym(varAssigned) {

	this->addChild(expressionAssigned);

	if (this->hasDeclaration(varAssigned)) {
		this->varSym = varAssigned;
		this->generateILOCCode(NULL);
	}

}

AssignmentNode::AssignmentNode(Symbol* varAssigned, std::vector<Node*>* expressionIndexList, Node* expressionAssigned):
	Node("Atribuicao", Common::NT_ASSIGNMENT), varSym(varAssigned) {

	this->addChildren(expressionIndexList);
	this->addChild(expressionAssigned);

	if (this->hasDeclaration(varAssigned)) {
		this->varSym = varAssigned;
		this->generateILOCCode(NULL);
	}
}

bool AssignmentNode::hasDeclaration(Symbol* sym) {
	bool found = true;
	if (!Scope::isTokenInScopes(sym->getText())) {
		yyerror("variable not declared");
		found = false;
	}
	return found;
}

void AssignmentNode::printSourceCode(const std::string& end) {
	if (this->children->size() == 1) {
		fprintf(this->flexOut, "%s", this->varSym->getText().c_str());
		fprintf(this->flexOut, "%s", " = ");
		this->children->at(0)->printSourceCode("");
		fprintf(this->flexOut, "%s", end.c_str());
	} else {
		fprintf(this->flexOut, "%s", this->varSym->getText().c_str());
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
		Symbol* symbol = Scope::getSymbol(this->varSym->getText());
		Node* symbolScope = Scope::getScope(this->varSym->getText());
		Node* expressionAssigned = this->children->at(0);
		std::string registerBaseAddress = (symbolScope->getNodeType() == Common::NT_PROGRAM) ? "rBSS" : "rFP";
		std::stringstream symbolOffsetStr;
		symbolOffsetStr << symbol->getOffset();

		std::vector<ILOC*> instr = expressionAssigned->getInstructions();

		this->instructions.insert( this->instructions.end(), instr.begin(), instr.end() );

		ILOC* instruction = new ILOC(Common::ILOC_STOREAI, expressionAssigned->getLastRegister(), "", registerBaseAddress, symbolOffsetStr.str());
		this->addInstruction(instruction);
	}
}
