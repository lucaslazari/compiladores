#include "vardeclarationnode.h"
#include <stdio.h>

VarDeclarationNode::VarDeclarationNode(const std::string& varName, Common::DataType dataType):
	Node("Declaracao de variavel", Common::NT_VAR_DECLARATION), varName(varName), dataType(dataType) {

	if (Scope::isTokenInClosestScope(varName)) {
		yyerror("Variavel ja declarada neste escopo.");
	} else {

		Symbol * sym = new Symbol(varName, Common::VARIABLE, dataType);
		Node* scope = Scope::getScope();

		// busca o deslocamento do escopo atual, esse será o deslocamento da nova variavel no escopo
		int coffest = scope->getCurrentOffset();
		sym->setOffset(coffest);
		// atualiza o deslocamento do escopo atual
		scope->setCurrentOffset(coffest + Symbol::getDataTypeSize(dataType));

		Scope::addSymbol(sym);
	}
}

Common::DataType VarDeclarationNode::getDataType() const {
	return dataType;
}

void VarDeclarationNode::setDataType(const Common::DataType& value) {
	dataType = value;
}

std::string VarDeclarationNode::getVarName() const {
	return varName;
}

void VarDeclarationNode::setVarName(const std::string& value) {
	varName = value;
}

void VarDeclarationNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", this->varName.c_str());
	fprintf(this->flexOut, "%s", ": ");
	fprintf(this->flexOut, "%s", this->dataTypeToString(this->dataType).c_str());
	fprintf(this->flexOut, "%s", end.c_str());
}

void VarDeclarationNode::generateILOCCode() {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		(*it)->generateILOCCode();
	}
}
