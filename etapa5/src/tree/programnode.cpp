#include "programnode.h"
#include <stdio.h>
#include <sstream>

ProgramNode::ProgramNode(): Node("Programa", Common::NT_PROGRAM) {
	this->isNewScope = true;
	this->hashTable = new Common::HashTable();
	this->baseAddr = 0;
	this->currentOffset = 0;
	Scope::pushScope(this);
}

void ProgramNode::printSourceCode(const std::string& end) {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++)
		(*it)->printSourceCode(";\n");
}

void ProgramNode::generateILOCCode() {
	std::stringstream baseAddrStr;
	baseAddrStr << this->baseAddr;
	std::string registerName = ILOC::getRegister("PROGRAM_BASE_ADDRESS");
	ILOC* instruction = new ILOC(Common::ILOC_LOADI, baseAddrStr.str(), "", registerName, "");
	this->instructions->push_back(instruction);
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		(*it)->generateILOCCode();
	}
}
