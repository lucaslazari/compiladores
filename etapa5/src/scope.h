#ifndef SCOPE_H
#define SCOPE_H

#include <stack>
#include <vector>
#include <tr1/unordered_map>
#include "tree/common.h"

class Scope {

public:
	Scope();
	static void pushScope(Common::HashTable* hashTable);
	static Common::HashTable* popScope();
	static bool isTokenInScope(std::string& token);

private:
	static std::stack<Common::HashTable*> scopes;
};

#endif // SCOPE_H
