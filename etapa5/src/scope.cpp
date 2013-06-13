#include "scope.h"

std::stack<Common::HashTable*> Scope::scopes;

Scope::Scope() {}

void Scope::pushScope(Common::HashTable* hashTable) {
	Scope::scopes.push(hashTable);
}

Common::HashTable* Scope::popScope() {
	Common::HashTable* scope = (Common::HashTable*)Scope::scopes.top();
	Scope::scopes.pop();
	return scope;
}

bool Scope::isTokenInScope(std::string& token) {
	// TODO
	return false;
}
