class Solution {
    public int maxOperations(int[] nums, int k) {
        HashMap <Integer, Integer> map = new HashMap<>();
        int count=0;
        for(int i = 0; i < nums.length; i++)
        {
            if(map.containsKey(k - nums[i]) && map.get(k - nums[i])>0)
            {
                count++;
                map.put(k - nums[i],map.get(k - nums[i]) - 1);
            }
            else
            {
                 map.putIfAbsent(nums[i], 0);
                // int value=map.get(nums[i]);
                map.put(nums[i], map.get(nums[i]) + 1);
            }
           // System.out.println(map);
            
        }
        return count;
    }
}
