class Codec:
    def __init__(self):
        self.dic = {}
        self.i = 0
        self.baseURL = "http://tinyurl.com/"
        
    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        self.i += 1
        short = self.baseURL + str(self.i)
        self.dic[self.i] = longUrl
        return short

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        index = shortUrl.split(self.baseURL)

        if index[1]:
            long = self.dic.get(int(index[1]))

        return long   


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))


