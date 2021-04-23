public class Solution
{
    private Dictionary<int, int> counter = new Dictionary<int, int>();
    
    public int LeastBricks(IList<IList<int>> wall)
    {
        foreach(var row in wall)
        {
            for(int i = 0; i < row.Count-1; i++)
            {
                if(i > 0) row[i] += row[i-1];
                Valuecount(row[i]);
            }
        }
        int max = counter.Count > 0 ? counter.Max(kvp => kvp.Value) : 0;
        return wall.Count - max;
    }
    
    private void Valuecount(int val)
    {
        if(counter.ContainsKey(val)) counter[val]++;
        else counter[val] = 1;
    }
}
