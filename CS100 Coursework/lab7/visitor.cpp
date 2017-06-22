#include "visitor.h"
#include <sstream>

PrintVisitor::PrintVisitor() : Visitor() { output = ""; };

void PrintVisitor::rootNode() {
    
}
void PrintVisitor::sqrNode() {
    output += " ^2 ";
}
void PrintVisitor::multNode() {
    output += " * ";
}
void PrintVisitor::subNode() {
    output += " - ";
}
void PrintVisitor::addNode() {
    output += " + ";
}
void PrintVisitor::opNode(Op* op) {
    std::ostringstream os;
    
    os << op->evaluate();
    
    string temp = os.str();
    
    output += temp;
}

void PrintVisitor::execute() {
    std::cout << output << " " << std::endl;
}
