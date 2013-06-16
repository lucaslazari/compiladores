#include "programnode.h"
#include <stdio.h>
#include <sstream>

ProgramNode::ProgramNode(): Node("Programa", Common::NT_PROGRAM), initialAddress(1024) {
	this->isNewScope = true;
    this->hashTable = new Common::HashTable();
    Scope::pushScope(this);
}

void ProgramNode::printSourceCode(const std::string& end) {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++)
		(*it)->printSourceCode(";\n");
}

void ProgramNode::generateILOCCode() {
	std::stringstream initialAddressStr;
	initialAddressStr << this->initialAddress;
	std::string registerName = ILOC::getRegister("PROGRAM_BASE_ADDRESS");
	fprintf(this->flexOut, "%s", "loadI ");
	fprintf(this->flexOut, "%s", initialAddressStr.str().c_str());
	fprintf(this->flexOut, "%s", " => ");
	fprintf(this->flexOut, "%s", registerName.c_str());
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		(*it)->generateILOCCode();
	}
}
