class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] map=new int[1001];
        for(int i=0;i<trips.length;i++) {
            for(int j=trips[i][1];j<trips[i][2];j++) {
                map[j]+=trips[i][0];
            }
        }
        int max=0;
        for(int i=0;i<map.length;i++) {
            max = max>map[i]?max : map[i];
            if(max>capacity) {
                return false;
            }
        }
        return true;
    }
}
