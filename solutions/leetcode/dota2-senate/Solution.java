class Solution {
    public String predictPartyVictory(String senate) {
        int rCount = 0, dCount = 0;
        int rBan = 0, dBan = 0;

        Queue<Character> q = new LinkedList<Character>();
        for (char c : senate.toCharArray()) {
            if (c == 'R') {
                ++rCount;
            } else {
                ++dCount;
            }
            q.add(c);
        }

        while (rCount > 0 && dCount > 0) {
            char c = q.poll();
            if (c == 'R') {
                if (dBan > 0) {
                    --dBan;
                    --rCount;
                    continue;
                }
                ++rBan;
            } else { // c == 'D'
                if (rBan > 0) {
                    --rBan;
                    --dCount;
                    continue;
                }
                ++dBan;
            }
            q.add(c);
        }

        return rCount > 0 ? "Radiant" : "Dire";
    }
}
