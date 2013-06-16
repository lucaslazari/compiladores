#include "iloc.h"
#include "tree/common.h""

ILOC::ILOC(int type, Symbol *src1, Symbol *src2, Symbol *dst1, Symbol *dst2) {
	this->type = type;
	this->src1 = src1;
	this->src2 = src2;
	this->dst1 = dst1;
	this->dst2 = dst2;

    //std::cout << this->codeline() << "\n";
}

std::string ILOC::codeline() {

    std::string line;

    switch(this->type) {
        // NOP
        case Common::ILOC_NOP:
            line = "nop";
            break;

        // Operações aritméticas (com registradores apenas)
        case Common::ILOC_ADD:
            line = "add " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_SUB:
            line = "sub " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_MULT:
            line = "mult " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_DIV:
            line = "div " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;

        // Operações aritméticas (com imediatos)
        case Common::ILOC_ADDI:
            line = "addI " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_SUBI:
            line = "subI " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_RSUBI:
            line = "rsubI " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_MULTI:
            line = "multI " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_DIVI:
            line = "divI " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_RDIVI:
            line = "rdivI " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;

        // Operações lógicas
        case Common::ILOC_LSHIFT:
            line = "lshift " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_LSHIFTI:
            line = "lshiftI " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_RSHIFT:
            line = "rshift " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_RSHIFTI:
            line = "rshiftI " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_AND:
            line = "and " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_ANDI:
            line = "andI " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_OR:
            line = "or " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_ORI:
            line = "orI " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_XOR:
            line = "xor " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_XORI:
            line = "xorI " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;

        // Operações sobre memória
        case Common::ILOC_LOADI:
            line = "loadI " + src1->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_LOAD:
            line = "load " + src1->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_LOADAI:
            line = "loadAI " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_LOADA0:
            line = "loadA0 " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_CLOAD:
            line = "cload " + src1->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_CLOADAI:
            line = "cloadAI " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_CLOADA0:
            line = "cloadA0 " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_STORE:
            line = "store " + src1->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_STOREAI:
            line = "storeAI " + src1->getText() + " => " + dst1->getText() + ", " + dst2->getText();
            break;
        case Common::ILOC_STOREA0:
            line = "storeA0 " + src1->getText() + " => " + dst1->getText() + ", " + dst2->getText();
            break;
        case Common::ILOC_CSTORE:
            line = "cstore " + src1->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_CSTOREAI:
            line = "cstoreAI " + src1->getText() + " => " + dst1->getText() + ", " + dst2->getText();
            break;
        case Common::ILOC_CSTOREA0:
            line = "cstoreA0 " + src1->getText() + " => " + dst1->getText() + ", " + dst2->getText();
            break;
        case Common::ILOC_I2I:
            line = "i2i " + src1->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_C2C:
            line = "c2c " + src1->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_C2I:
            line = "c2i " + src1->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_I2C:
            line = "i2c " + src1->getText() + " => " + dst1->getText();
            break;

        // Operações de fluxo de controle
        case Common::ILOC_JUMPI:
            line = "jumpI => " + dst1->getText();
            break;
        case Common::ILOC_JUMP:
            line = "jump  => " + dst1->getText();
            break;
        case Common::ILOC_CBR:
            line = "cbr " + src1->getText() + " => " + dst1->getText() + ", " + dst2->getText();
            break;
        case Common::ILOC_CMP_LT:
            line = "cmp_LT " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_CMP_LE:
            line = "cmp_LE " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_CMP_EQ:
            line = "cmp_EQ " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_CMP_GE:
            line = "cmp_GE " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_CMP_GT:
            line = "cmp_GT " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
        case Common::ILOC_CMP_NE:
            line = "cmp_NE " + src1->getText() + ", " + src2->getText() + " => " + dst1->getText();
            break;
    }

    return line;
}
