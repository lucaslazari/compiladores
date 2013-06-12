#ifndef ILOCNODE_H
#define ILOCNODE_H

#include <string>
#include "tree/common.h"
#include "symbol.h"

class ILOC {

    public:

        ILOC::ILOC(int type, Symbol *src1, Symbol *src2, Symbol *dst1,  Symbol *dst2);
        void join(ILOC *n1);
        void print(ILOC *in);

    private:

        int type;

        Symbol *src1;
        Symbol *src2;
        Symbol *dst1;
        Symbol *dst2;

        ILOC *prev;
        ILOC *next;

};

#endif // SYMBOL_H
