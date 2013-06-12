#include "blocknode.h"
#include <stdio.h>

BlockNode::BlockNode(std::vector<Node*>* children): Node("Bloco", children) {
	this->isNewScope = true;
	this->hashTable = new std::tr1::unordered_map<std::string, Symbol*>();
}

void BlockNode::printSourceCode(const std::string& end) {
  fprintf(this->flexOut, "%s", "{\n");
  for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
    (*it)->printSourceCode(";\n");
  }
	fprintf(this->flexOut, "%s", "}\n");
}
