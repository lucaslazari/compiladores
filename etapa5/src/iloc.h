#ifndef ILOCNODE_H
#define ILOCNODE_H

#include <string>
#include <vector>
#include <tr1/unordered_map>
#include "tree/common.h"
#include "symbol.h"
#define MAX_REGISTERS 200

typedef std::tr1::unordered_map<std::string, int> RegisterDictionary;

class ILOC {

public:
	ILOC(Common::ILOC_OperationType type, const std::string& src1, const std::string& src2, const std::string& dst1, const std::string& dst2);
	ILOC(Common::ILOC_OperationType type, const std::string& label, const std::string& src1, const std::string& src2, const std::string& dst1, const std::string& dst2);
	std::string codeline();
	static void initRegisters();
	static std::string* getRegister(const std::string& identifierName);
	static void returnRegister(const std::string& registerName);	
	static void addInstruction(ILOC* instruction);
	static void printILOC(FILE *f);

private:
	Common::ILOC_OperationType type;
	std::string label;
	std::string src1;
	std::string src2;
	std::string dst1;
	std::string dst2;
	static std::vector<std::string> registersBeingUsed;
	static RegisterDictionary registersByIdentifier;
	static std::vector<ILOC*> instructions;
};

#endif // SYMBOL_H
