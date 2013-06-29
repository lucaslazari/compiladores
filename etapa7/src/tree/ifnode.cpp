#include "ifnode.h"
#include "expression/expressionnode.h"
#include <stdio.h>

IfNode::IfNode(): Node("Se", Common::NT_IF) {
	this->setFalseLabel(ILOC::makeLabel());
	this->setTrueLabel(ILOC::makeLabel());
	this->setNextLabel(ILOC::makeLabel());
	this->generateILOCCode(NULL);
}

IfNode::IfNode(Node* expression, Node* commandThen): Node("Se", Common::NT_IF) {
	this->setFalseLabel(ILOC::makeLabel());
	this->setTrueLabel(ILOC::makeLabel());
	this->setNextLabel(ILOC::makeLabel());
	this->addChild(expression);
	this->addChild(commandThen);
	this->generateILOCCode(NULL);
}

IfNode::IfNode(Node* expression, Node* commandThen, Node* commandElse): Node("Se Senao", Common::NT_IF) {
	this->setFalseLabel(ILOC::makeLabel());
	this->setTrueLabel(ILOC::makeLabel());
	this->setNextLabel(ILOC::makeLabel());
	this->addChild(expression);
	this->addChild(commandThen);
	this->addChild(commandElse);
	this->generateILOCCode(NULL);
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
	ILOC* instruction;

	// condição do if
	Node* condNode = dynamic_cast<Node*>(this->children->at(0));
	std::vector<ILOC*> condInstr = condNode->getInstructions();

	// instruções geradas pelo nó de condições
	this->instructions.insert(this->instructions.end(), condInstr.begin(), condInstr.end());

	// adiciona instrução de comparação de um registrador, pulando para determinado label
	instruction = new ILOC(Common::ILOC_CBR, condNode->getLastRegister(), "", this->getTrueLabel(), this->getFalseLabel());
	this->addInstruction(instruction);

	// código caso for verdadeiro
	Node* thenNode = dynamic_cast<Node*>(this->children->at(1));
	std::vector<ILOC*> thenInstr = thenNode->getInstructions();

	if (!thenInstr.at(0)->hasLabel()) {
		thenInstr.at(0)->setLabel(this->getTrueLabel());
	} else {
		// adiciona o label de condição falsa
		instruction = new ILOC(Common::ILOC_NOP, this->getTrueLabel(), "", "", "", "");
		this->addInstruction(instruction);
	}

	// instruções geradas pelo nó de código "verdadeiro"
	this->instructions.insert(this->instructions.end(), thenInstr.begin(), thenInstr.end());

	// código caso houver um else
	if (this->children->size() == 3) {
		Node* elseNode = dynamic_cast<Node*>(this->children->at(2));
		std::vector<ILOC*> elseInstr = elseNode->getInstructions();

		// adiciona jump incondicional para o próximo comando
		instruction = new ILOC(Common::ILOC_JUMPI, "", "", this->getNextLabel(), "");
		this->addInstruction(instruction);

		if (!elseInstr.at(0)->hasLabel()) {
			elseInstr.at(0)->setLabel(this->getFalseLabel());
		} else {
			// adiciona o label de condição falsa
			instruction = new ILOC(Common::ILOC_NOP, this->getFalseLabel(), "", "", "", "");
			this->addInstruction(instruction);
		}

		// instruções geradas pelo nó de código "verdadeiro"
		this->instructions.insert(this->instructions.end(), elseInstr.begin(), elseInstr.end());

		// adiciona o label para o próximo trecho de código a ser executado
		instruction = new ILOC(Common::ILOC_NOP, this->getNextLabel(), "", "", "", "");
		this->addInstruction(instruction);
	} else {
		// adiciona o label de condição falsa
		instruction = new ILOC(Common::ILOC_NOP, this->getFalseLabel(), "", "", "", "");
		this->addInstruction(instruction);
	}
}
