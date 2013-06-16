#ifndef FLOATEXPRESSION_H
#define FLOATEXPRESSION_H

#include <string>
#include "../common.h"
#include "expressionnode.h"

class FloatExpression {

public:
	FloatExpression();
	static std::string evaluate(const Common::OperationType& OperationType, Node* leftExpression, Node* rightExpression);
};

#endif // FLOATEXPRESSION_H
