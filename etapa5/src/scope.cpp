#include "scope.h"
#include <iostream>

std::deque<Common::HashTable*> Scope::scopes;

Scope::Scope() {}

void Scope::pushScope(Common::HashTable* hashTable) {
	Scope::scopes.push_front(hashTable);
}

Common::HashTable* Scope::popScope() {
	Common::HashTable* scope = (Common::HashTable*)Scope::scopes.front();
	Scope::scopes.pop_front();
	return scope;
}

bool Scope::isTokenInScopes(const std::string& token) {
	bool tokenExist = false;
	for (unsigned int i = 0; i < scopes.size(); i++) {
		Common::HashTable* scope = scopes[i];
		if (scope->find(token) != scope->end()) {
			tokenExist = true;
			break;
		}
	}
	return tokenExist;
}

bool Scope::isTokenInClosestScope(const std::string& token) {
	Common::HashTable* scope = (Common::HashTable*)Scope::scopes.front();
	if (scope->find(token) != scope->end())
		return true;
	else
		return false;
}

void Scope::addSymbol(Symbol* symbol) {
	Common::HashTable* scope = (Common::HashTable*)Scope::scopes.front();
	scope->insert(Common::HashTable::value_type(symbol->getText(), symbol));
}

Symbol* Scope::getSymbol(const std::string& token) {
	Common::HashTable* scope = (Common::HashTable*)Scope::scopes.front();
	Common::HashTable::iterator symbolPair = scope->find(token);
	return symbolPair->second;
}
