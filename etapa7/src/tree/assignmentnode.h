#ifndef ASSIGNMENTNODE_H
#define ASSIGNMENTNODE_H

#include <string>
#include <vector>
#include "node.h"
#include "scope.h"

class AssignmentNode : public Node {

public:
	AssignmentNode(Symbol* varAssigned, Node* expressionAssigned);
	AssignmentNode(Symbol* varAssigned, std::vector<Node*>* expressionIndexList, Node* expressionAssigned);
	void printSourceCode(const std::string& end);
	void generateILOCCode(Node* context);
	bool hasDeclaration(Symbol* sym);


private:
	Symbol* varSym;
};

#endif // ASSIGNMENTNODE_H
