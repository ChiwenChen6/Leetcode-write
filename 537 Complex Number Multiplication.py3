class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        x1, x1i = map(int, num1[:-1].split('+'))
        x2, x2i = map(int, num2[:-1].split('+'))
        return f"{x1*x2 - x1i*x2i}+{x1*x2i + x2*x1i}i"
