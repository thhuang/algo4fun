/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> original2new;

        Node dummy(0);
        Node* p = &dummy;
        Node* node = head;

        while (node) {
            p->next = new Node(node->val);
            p->next->random = node->random;
            original2new[node] = p->next;

            p = p->next;
            node = node->next;
        }

        p = dummy.next;
        while (p) {
            p->random = original2new[p->random];
            p = p->next;
        }

        return dummy.next;
    }
};
