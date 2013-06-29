#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include "tree/common.h"

class Symbol {

public:
	Symbol(const std::string& text, const Common::TokenType& tokenType);
	Symbol(const std::string& text, const Common::TokenType& tokenType, const Common::DataType& dataType);
	Symbol(const std::string& text, const Common::DataType& dataType);
	Common::TokenType getTokenType() const;
	void setTokenType(const Common::TokenType& value);
	Common::DataType getDataType() const;
	void setDataType(const Common::DataType& value);
	std::string getText();
	void setText(const std::string& value);
	std::string getValue() const;
	void setValue(const std::string& value);
	void setOffset(int os);
	int getOffset();
	static int getDataTypeSize(Common::DataType dt);

private:
	std::string text;
	Common::TokenType tokenType;
	Common::DataType dataType;
	std::string value;
	int offset;
};

#endif // SYMBOL_H
