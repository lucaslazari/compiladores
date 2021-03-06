#include "inputnode.h"
#include <stdio.h>

InputNode::InputNode(const std::string& varName): Node("Entrada"), varName(varName) {}

void InputNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", "entrada ");
	fprintf(this->flexOut, "%s", varName.c_str());
	fprintf(this->flexOut, "%s", ";\n");
}
