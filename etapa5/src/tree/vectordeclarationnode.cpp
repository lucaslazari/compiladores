#include "vectordeclarationnode.h"
#include <stdio.h>
#include <sstream>

VectorDeclarationNode::VectorDeclarationNode(const std::string& vectorName, Common::DataType& dataType, std::vector<int>* dimensions):
	Node("Declaracao de vetor"), vectorName(vectorName), dataType(dataType), dimensions(dimensions) {
	if (Scope::isTokenInClosestScope(vectorName))
		yyerror("Vetor ja declarado neste escopo.");
	else
		Scope::addSymbol(new Symbol(vectorName, Common::VECTOR_VAR, dataType));	
}

void VectorDeclarationNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", this->vectorName.c_str());
	fprintf(this->flexOut, "%s", ": ");
	fprintf(this->flexOut, "%s", this->dataTypeToString(this->dataType).c_str());
	for (unsigned int i = 0; i < this->dimensions->size(); i++) {
		std::stringstream sizeStr;
		sizeStr << this->dimensions->at(i);
		fprintf(this->flexOut, "%s", "[");
		fprintf(this->flexOut, "%s", sizeStr.str().c_str());
		fprintf(this->flexOut, "%s", "]");
	}
	fprintf(this->flexOut, "%s", end.c_str());
}

void VectorDeclarationNode::generateILOCCode() {
	// ...
}
