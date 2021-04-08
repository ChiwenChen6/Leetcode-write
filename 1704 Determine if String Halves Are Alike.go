func halvesAreAlike(s string) bool {
    l := len(s)
    x1 := 0
    x2 := 0
    for pos, x := range s{
        if pos < l/2{
            switch x{
                case 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U':
                    x1++
            }
        }else{
            switch x{
                case 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U':
                    x2++
            }
        }
    }
    return x1 == x2
}
// Status: Accepted
// Runtime: 0 ms
// Memory Usage: 2.2 MB
