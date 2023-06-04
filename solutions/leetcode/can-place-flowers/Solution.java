class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        if (n == 0) {
            return true;
        }

        int m = flowerbed.length;

        List<Integer> data = new ArrayList<Integer>(m + 2);
        data.add(0);
        data.addAll(Arrays.stream(flowerbed).boxed().toList());
        data.add(0);

        for (int i = 1; i <= m; ++i) {
            if (data.get(i - 1) == 1 || data.get(i) == 1 || data.get(i + 1) == 1) {
                continue;
            }
            data.set(i, 1);
            --n;
            if (n == 0) {
                return true;
            }
        }

        return false;
    }

}

    
