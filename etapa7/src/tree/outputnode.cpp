#include "outputnode.h"
#include <stdio.h>

OutputNode::OutputNode(std::vector<Node*>* children): Node("Saida", Common::NT_OUTPUT, children) {}

void OutputNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", "saida ");
	for (unsigned int i = 0; i < this->children->size(); i++) {
		this->children->at(i)->printSourceCode("");
		if (i != this->children->size()-1)
			fprintf(this->flexOut, "%s", ", ");
	}
	fprintf(this->flexOut, "%s", ";\n");
}

void OutputNode::generateILOCCode(Node* context) {
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		std::vector<ILOC*> instr = (*it)->getInstructions();

		this->instructions.insert( this->instructions.end(), instr.begin(), instr.end() );
	}
}
