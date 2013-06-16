#ifndef INTEGEREXPRESSION_H
#define INTEGEREXPRESSION_H

#include <string>
#include "../common.h"
#include "expressionnode.h"

class IntegerExpression {

public:
	IntegerExpression();
	static std::string evaluate(const Common::OperationType& operationType, Node* leftExpression, Node* rightExpression);
};

#endif // INTEGEREXPRESSION_H
