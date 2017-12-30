#include "node.h"

Node::Node(Node * p, State s, Moves* m, double u, int v, int t): //state is copied
	parent(p),  state(s), moves(m), utility(u), visits(v), type(t)
{
	children = new Children();
}

void Node::visit() {
	visits++;
}

void Node::addUtility(int score) {
	utility = ((utility* (visits - 1)) + score / 100.0) / static_cast<double>(visits);
}

int Node::getVisits() {
	return visits;
}

double Node::getUtility() {
	return utility;
}

Node* Node::getParent() {
	return parent;
}

State Node::getState() {
	return state;
}

Children* Node::getChildren() {
	return children;
}

void Node::addChild(Node* n) {
	children.push_back(n);
}

Moves * Node::getMoves()
{
	return nullptr;
}
