#include "programnode.h"
#include <stdio.h>
#include <iostream>


ProgramNode::ProgramNode(): Node("Programa") {
	this->isNewScope = true;
	this->hashTable = new Common::HashTable();
	Scope::pushScope(this->hashTable);
}

void ProgramNode::printSourceCode(const std::string& end) {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++)
		(*it)->printSourceCode(";\n");
}

void ProgramNode::generateILOCCode() {
		for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
				(*it)->generateILOCCode();
		}
}
