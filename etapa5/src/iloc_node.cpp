#include "iloc_node.h"

ILOC::ILOC(int type, Symbol *src1, Symbol *src2, Symbol *dst1, Symbol *dst2) {

    this->type = type;

    this->src1 = src1;
    this->src2 = src2;
    this->dst1 = dst1;
    this->dst2 = dst2;

    this->prev = 0;
    this->next = 0;

}

void join(ILOC *n1) {

}

void print(ILOC *in) {

}
