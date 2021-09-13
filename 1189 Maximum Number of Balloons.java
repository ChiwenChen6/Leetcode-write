class Solution {
    public int maxNumberOfBalloons(String text) {
        if(text == null || text.length() < 7) {
            return 0;
        }
        int[] freq = new int[5];

        for(int i : text.toCharArray()) {

            if(i == 'b') {
                freq[0]++;
            }
            else if(i == 'a') {
                freq[1]++;
            }
            else if(i == 'l') {
                freq[2]++;
            }
            else if(i == 'o') {
                freq[3]++;
            }
            else if(i == 'n'){
                freq[4]++;
            }

        }
        int min1 = Math.min(Math.min(freq[0], freq[1]), freq[4]);
        int min2 = Math.min(freq[2], freq[3]);
        return Math.min(min1, (min2 / 2));
    }
        
}
