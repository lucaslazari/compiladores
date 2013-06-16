#include "expressionnode.h"
#include "integerexpression.h"
#include "floatexpression.h"

ExpressionNode::ExpressionNode() {}

ExpressionNode::ExpressionNode(const std::string& name): Node(name) {}

ExpressionNode::ExpressionNode(const std::string& name, const Common::DataType& dataType): Node(name), dataType(dataType) {}

Common::DataType ExpressionNode::getDataType() const {
	return dataType;
}

void ExpressionNode::setDataType(const Common::DataType &value) {
	dataType = value;
}

std::string ExpressionNode::resolveExpression(const Common::OperationType& operationType, Node* leftSide, Node* rightSide) {
	std::string value;
	switch (operationType) {
	case Common::OP_SUM:
		if (this->dataType == Common::INT)
			value = IntegerExpression::evaluate(operationType, leftSide, rightSide);
		else if (this->dataType == Common::FLOAT)
			value = FloatExpression::evaluate(operationType, leftSide, rightSide);
		break;
	default:
		break;
	}
	return value;
}
