class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        var stack = new Stack<Integer>();
        for (int v : asteroids) {
            while (!stack.empty() && stack.peek() > 0 && stack.peek() + v < 0) {
                stack.pop();
            }
            if (!stack.empty() && stack.peek() > 0 && stack.peek() + v == 0) {
                stack.pop();
                continue;
            } else if (!stack.empty() && stack.peek() > 0 && v < 0) {
                continue;
            }
            stack.add(v);
        }
        return stack.stream().mapToInt(v -> v).toArray();
    }
}
