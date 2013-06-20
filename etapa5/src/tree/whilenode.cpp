#include "whilenode.h"
#include <stdio.h>

WhileNode::WhileNode(Node *expression, Node *command): Node("Enquanto", Common::NT_WHILE) {
	this->addChild(expression);
	this->addChild(command);
	this->setFalseLabel(ILOC::makeLabel());
	this->setTrueLabel(ILOC::makeLabel());
	this->setNextLabel(ILOC::makeLabel());
	this->generateILOCCode(NULL);
}

void WhileNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", "enquanto (");
	this->children->at(0)->printSourceCode("");
	fprintf(this->flexOut, "%s", ")\n");
	this->children->at(1)->printSourceCode(";\n");
}

std::string WhileNode::getFalseLabel() const {
	return falseLabel;
}

void WhileNode::setFalseLabel(const std::string &value) {
	falseLabel = value;
}

std::string WhileNode::getTrueLabel() const {
	return trueLabel;
}

void WhileNode::setTrueLabel(const std::string &value) {
	trueLabel = value;
}

void WhileNode::generateILOCCode(Node* context) {
	ILOC* instruction;

	// adiciona o label de condição falsa
	instruction = new ILOC(Common::ILOC_NOP, this->getFalseLabel(), "", "", "", "");
	this->addInstruction(instruction);

	// condição do while
	Node* condNode = dynamic_cast<Node*>(this->children->at(0));
	std::vector<ILOC*> condInstr = condNode->getInstructions();

	//condInstr.at(0)->setLabel();

	this->instructions.insert(this->instructions.end(), condInstr.begin(), condInstr.end());

	// adiciona instrução de comparação de um registrador, pulando para determinado label
	instruction = new ILOC(Common::ILOC_CBR, condNode->getLastRegister(), "", this->getTrueLabel(), this->getNextLabel());
	this->addInstruction(instruction);

	// adiciona o label de condição verdadeira
	instruction = new ILOC(Common::ILOC_NOP, this->getTrueLabel(), "", "", "", "");
	this->addInstruction(instruction);

	// código caso for verdadeiro
	Node* doNode = dynamic_cast<Node*>(this->children->at(1));
	std::vector<ILOC*> doInstr = doNode->getInstructions();

	this->instructions.insert(this->instructions.end(), doInstr.begin(), doInstr.end());

	// adiciona jump incondicional para a condição do while
	instruction = new ILOC(Common::ILOC_JUMPI, "", "", this->getFalseLabel(), "");
	this->addInstruction(instruction);

	// adiciona o label de condição verdadeira
	instruction = new ILOC(Common::ILOC_NOP, this->getNextLabel(), "", "", "", "");
	this->addInstruction(instruction);
}

