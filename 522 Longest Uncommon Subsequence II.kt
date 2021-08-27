class Solution {
    fun findLUSlength(strs: Array<String>): Int {
        var len = -1
        for (i in 0 until strs.size) {
            var satisfied = true
            for (j in 0 until strs.size) {
                if (i == j) continue
                if (strs[i].isSubSeq(strs[j])) satisfied = false
            }
            if (satisfied) len = Math.max(len, strs[i].length)
        }
        return len
    }

    private fun String.isSubSeq(other: String): Boolean {
        if (this.length > other.length) return false
        var p = 0
        var q = 0
        while (p < this.length && q < other.length) {
            if (this[p] == other[q]) {
                p++
                q++
            } else {
                q++
            }
        }
        return p == this.length
    }
}
