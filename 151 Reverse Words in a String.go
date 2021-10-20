func reverseWords(s string) string {
    i, n, res := 0, len(s), ""
    for i < n {
        for i < n && s[i] == ' ' { i++ }
        if i == n { break }
        j := i
        for j < n && s[j] != ' ' { j++ }
        if len(res) == 0 {
            res = s[i : j]
        } else {
            res = s[i : j] + " " + res
        }
        i = j + 1
    }
    return res
}
