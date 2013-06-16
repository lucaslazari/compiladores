#include "blocknode.h"
#include <stdio.h>

BlockNode::BlockNode(): Node("Bloco") {
	this->isNewScope = true;
	this->hashTable = new Common::HashTable();
    Scope::pushScope(this);
}

BlockNode::BlockNode(bool isNewScope): Node("Bloco") {
	this->isNewScope = isNewScope;
	if (this->isNewScope) {
		this->hashTable = new Common::HashTable();
        Scope::pushScope(this);
	}
}

void BlockNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", "{\n");
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		(*it)->printSourceCode(";\n");
	}
	fprintf(this->flexOut, "%s", "}\n");
}

void BlockNode::generateILOCCode() {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		(*it)->generateILOCCode();
	}
}
