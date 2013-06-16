#ifndef ASSIGNMENTNODE_H
#define ASSIGNMENTNODE_H

#include <string>
#include <vector>
#include "node.h"

class AssignmentNode : public Node {

public:
	AssignmentNode(const std::string& varName, Node* expressionAssigned);
	AssignmentNode(const std::string& varName, std::vector<Node*>* expressionIndexList, Node* expressionAssigned);
	void printSourceCode(const std::string& end);
	void generateILOCCode();

private:
	void generateILOCInstructions();
	std::string varName;
};

#endif // ASSIGNMENTNODE_H
