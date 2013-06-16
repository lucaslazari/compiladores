#include "integerexpression.h"
#include <cstdlib>
#include <sstream>

IntegerExpression::IntegerExpression() {}

std::string IntegerExpression::evaluate(const Common::OperationType& operationType, Node* leftExpression, Node* rightExpression) {
	ExpressionNode* left = dynamic_cast<ExpressionNode*>(leftExpression);
	ExpressionNode* right = dynamic_cast<ExpressionNode*>(rightExpression);
	int result;
	std::stringstream resultStr;

	switch (operationType) {
	case Common::OP_SUM:
		result = atoi(left->evaluate().c_str()) + atoi(right->evaluate().c_str());
		resultStr << result;
		break;
	default:
		break;
	}
	return resultStr.str();
}
