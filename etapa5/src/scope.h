#ifndef SCOPE_H
#define SCOPE_H

#include <deque>
#include <vector>
#include <tr1/unordered_map>
#include "tree/common.h"
#include "tree/node.h"
#include "symbol.h"

class Scope {

public:
	Scope();
    static void pushScope(Node * newScopeNode);
    static Node* popScope();
	static bool isTokenInScopes(const std::string& token);
	static bool isTokenInClosestScope(const std::string& token);
	static void addSymbol(Symbol* symbol);
	static Symbol* getSymbol(const std::string& token);

private:
    static std::deque<Node*> scopes;
};

#endif // SCOPE_H
