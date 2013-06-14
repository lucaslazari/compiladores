#ifndef FUNCTIONDEFINITIONNODE_H
#define FUNCTIONDEFINITIONNODE_H

#include <string>
#include <vector>
#include "node.h"

class FunctionDefinitionNode : public Node {

public:
  FunctionDefinitionNode(Node* header, Node* block);
  FunctionDefinitionNode(Node* header, std::vector<Node*>* locals, Node* block);
  void printSourceCode(const std::string& end);
};

#endif // FUNCTIONDEFINITIONNODE_H
