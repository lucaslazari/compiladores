#ifndef PROGRAMNODE_H
#define PROGRAMNODE_H

#include <string>
#include "node.h"
#include "scope.h"

class ProgramNode : public Node {

public:
	ProgramNode();
	void printSourceCode(const std::string& end);
	void generateILOCCode();
	void printILOC();

private:

};

#endif // PROGRAMNODE_H
