#pragma once
#ifndef NODEFACTORY_H
#define NODEFACTORY_H
#include "node.h"

class NodeFactory {
public:
    static Node* createNode(int val);
};
#endif
