func detectCapitalUse(word string) bool {
    	return word == strings.ToUpper(word) || word[1:] == strings.ToLower(word)[1:]
}
