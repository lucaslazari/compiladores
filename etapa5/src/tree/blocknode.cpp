#include "blocknode.h"
#include <stdio.h>

BlockNode::BlockNode(): Node("Bloco", Common::NT_BLOCK) {
	this->isNewScope = true;
	this->hashTable = new Common::HashTable();
	this->baseAddr = Scope::scopeCount() * Common::scopeSize;
	this->currentOffset = 0;
	Scope::pushScope(this);
}

BlockNode::BlockNode(bool isNewScope): Node("Bloco", Common::NT_BLOCK) {
	this->isNewScope = isNewScope;
	if (this->isNewScope) {
		this->hashTable = new Common::HashTable();
		this->baseAddr = Scope::scopeCount() * Common::scopeSize;
		this->currentOffset = 0;
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
	if (this->isNewScope)
		Scope::pushScope(this);

	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		(*it)->generateILOCCode();
	}
}

void BlockNode::printILOC() {
	for (unsigned int i = 0; i < this->children->size(); i++)
		this->children->at(i)->printILOC();
}
