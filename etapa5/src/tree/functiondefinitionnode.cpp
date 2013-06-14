#include "functiondefinitionnode.h"
#include <stdio.h>
#include "headernode.h"

FunctionDefinitionNode::FunctionDefinitionNode(Node* header, Node* block) : Node("Definicao de funcao") {
  this->addChild(header);
  this->addChild(block);

  HeaderNode* headerNode = dynamic_cast<HeaderNode*>(header);

  if (Scope::isTokenInClosestScope(headerNode->getFunctionName()))
    yyerror("Funcao ja declarada.");
  else
    Scope::addSymbol(new Symbol(headerNode->getFunctionName(), headerNode->getDataType()));
}

FunctionDefinitionNode::FunctionDefinitionNode(Node* header, std::vector<Node*>* locals, Node* block): Node("Definicao de funcao") {
  this->addChild(header);
  this->addChildren(locals);
  this->addChild(block);
}

void FunctionDefinitionNode::printSourceCode(const std::string& end) {
  Node* header = this->children->at(0);
  header->printSourceCode("");
  if (this->children->size() == 2) {
    Node* block = this->children->at(1);
    fprintf(this->flexOut, "%s", " ");
		block->printSourceCode("\n");
  } else if (this->children->size() > 2) {
    Node* block = this->children->at(this->children->size()-1);
    int childrenSize = this->children->size() - 2 + 1;

    fprintf(this->flexOut, "%s", "\n");
    for (int i = 1; i < childrenSize; i++)
			this->children->at(i)->printSourceCode(";\n");

		block->printSourceCode("\n");
  }
}
