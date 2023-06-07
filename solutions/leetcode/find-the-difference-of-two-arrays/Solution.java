class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        HashSet<Integer> s1 = new HashSet<Integer>(Arrays.stream(nums1).boxed().toList());
        HashSet<Integer> s2 = new HashSet<Integer>(Arrays.stream(nums2).boxed().toList());
        List<Integer> res1 = s1.stream().filter(v -> !s2.contains(v)).collect(Collectors.toList());
        List<Integer> res2 = s2.stream().filter(v -> !s1.contains(v)).collect(Collectors.toList());
        return Arrays.asList(res1, res2);
    }
}

