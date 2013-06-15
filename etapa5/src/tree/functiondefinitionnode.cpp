#include "functiondefinitionnode.h"
#include <stdio.h>
#include "headernode.h"
#include "blocknode.h"
#include "vardeclarationnode.h"

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

  HeaderNode* headerNode = dynamic_cast<HeaderNode*>(header);
  BlockNode* blockNode = dynamic_cast<BlockNode*>(block);

  if (Scope::isTokenInClosestScope(headerNode->getFunctionName()))
    yyerror("Funcao ja declarada.");
  else
    Scope::addSymbol(new Symbol(headerNode->getFunctionName(), headerNode->getDataType()));

  // TODO
  /*for (unsigned int i = 1; i < (this->children->size() - 1); i++) {
    VarDeclarationNode* varDeclaration = dynamic_cast<varDeclaration*>(this->children->at(i));
    if (Scope::isTokenInClosestScope(varDeclaration->getVarName()))
      yyerror("Variavel local ja declarada no escopo.");
    else
      Scope::addSymbol(new Symbol(varDeclaration->getVarName(), varDeclaration->getDataType()));
  }*/
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

void FunctionDefinitionNode::generateILOCCode() {
    Node* header = this->children->at(0);
    header->generateILOCCode();

    if (this->children->size() == 2) {
        Node* block = this->children->at(1);
        block->generateILOCCode();
    } else if (this->children->size() > 2) {
        Node* block = this->children->at(this->children->size()-1);
        int childrenSize = this->children->size() - 2 + 1;

        for (int i = 1; i < childrenSize; i++) {
            this->children->at(i)->generateILOCCode();
        }

        block->generateILOCCode();
    }
}
