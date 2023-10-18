/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
   public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int actualRead = 0;
        int lastRead = -1;
        while (n - actualRead >= 4 && lastRead != 0) {
            lastRead = read4(buf + actualRead);
            actualRead += lastRead;
        }

        if (0 <= lastRead && lastRead < 4) return actualRead;

        char buf4[4];
        lastRead = read4(buf4);
        for (int i = 0, m = min(lastRead, n - actualRead); i < m; ++i) {
            buf[actualRead++] = buf4[i];
        }

        return actualRead;
    }
};
