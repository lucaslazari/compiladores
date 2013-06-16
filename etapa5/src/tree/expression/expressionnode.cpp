#include "expressionnode.h"

ExpressionNode::ExpressionNode() {}

ExpressionNode::ExpressionNode(const std::string& name): Node(name) {}

ExpressionNode::ExpressionNode(const std::string& name, const Common::DataType& dataType): Node(name), dataType(dataType) {}

Common::DataType ExpressionNode::getDataType() const {
	return dataType;
}

void ExpressionNode::setDataType(const Common::DataType &value) {
	dataType = value;
}