#include "NodeFactory.h"

Node* NodeFactory::createNode(int val) {
    return new Node(val);
}