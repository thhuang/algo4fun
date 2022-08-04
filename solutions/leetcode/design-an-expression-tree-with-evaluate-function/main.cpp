/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
   public:
    virtual ~Node(){};
    virtual int evaluate() const = 0;
};

class OpNode : public Node {
   public:
    OpNode(Node* left, Node* right) : _left(left), _right(right) {}

    ~OpNode() {
        delete _left;
        delete _right;
    }

   protected:
    Node* const _left;
    Node* const _right;
};

class Addition : public OpNode {
   public:
    Addition(Node* left, Node* right) : OpNode(left, right) {}

    int evaluate() const { return _left->evaluate() + _right->evaluate(); }
};

class Subtraction : public OpNode {
   public:
    Subtraction(Node* left, Node* right) : OpNode(left, right) {}

    int evaluate() const { return _left->evaluate() - _right->evaluate(); }
};

class Multiplication : public OpNode {
   public:
    Multiplication(Node* left, Node* right) : OpNode(left, right) {}

    int evaluate() const { return _left->evaluate() * _right->evaluate(); }
};

class Division : public OpNode {
   public:
    Division(Node* left, Node* right) : OpNode(left, right) {}

    int evaluate() const { return _left->evaluate() / _right->evaluate(); }
};

class Integer : public Node {
    int _val;

   public:
    Integer(int val) : _val(val) {}

    int evaluate() const { return _val; }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
   public:
    Node* buildTree(vector<string>& postfix) {
        vector<Node*> s;

        for (string token : postfix) {
            if (isdigit(token.front())) {
                s.push_back(new Integer(stoi(token)));
            } else {
                Node* r = s.back();
                s.pop_back();
                Node* l = s.back();
                s.pop_back();

                switch (token[0]) {
                    case '+':
                        s.push_back(new Addition(l, r));
                        break;
                    case '-':
                        s.push_back(new Subtraction(l, r));
                        break;
                    case '*':
                        s.push_back(new Multiplication(l, r));
                        break;
                    case '/':
                        s.push_back(new Division(l, r));
                        break;
                }
            }
        }

        return s.front();
    }
};

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
