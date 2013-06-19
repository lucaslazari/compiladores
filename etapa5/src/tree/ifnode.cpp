#include "ifnode.h"
#include "expression/expressionnode.h"
#include <stdio.h>

IfNode::IfNode(): Node("Se", Common::NT_IF) {
	this->setFalseLabel(ILOC::makeLabel());
	this->setTrueLabel(ILOC::makeLabel());
	this->setNextLabel(ILOC::makeLabel());
	//this->generateILOCCode(NULL);
}

IfNode::IfNode(Node* expression, Node* commandThen): Node("Se", Common::NT_IF) {
	this->setFalseLabel(ILOC::makeLabel());
	this->setTrueLabel(ILOC::makeLabel());
	this->setNextLabel(ILOC::makeLabel());
	this->addChild(expression);
	this->addChild(commandThen);
	//this->generateILOCCode(NULL);
}

IfNode::IfNode(Node* expression, Node* commandThen, Node* commandElse): Node("Se Senao", Common::NT_IF) {
	this->setFalseLabel(ILOC::makeLabel());
	this->setTrueLabel(ILOC::makeLabel());
	this->setNextLabel(ILOC::makeLabel());
	this->addChild(expression);
	this->addChild(commandThen);
	this->addChild(commandElse);
	//this->generateILOCCode(NULL);
}

void IfNode::printSourceCode(const std::string& end) {
	fprintf(this->flexOut, "%s", "se (");
	this->children->at(0)->printSourceCode("");
	fprintf(this->flexOut, "%s", ") entao\n");
	this->children->at(1)->printSourceCode("");
	if (this->children->size() == 3) {
		fprintf(this->flexOut, "%s", "senao\n");
		this->children->at(2)->printSourceCode("");
	}
}

void IfNode::generateILOCCode(Node* context) {
	Node* condition;
	Node* condTrue;
	Node*	condFalse;

	// gera o iloc da condição 'if'
	condition = dynamic_cast<Node*>(this->children->at(0));
	condition->generateILOCCode(NULL);

	// adiciona instrução de comparação de um registrador, pulando para determinado label
	ILOC* instruction = new ILOC(Common::ILOC_CBR, condition->getLastRegister(), "", this->getTrueLabel(), this->getFalseLabel());
	ILOC::addInstruction(instruction);

	// adiciona o label de condição verdadeira
	instruction = new ILOC(Common::ILOC_NOP, this->getTrueLabel(), "", "", "", "");
	ILOC::addInstruction(instruction);

	// gera o iloc do bloco 'then
	condTrue = dynamic_cast<Node*>(this->children->at(1));
	condTrue->generateILOCCode(NULL);

	// caso haja um bloco 'else'...
	if (this->children->size() == 3) {
		// adiciona jump incondicional para o próximo comando
		instruction = new ILOC(Common::ILOC_JUMPI, "", "", this->getNextLabel(), "");
		ILOC::addInstruction(instruction);

		// adiciona o label de condição falsa
		instruction = new ILOC(Common::ILOC_NOP, this->getFalseLabel(), "", "", "", "");
		ILOC::addInstruction(instruction);

		// gera o iloc do bloco 'else'
		condFalse = dynamic_cast<Node*>(this->children->at(2));
		condFalse->generateILOCCode(NULL);

		// adiciona o label de condição falsa
		instruction = new ILOC(Common::ILOC_NOP, this->getNextLabel(), "", "", "", "");
		ILOC::addInstruction(instruction);
	} else {
		// adiciona o label de condição falsa
		instruction = new ILOC(Common::ILOC_NOP, this->getFalseLabel(), "", "", "", "");
		ILOC::addInstruction(instruction);
	}
}
