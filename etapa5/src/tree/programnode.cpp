#include "programnode.h"
#include <stdio.h>

ProgramNode::ProgramNode(): Node("Programa") {
	this->isNewScope = true;
	this->hashTable = new std::tr1::unordered_map<std::string, Symbol*>();
}

void ProgramNode::printSourceCode(const std::string& end) {
  for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++)
    (*it)->printSourceCode(";\n");
}
