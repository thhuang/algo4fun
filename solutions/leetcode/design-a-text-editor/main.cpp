class TextEditor {
    list<char> s;
    list<char>::iterator it = s.end();

   public:
    TextEditor() {}

    void addText(string text) {
        for (char c : text) {
            it = next(s.insert(it, c));
        }
    }

    int deleteText(int k) {
        auto l = it;

        int count = 0;
        for (int i = 0; i < k && l != s.begin(); ++i) --l, ++count;
        s.erase(l, it);

        return count;
    }

    string cursorLeft(int k) {
        for (int i = 0; i < k && it != s.begin(); ++i) --it;

        auto l = it;
        for (int i = 0; i < 10 && l != s.begin(); ++i) --l;

        string result;
        while (l != it) result.push_back(*l++);

        return result;
    }

    string cursorRight(int k) {
        for (int i = 0; i < k && it != s.end(); ++i) ++it;

        auto l = it;
        for (int i = 0; i < 10 && l != s.begin(); ++i) --l;

        string result;
        while (l != it) result.push_back(*l++);

        return result;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
