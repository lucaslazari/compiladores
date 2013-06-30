#include "functioncallnode.h"
#include "scope.h"
#include <stdio.h>

FunctionCallNode::FunctionCallNode(Symbol* functionSym, std::vector<Node*>* children):
	//Node("Chamada de funcao", Common::NT_FUNCTION_CALL, children), funSym(functionSym) {
	ExpressionNode("Chamada de funcao", Common::EX_IDENTIFIER), symbol(functionSym) {

	this->addChildren(children);

	this->hasDeclaration(functionSym);

}

bool FunctionCallNode::hasDeclaration(Symbol* sym) {
	bool found = true;
	if (!Scope::isTokenInScopes(sym->getText())) {
		yyerror("function not declared");
		found = false;
	}
	return found;
}

void FunctionCallNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", this->symbol->getText().c_str());
	fprintf(this->flexOut, "%s", "(");
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++)
		(*it)->printSourceCode("");
	fprintf(this->flexOut, "%s", ")");
	fprintf(this->flexOut, "%s", end.c_str());
}

void FunctionCallNode::generateILOCCode(Node* context) {}
