#ifndef ILOCNODE_H
#define ILOCNODE_H

#include <string>
#include "tree/common.h"
#include "symbol.h"

class ILOC {

public:
    ILOC(int type, std::string src1, std::string src2, std::string dst1, std::string dst2);
    std::string codeline();

private:
	int type;
    std::string src1;
    std::string src2;
    std::string dst1;
    std::string dst2;
};

#endif // SYMBOL_H
