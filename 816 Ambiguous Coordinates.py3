class Solution:
    def ambiguousCoordinates(self, S: str) -> List[str]:
        S = S[1:-1]
        def numbers(s):
            ans = []
            for i in range(1, len(s)+1):
                ns = s[:i]
                if s[i:]:
                    ns += "." + s[i:]
                if len(ns) > 1 and (
                    ns[0] == '0' and ns[-1] == '0' or
                    ns[0] == '0' and ns[1] != '.' or
                    ns[-1] == '0' and '.' in ns):
                    continue
                ans.append(ns)    
            return ans        
        return ['(' + p[0] + ', ' + p[1] + ')'
               for i in range(1, len(S))
               for p in itertools.product(numbers(S[:i]), numbers(S[i:]))]
