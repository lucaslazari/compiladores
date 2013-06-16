#include "iloc.h"

ILOC::ILOC(int type, Symbol *src1, Symbol *src2, Symbol *dst1, Symbol *dst2) {
	this->type = type;
	this->src1 = src1;
	this->src2 = src2;
	this->dst1 = dst1;
	this->dst2 = dst2;

    std::cout << this->codeline() << "\n";
}

std::string ILOC::codeline() {

    std::string line;

    switch(this->type) {
        case ILOC_NOP:
            line = "nop";
            break;
        case ILOC_ADD:
            line = "add " << src1->getText() << " " << src2->getText() << " => " << dst1->getText();
            break;
        case ILOC_SUB:
            line = "sub " << src1->getText() << " " << src2->getText() << " => " << dst1->getText();
            break;
        case ILOC_MULT:
            line = "";
            break;
        case ILOC_DIV:
            line = "";
            break;
        case ILOC_ADDI:
            line = "";
            break;
        case ILOC_SUBI:
            line = "";
            break;
        case ILOC_RSUBI:
            line = "";
            break;
        case ILOC_MULTI:
            line = "";
            break;
        case ILOC_DIVI:
            line = "";
            break;
        case ILOC_RDIVI:
            line = "";
            break;
        case ILOC_LSHIFT:
            line = "";
            break;
        case ILOC_LSHIFTI:
            line = "";
            break;
        case ILOC_RSHIFT:
            line = "";
            break;
        case ILOC_RSHIFTI:
            line = "";
            break;
        case ILOC_AND:
            line = "";
            break;
        case ILOC_ANDI:
            line = "";
            break;
        case ILOC_OR:
            line = "";
            break;
        case ILOC_ORI:
            line = "";
            break;
        case ILOC_XOR:
            line = "";
            break;
        case ILOC_XORI:
            line = "";
            break;
        case ILOC_LOADI:
            line = "";
            break;
        case ILOC_LOAD:
            line = "";
            break;
        case ILOC_LOADAI:
            line = "";
            break;
        case ILOC_LOADA0:
            line = "";
            break;
        case ILOC_CLOAD:
            line = "";
            break;
        case ILOC_CLOADAI:
            line = "";
            break;
        case ILOC_CLOADA0:
            line = "";
            break;
        case ILOC_STORE:
            line = "";
            break;
        case ILOC_STOREAI:
            line = "";
            break;
        case ILOC_STOREA:
            line = "";
            break;
        case ILOC_CSTORE:
            line = "";
            break;
        case ILOC_CSTOREAI:
            line = "";
            break;
        case ILOC_CSTOREA0:
            line = "";
            break;
        case ILOC_I2I:
            line = "";
            break;
        case ILOC_C2C:
            line = "";
            break;
        case ILOC_C2I:
            line = "";
            break;
        case ILOC_I2C:
            line = "";
            break;
        case ILOC_JUMPI:
            line = "";
            break;
        case ILOC_JUMP:
            line = "";
            break;
        case ILOC_CBR:
            line = "";
            break;
        case ILOC_CMP_LT:
            line = "";
            break;
        case ILOC_CMP_LE:
            line = "";
            break;
        case ILOC_CMP_EQ:
            line = "";
            break;
        case ILOC_CMP_GE:
            line = "";
            break;
        case ILOC_CMP_GT:
            line = "";
            break;
        case ILOC_CMP_NE:
            line = "";
            break;

    }
    return line;
}
