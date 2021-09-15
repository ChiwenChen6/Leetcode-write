func reverseOnlyLetters(s string) string {
	ss := []byte(s)

	for i, j := 0, len(ss)-1; i<j; {
		if isAlpha(ss[i]) && isAlpha(ss[j]) {
			ss[i], ss[j] = ss[j], ss[i]
			i++
			j--
			continue
		}
		if !isAlpha(ss[i]) && !isAlpha(ss[j]) {
			i++
			j--
			continue
		}
		if isAlpha(ss[i]) {
			j--
			continue
		}
		i++
	}

	return string(ss)
}

func isAlpha(r byte) bool {
	return (r >= 'a' && r <= 'z') || (r >= 'A' && r <= 'Z')
}
