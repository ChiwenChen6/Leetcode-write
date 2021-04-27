class Solution {
    
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        //heap
        PriorityQueue<Integer> climbTaken = new PriorityQueue<Integer>((a, b) -> (b - a));
        for(int i = 0; i < heights.length - 1; i++){
            int climb = heights[i + 1] - heights[i];
            
            if(climb > 0){
                climbTaken.add(climb);
                bricks -= climb;
                
                if(bricks < 0){        
                    if(ladders <= 0) 
                        return i;
                    ladders--;                    
                    int lastMaxclimb = climbTaken.remove();                
                    bricks += lastMaxclimb;                    
                }
            }
        }        
        return heights.length - 1;
    }
}


// Status: Accepted
// Runtime: 14 ms
// Memory Usage: 52.9 MB
