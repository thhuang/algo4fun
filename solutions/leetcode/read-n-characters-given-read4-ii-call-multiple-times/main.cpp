/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
    char bufRemain[4];
    int remain = 0;

   public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int actualRead = 0;

        if (remain > 0) {
            if (n <= remain) {
                memcpy(buf, bufRemain, n);
                for (int i = 0; i < remain - n; ++i) {
                    bufRemain[i] = bufRemain[i + n];
                }
                actualRead += n;
                remain -= n;
            } else {
                memcpy(buf, bufRemain, remain);
                actualRead += remain;
                remain = 0;
            }
        }

        if (actualRead == n) return n;

        int lastRead = -1;
        while (n - actualRead >= 4 && lastRead != 0) {
            lastRead = read4(buf + actualRead);
            actualRead += lastRead;
        }

        if (0 <= lastRead && lastRead < 4) return actualRead;

        char buf4[4];
        lastRead = read4(buf4);

        int m = min(lastRead, n - actualRead);
        for (int i = 0; i < m; ++i) {
            buf[actualRead++] = buf4[i];
        }

        if (int d = lastRead - m; d > 0) {
            for (int i = m; i < lastRead; ++i) {
                bufRemain[i - m] = buf4[i];
            }
            remain = d;
        }

        return actualRead;
    }
};
