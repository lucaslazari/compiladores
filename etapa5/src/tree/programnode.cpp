#include "programnode.h"
#include <stdio.h>
#include <sstream>

ProgramNode::ProgramNode(): Node("Programa"), initialAddress(1024) {
	this->isNewScope = true;
    this->hashTable = new Common::HashTable();
    Scope::pushScope(this->hashTable);
}

void ProgramNode::printSourceCode(const std::string& end) {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++)
		(*it)->printSourceCode(";\n");
}

void ProgramNode::generateILOCCode() {
	std::stringstream initialAddressStr;
	initialAddressStr << this->initialAddress;
	fprintf(this->flexOut, "%s", "loadI ");
	fprintf(this->flexOut, "%s", initialAddressStr.str().c_str());
	fprintf(this->flexOut, "%s", " => r0");
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		(*it)->generateILOCCode();
	}
}
