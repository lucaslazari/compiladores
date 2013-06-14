#include "vardeclarationnode.h"
#include <stdio.h>

VarDeclarationNode::VarDeclarationNode(const std::string& varName, Common::DataType dataType):
	Node("Declaracao de variavel"), varName(varName), dataType(dataType) {	
  if (Scope::isTokenInClosestScope(varName))
    yyerror("Variavel ja declarada neste escopo.");
  else
    Scope::addSymbol(new Symbol(varName, dataType));
}

void VarDeclarationNode::printSourceCode(const std::string& end) {
  fprintf(this->flexOut, "%s", this->varName.c_str());
  fprintf(this->flexOut, "%s", ": ");
  fprintf(this->flexOut, "%s", this->dataTypeToString(this->dataType).c_str());
  fprintf(this->flexOut, "%s", end.c_str());
}
