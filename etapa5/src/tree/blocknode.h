#ifndef BLOCONODE_H
#define BLOCONODE_H

#include <vector>
#include "node.h"

class BlockNode : public Node {

public:
  BlockNode();
  void printSourceCode(const std::string& end);
};

#endif // BLOCONODE_H
