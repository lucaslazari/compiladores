#ifndef PROGRAMNODE_H
#define PROGRAMNODE_H

#include <string>
#include "node.h"
#include "scope.h"

class ProgramNode : public Node {

public:
	ProgramNode();
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);
	void printILOC(FILE * f);

};

#endif // PROGRAMNODE_H
