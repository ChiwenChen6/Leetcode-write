    public int maxCount(int m, int n, int[][] ops) {
        int minX = Integer.MAX_VALUE, minY = Integer.MAX_VALUE;
        for (int[] op : ops) {
            minX = Math.min(op[0], minX);
            minY = Math.min(op[1], minY);
        }
        
        if (minX == Integer.MAX_VALUE && minY == Integer.MAX_VALUE) return m * n;
        return minX * minY;
    }
