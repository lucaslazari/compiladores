#include "scope.h"
#include <iostream>

std::deque<Node*> Scope::scopes;

Scope::Scope() {}

void Scope::pushScope(Node* newScopeNode) {
	Scope::scopes.push_front(newScopeNode);
}

Node* Scope::popScope() {
	Node* scope = (Node*)Scope::scopes.front();
	Scope::scopes.pop_front();
	return scope;
}

Node* Scope::getScope() {
	Node* scope = (Node*)Scope::scopes.front();
	return scope;
}

bool Scope::isTokenInScopes(const std::string& token) {
	bool tokenExist = false;
	for (unsigned int i = 0; i < scopes.size(); i++) {
		Common::HashTable* scope = scopes[i]->getHashTable();
		if (scope->find(token) != scope->end()) {
			tokenExist = true;
			break;
		}
	}
	return tokenExist;
}

bool Scope::isTokenInClosestScope(const std::string& token) {
	Common::HashTable* scope = (Common::HashTable*)Scope::scopes.front()->getHashTable();
	if (scope->find(token) != scope->end())
		return true;
	else
		return false;
}

void Scope::addSymbol(Symbol* symbol) {
	Common::HashTable* scope = (Common::HashTable*)Scope::scopes.front()->getHashTable();
	scope->insert(Common::HashTable::value_type(symbol->getText(), symbol));
}

Symbol* Scope::getSymbol(const std::string& token) {
	bool tokenExist = false;
	Common::HashTable::iterator symbolPair;
	for (unsigned int i = 0; i < scopes.size(); i++) {
		Common::HashTable* scope = scopes[i]->getHashTable();
		symbolPair = scope->find(token);
		if (symbolPair != scope->end()) {
			tokenExist = true;
			break;
		}
	}
	if (tokenExist)
		return symbolPair->second;
	else
		return NULL;
}
