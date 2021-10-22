class Solution:
    def frequencySort(self, s: str) -> str:
        maps={}
        for char in s:
            maps[char] = maps.get(char,0)+1
        mapList = sorted(maps.items(),key=lambda x:x[1])
        stringList = []
        for i in reversed(range(len(mapList))):
            stringList.append(mapList[i][0]*mapList[i][1])
        return "".join(stringList)
