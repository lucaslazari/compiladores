#include "iloc.h"

ILOC::ILOC(int type, Symbol *src1, Symbol *src2, Symbol *dst1, Symbol *dst2) {
	this->type = type;
	this->src1 = src1;
	this->src2 = src2;
	this->dst1 = dst1;
	this->dst2 = dst2;
	this->prev = 0;
	this->next = 0;
}

void ILOC::join(ILOC *n1, ILOC *n2) {
/*
	ILOC *t = *this;

	while (this->prev) {
		t = t->prev;
	}

	t->prev = n1;
	n1->next = *this;
*/
}

void ILOC::print(ILOC *in) {

}
