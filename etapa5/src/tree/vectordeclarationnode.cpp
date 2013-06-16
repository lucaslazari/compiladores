#include "vectordeclarationnode.h"
#include <stdio.h>
#include <sstream>

VectorDeclarationNode::VectorDeclarationNode(const std::string& vectorName, Common::DataType& dataType, std::vector<int>* dimensions):
	Node("Declaracao de vetor"), vectorName(vectorName), dataType(dataType), dimensions(dimensions) {
	if (Scope::isTokenInClosestScope(vectorName)) {
		yyerror("Vetor ja declarado neste escopo.");
	} else {

		Symbol * sym = new Symbol(vectorName, Common::VECTOR_VAR, dataType);

		// busca o deslocamento do escopo atual, esse será o deslocamento da nova variavel no escopo
		sym->setOffset(this->getCurrentOffset());
		// calcula o deslocamento do vetor varrendo a lista de dimensões do mesmo
		int size = 0;
		int dtSize = Symbol::getDataTypeSize(dataType);
		for (int i = 0; i < dimensions->size(); i++) {
			size += dimensions->at(i) * dtSize;
		}

		// atualiza o deslocamento do escopo atual
		this->setCurrentOffset(this->getCurrentOffset() + size);

		Scope::addSymbol(sym);
	}
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
