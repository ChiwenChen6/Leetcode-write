  public class Solution
    {
        public int[] ConstructArray(int n, int k)
        {
            int[] res = new int[n];
            res[0] = 1;

            int diff = k;
            bool useHigh = true;
            for (int i = 1; i <= k; i++) {
                if (useHigh) {
                    res[i] = res[i - 1] + diff;
                }
                else {                    
                    res[i] = res[i - 1] - diff;
                }
                useHigh = !useHigh;
                diff--;
            }
            int val = res[1] + 1;
            for (int i = k + 1; i < n; i++) {
                res[i] = val++;
            }
            return res;
        }
    }


04/13/2021 10:16	Accepted	216 ms	29.4 MB	csharp
