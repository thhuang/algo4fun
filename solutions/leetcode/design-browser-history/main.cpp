class BrowserHistory {
    int curr, lastStep;
    vector<string> history;

   public:
    BrowserHistory(string homepage)
        : curr{0}, lastStep{0}, history{{homepage}} {}

    void visit(string url) {
        lastStep = ++curr;

        if (history.size() > curr) {
            history[curr] = url;
        } else {
            history.push_back(url);
        }
    }

    string back(int steps) {
        curr = max(0, curr - steps);
        return history[curr];
    }

    string forward(int steps) {
        curr = min(lastStep, curr + steps);
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
