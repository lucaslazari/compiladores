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

void OperationNode::generateILOCCode() {
	// TODO
	for (std::vector<Node*>::iterator it = this->children->begin(); it != this->children->end(); it++) {
		(*it)->generateILOCCode();
	}
}