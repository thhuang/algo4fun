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

class Solution {
    unordered_map<Node*, Node*> mp;

   public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        if (mp.count(head)) return mp[head];
        auto cp = mp[head] = new Node(head->val);
        cp->next = copyRandomList(head->next);
        cp->random = copyRandomList(head->random);
        return cp;
    }
};
