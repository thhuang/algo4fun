class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int n = candies.length;
        int mx = Arrays.stream(candies).max().getAsInt();
        List<Boolean> result = new ArrayList<Boolean>(n);
        for (int v : candies) {
            result.add(v + extraCandies >= mx);
        }
        return result;
    }
}
