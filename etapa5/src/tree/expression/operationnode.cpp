#include "operationnode.h"
#include <stdio.h>

OperationNode::OperationNode(const Common::OperationType& operationType, Node* leftSide, Node* rightSide):
	ExpressionNode("Expressao operation", Common::EX_OPERATION), operationType(operationType) {

	Common::DataType dataTypeExprLeft, dataTypeExprRight;

	if (leftSide != NULL) {
		this->addChild(leftSide);
		ExpressionNode* left = dynamic_cast<ExpressionNode*>(leftSide);
		dataTypeExprLeft = left->getDataType();
	}

	if (rightSide != NULL) {
		this->addChild(rightSide);
		ExpressionNode* right = dynamic_cast<ExpressionNode*>(rightSide);
		dataTypeExprRight = right->getDataType();
	}

	if (leftSide != NULL && rightSide != NULL) {
		if (dataTypeExprLeft != dataTypeExprRight)
			yyerror("tipos diferentes na expressao.");
		else
			this->dataType = dataTypeExprLeft;
	}
}

void OperationNode::printSourceCode(const std::string& end) {
	if (this->children->size() == 2) {
		this->children->at(0)->printSourceCode("");
		fprintf(this->flexOut, "%s", " ");
		fprintf(this->flexOut, "%s", this->operationTypeToString(this->operationType).c_str());
		fprintf(this->flexOut, "%s", " ");
		this->children->at(1)->printSourceCode("");
	} else if (this->children->size() == 1) {
		if (this->operationType == Common::OP_PAREN) {
			fprintf(this->flexOut, "%s", "(");
			this->children->at(0)->printSourceCode("");
			fprintf(this->flexOut, "%s", ")");
		} else if (this->operationType == Common::OP_SUB) {
			fprintf(this->flexOut, "%s", "-");
			this->children->at(0)->printSourceCode("");
		}
	}
}

void OperationNode::generateILOCCode(Node* context) {
	if (this->children->size() == 2) {
		ExpressionNode* left = dynamic_cast<ExpressionNode*>(this->children->at(0));
		ExpressionNode* right = dynamic_cast<ExpressionNode*>(this->children->at(1));
		switch (this->operationType) {
			case Common::OP_SUM: {
				left->generateILOCCode(this);
				right->generateILOCCode(this);
				std::string* operationRegister = ILOC::getRegister("@EX_SUM_REG");
				ILOC* instruction = new ILOC(Common::ILOC_ADD, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				ILOC::addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_SUB: {
				left->generateILOCCode(this);
				right->generateILOCCode(this);
				std::string* operationRegister = ILOC::getRegister("@EX_SUB_REG");
				ILOC* instruction = new ILOC(Common::ILOC_SUB, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				ILOC::addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_MULT: {
				left->generateILOCCode(this);
				right->generateILOCCode(this);
				std::string* operationRegister = ILOC::getRegister("@EX_MULT_REG");
				ILOC* instruction = new ILOC(Common::ILOC_MULT, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				ILOC::addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_DIV: {
				left->generateILOCCode(this);
				right->generateILOCCode(this);
				std::string* operationRegister = ILOC::getRegister("@EX_DIV_REG");
				ILOC* instruction = new ILOC(Common::ILOC_DIV, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				ILOC::addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_AND: {
				left->generateILOCCode(this);
				right->generateILOCCode(this);
				std::string* operationRegister = ILOC::getRegister("@EX_AND_REG");
				ILOC* instruction = new ILOC(Common::ILOC_AND, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				ILOC::addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			case Common::OP_OR: {
				left->generateILOCCode(this);
				right->generateILOCCode(this);
				std::string* operationRegister = ILOC::getRegister("@EX_OR_REG");
				ILOC* instruction = new ILOC(Common::ILOC_OR, left->getLastRegister(), right->getLastRegister(), *operationRegister, "");
				ILOC::addInstruction(instruction);
				this->setLastRegister(*operationRegister);
				break;
			}
			default:
				break;
		}
	}
}