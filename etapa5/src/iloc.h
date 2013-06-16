#ifndef ILOCNODE_H
#define ILOCNODE_H

#include <string>
#include "tree/common.h"
#include "symbol.h"

class ILOC {

public:
	ILOC(int type, Symbol *src1, Symbol *src2, Symbol *dst1,  Symbol *dst2);
    std::string codeline();

private:
	int type;
	Symbol *src1;
	Symbol *src2;
	Symbol *dst1;
	Symbol *dst2;
};

#endif // SYMBOL_H
