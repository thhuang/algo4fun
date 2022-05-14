/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node* process(Node* head) {
        Node* p = head;
        Node* prev = nullptr;

        while (p) {
            if (!p->child) {
                prev = p;
                p = p->next;
                continue;
            }

            Node* p1 = p->next;
            Node* q0 = p->child;
            Node* q1 = process(q0);

            p->child = nullptr;
            p->next = q0;
            q0->prev = p;
            q1->next = p1;
            if (p1) p1->prev = q1;

            prev = q1;
            p = p1;
        }

        return prev;
    }

   public:
    Node* flatten(Node* head) {
        process(head);
        return head;
    }
};

class Solution {
   public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        function<Node*(Node*)> dfs = [&](Node* u) -> Node* {
            auto l = u->child;
            auto r = u->next;
            u->child = nullptr;

            if (l) {
                u->next = l;
                l->prev = u;
                u = dfs(l);
            }
            if (r) {
                u->next = r;
                r->prev = u;
                u = dfs(r);
            }

            return u;
        };

        dfs(head);

        return head;
    }
};
