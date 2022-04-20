class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int val) : val(val), next(nullptr) {}
        ListNode(int val, ListNode* next) : val(val), next(next) {}
    };

    ListNode* first_ = nullptr;
    ListNode* last_ = nullptr;

    int length_ = 0;

   public:
    MyLinkedList() {}

    int get(int index) {
        if (index >= length_) return -1;
        auto p = first_;
        for (int i = 0; i < index; ++i) p = p->next;
        return p->val;
    }

    void addAtHead(int val) {
        if (length_ == 0) {
            first_ = last_ = new ListNode(val);
        } else {
            first_ = new ListNode(val, first_);
        }
        ++length_;
    }

    void addAtTail(int val) {
        if (length_ == 0) {
            first_ = last_ = new ListNode(val);
        } else {
            last_->next = new ListNode(val);
            last_ = last_->next;
        }
        ++length_;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > length_) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == length_) {
            addAtTail(val);
            return;
        }
        ListNode dummy{-1, first_};
        ListNode* p = &dummy;
        for (int i = 0; i < index; ++i) p = p->next;
        p->next = new ListNode(val, p->next);
        ++length_;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= length_) return;
        if (length_ == 1) {
            first_ = last_ = nullptr;
        } else if (index == 0) {
            auto d = first_;
            first_ = d->next;
            delete d;
        } else {
            ListNode dummy{-1, first_};
            ListNode* p = &dummy;
            for (int i = 0; i < index; ++i) p = p->next;
            ListNode* d = p->next;
            p->next = d->next;
            delete d;
            if (index == length_ - 1) last_ = p;
        }
        --length_;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
