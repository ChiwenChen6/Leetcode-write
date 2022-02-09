class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, (a, b) -> b[1] - a[1]);  
        int res = 0;
        int i = 0;
        int load = 0;  
        while (truckSize > 0 && i < boxTypes.length) { 
            load = Math.min(truckSize, boxTypes[i][0]);    
            truckSize -= load;  
            res += load * boxTypes[i++][1]; 
        }
        return res;
    }
}
