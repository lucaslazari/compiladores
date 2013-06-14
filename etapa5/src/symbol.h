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
	int getCount() const;
	void setCount(int value);
	std::string getText() const;
  void setText(const std::string& value);

private:
  std::string text;
  Common::TokenType tokenType;
	Common::DataType dataType;
	int count;
	Symbol* value;
	Symbol* next;
};

#endif // SYMBOL_H
