class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        wordSet = set(words)
        longestPathLengths = dict()

        def longestChainHelper(word):
            if word in longestPathLengths:
                return longestPathLengths[word]

            longestPathLengths[word] = 1
            for c in range(0, len(word)):
                smallWord = word[0:c] + word[c+1:]
                if smallWord in wordSet:
                    longestPathLengths[word] = max(longestChainHelper(smallWord) + 1, longestPathLengths[word])

            return longestPathLengths[word]

        for i in range(0, len(words)):
            longestChainHelper(words[i])

        return max(longestPathLengths.values())
