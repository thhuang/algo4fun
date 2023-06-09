class Solution {
    public String removeStars(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (char c : s.toCharArray()) {
            if (c != '*') {
                stack.add(c);
            } else if (!stack.empty()) {
                stack.pop();
            }
        }
        return stack.stream().map(Object::toString).collect(Collectors.joining());
    }
}
