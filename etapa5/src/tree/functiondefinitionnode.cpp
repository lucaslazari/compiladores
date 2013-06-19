#include "functiondefinitionnode.h"
#include <stdio.h>
#include "headernode.h"
#include "blocknode.h"
#include "vardeclarationnode.h"

FunctionDefinitionNode::FunctionDefinitionNode():
	Node("Definicao de funcao", Common::NT_FUNCTION_DEFINITION) {
}

void FunctionDefinitionNode::setHeader(Node* header) {
	HeaderNode* headerNode = dynamic_cast<HeaderNode*>(header);

	if (Scope::isTokenInClosestScope(headerNode->getFunctionName()))
		yyerror("Funcao ja declarada.");
	else {
		Symbol * sym = new Symbol(headerNode->getFunctionName(), Common::FUNCTION, headerNode->getDataType());
		sym->setOffset(Scope::getScope()->getBaseAddr());
		Scope::popScope();
		Scope::addSymbol(sym);
	}

	this->addChild(header);
}

void FunctionDefinitionNode::setLocals(std::vector<Node*>* locals) {
	this->addChildren(locals);
}

void FunctionDefinitionNode::setBlock(Node* block) {
	this->addChild(block);
}

void FunctionDefinitionNode::printSourceCode(const std::string& end) {
	Node* header = this->children->at(0);
	header->printSourceCode("");
	if (this->children->size() == 2) {
		Node* block = this->children->at(1);
		fprintf(this->flexOut, "%s", " ");
		block->printSourceCode("\n");
	} else if (this->children->size() > 2) {
		Node* block = this->children->at(this->children->size()-1);
		int childrenSize = this->children->size() - 2 + 1;

		fprintf(this->flexOut, "%s", "\n");
		for (int i = 1; i < childrenSize; i++)
			this->children->at(i)->printSourceCode(";\n");

		block->printSourceCode("\n");
	}
}

void FunctionDefinitionNode::generateILOCCode(Node* context) {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		std::vector<ILOC*> instr = (*it)->getInstructions();

		this->instructions.reserve( this->instructions.size() + instr.size() ); // preallocate memory
		this->instructions.insert( this->instructions.end(), instr.begin(), instr.end() );

	}
}
