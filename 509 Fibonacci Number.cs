public class Solution {
    public int Fib(int n) {
        int first = 0;
        int second = 1;
        while (n-- > 0) {
            int tmp = first;
            first = second;
            second = tmp + second;
        }
        return first;
    }
}

//  04/16/2021 11:19	Accepted	32 ms	15.2 MB	csharp
