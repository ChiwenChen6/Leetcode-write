func findLUSlength(strs []string) int {
    sort.Slice(strs, func(i int, j int) bool {
        return len(strs[i]) < len(strs[j])
    })
    
    res := -1
    LOOP:
    for i := 0; i < len(strs); i++ {
        for j := 0; j < len(strs); j++ {
            if i == j || len(strs[j]) < len(strs[i]) {
                continue
            } else {
                if isSub(strs[i], strs[j]) {
                    continue LOOP
                }
            }
        }
        res = max(res, len(strs[i]))
    }
    return res
}

func isSub(short string, long string) bool {
    if len(short) == 0 {
        return true
    }
    i := 0
    for j := 0; j < len(long); j++ {
        if long[j] == short[i] {
            i++
        }
        if i >= len(short) {
            return true
        }
    }
    return false
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}
