// Node.cpp
// Haoran Zhang
#include "node.h"

Node::Node(Node* parent, State state, Moves m, double utility, int visits, int type): //state is copied
	parent(parent),  state(state), moves(m), utility(utility), visits(visits), type(type)
{
	children = new Children();
}

Node::Node(Node& node):
	Node(node.parent, node.state, node.moves , node.utility, node.visits, node.type)
{

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
	children->push_back(n);
}

Moves Node::getMoves() //return copy
{
	return moves;
}
