#include <string>
#include <iostream>

using namespace std;

class ChainLink {
private:
    string color;

public:
    ChainLink(string color) {
        this->color = color;
    }

    string get_color() {
        return this->color;
    }
};

class Node{
private:
    ChainLink link;
    Node* nextPtr;
public:
    Node(const ChainLink &link, Node *next) : link(link), nextPtr(next) {}
    void linkTo(Node* n);
    ChainLink getLink();
    Node* next();
};

void Node::linkTo(Node* n) {
    this->nextPtr = n;
}

ChainLink Node::getLink() {
    return this->link;
}

Node* Node::next() {
    return this->nextPtr;
}

void addLink(Node *n, Node* first) {
    if (first->next() == nullptr) {
        first->linkTo(n);
    }else {
        addLink(n, first->next());
    }
}

Node *linkAt(Node *first, int i) {
    if (i == 0) {
        return first;
    }
    return linkAt(first->next(), i-1);
}

int main(){
    ChainLink linkOne = ChainLink("red");
    ChainLink linkTwo = ChainLink("blue");
    ChainLink linkThree = ChainLink("green");
    ChainLink linkFour = ChainLink("yellow");

    Node n1 = Node(linkOne, nullptr);
    Node n2 = Node(linkTwo, nullptr);
    Node n3 = Node(linkThree, nullptr);

    n1.linkTo(&n2);
    n2.linkTo(&n3);

    //Add n4 to end:
    Node n4 = Node(linkFour, nullptr);
    addLink(&n4, &n1);
    cout << (n1.next()->next()->next())->getLink().get_color() << endl;//prints yellow

    //view third node:
    cout << linkAt(&n1, 2)->getLink().get_color() << endl;// prints green
    return 0;
}

