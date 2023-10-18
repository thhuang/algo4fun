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
        int lastRead = 0;
        while (n - actualRead >= 4) {
            lastRead = read4(buf + actualRead);
            actualRead += lastRead;
        }

        if (lastRead < 4) return actualRead;

        char buf4[4];
        lastRead = read4(buf4);
        for (int i = 0; i < min(lastRead, n - actualRead); ++i) {
            buf[actualRead++] = buf4[i];
        }

        return actualRead;
    }
};
