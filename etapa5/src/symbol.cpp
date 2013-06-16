#include "symbol.h"

Symbol::Symbol(const std::string& text, const Common::TokenType& tokenType): text(text), tokenType(tokenType) {}

Symbol::Symbol(const std::string& text, const Common::TokenType& tokenType, const Common::DataType& dataType): text(text), tokenType(tokenType), dataType(dataType) {}

Symbol::Symbol(const std::string& text, const Common::DataType& dataType): text(text), dataType(dataType) {}

std::string Symbol::getText() const {
	return text;
}

void Symbol::setText(const std::string &value) {
	this->text = value;
}

Common::DataType Symbol::getDataType() const {
	return dataType;
}

void Symbol::setDataType(const Common::DataType &value) {
	this->dataType = value;
}

Common::TokenType Symbol::getTokenType() const {
	return tokenType;
}

void Symbol::setTokenType(const Common::TokenType &value) {
	this->tokenType = value;
}

int Symbol::getCount() const {
	return count;
}

void Symbol::setCount(int value) {
	this->count = value;
}

std::string Symbol::getValue() const {
	return value;
}

void Symbol::setValue(const std::string& value) {
	this->value = value;
}
