class Solution:

    def calculate(self, s: str) -> int:
        numbers = {str(x) for x in range(10)}
        st = []
        num = ""
        for c in "("+s+")":
            if num and not c.isnumeric():
                if st and st[-1] == "-":
                    st[-1] = -int(num)
                elif st and isinstance(st[-1], int):
                    st[-1] += int(num)
                else:
                    st.append(int(num))
                num = ""
            if c.isnumeric():
                num += c
            elif c == "(" or c == "-":
                st.append(c)
            elif c == ")": 
                squash = 0 
                while st:
                    c = st.pop()
                    if c == "(":
                        break
                    squash += c
                if st and st[-1] == "-":
                    st[-1] = -squash
                else:
                    st.append(squash)
        return sum(st)
