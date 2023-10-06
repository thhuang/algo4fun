class Logger {
    unordered_map<string, int> messageTimestamp;

   public:
    bool shouldPrintMessage(int timestamp, string message) {
        if (messageTimestamp.count(message) > 0 &&
            timestamp - messageTimestamp[message] < 10) {
            return false;
        }
        messageTimestamp[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
