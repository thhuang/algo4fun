class Solution {
    private boolean isOpen(char c) {
        return c == '(' || c == '[' || c == '{';
    }

    private boolean isClose(char c) {
        return c == ')' || c == ']' || c == '}';
    }

    private boolean match(char open, char close) {
        return (open == '(' && close == ')') || 
               (open == '[' && close == ']') || 
               (open == '{' && close == '}');
    }

    public boolean isValid(String s) {
        var stack = new Stack<Character>();
        for (var c : s.toCharArray()) {
            if (isOpen(c)) {
                stack.add(c);
            } else if (isClose(c)) {
                if (stack.empty()) return false;
                if (!match(stack.pop(), c)) return false;
            }
        }
        return stack.empty();
    }
}
