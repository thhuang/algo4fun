/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y),
 * next(next) {};
 * };
 */

class Solution {
   public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode dummy;
        auto p = &dummy;
        auto p1 = poly1;
        auto p2 = poly2;

        while (p1 || p2) {
            int power = 0;
            if (p1) power = max(power, p1->power);
            if (p2) power = max(power, p2->power);

            int coefficient = 0;
            if (p1 && power == p1->power)
                coefficient += p1->coefficient, p1 = p1->next;
            if (p2 && power == p2->power)
                coefficient += p2->coefficient, p2 = p2->next;
            if (coefficient == 0) continue;

            p->next = new PolyNode(coefficient, power);
            p = p->next;
        }

        return dummy.next;
    }
};
