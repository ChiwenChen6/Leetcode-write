int minSwaps (char * s) {
	int i, odd1 = 0, even1 = 0;

	for (i = 0; s[i]; i++) {
		if (s[i] == '1') {
			if (i & 1) {
				odd1++;
			} else {
				even1++;
			}
		}
	}

	if (odd1 + even1 < i / 2 || (i + 1) / 2 < odd1 + even1) {
		return -1;
	}

	if (i & 1) {
		return odd1 + even1 == i / 2 ? even1 : odd1;
	}

	return odd1 < even1 ? odd1 : even1;
}

// Runtime: 0 ms, faster than 100.00% of C online submissions for Minimum Number of Swaps to Make the Binary String Alternating.
// Memory Usage: 5.8 MB, less than 100.00% of C online submissions for Minimum Number of Swaps to Make the Binary String Alternating.
