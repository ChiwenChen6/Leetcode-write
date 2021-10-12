/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n) {
    long int left;
    long int right;
    long int mid;
    long int ret;

    left = 1;
    right = n;
    while(left <= right) {
            mid = (left + right)/2;
            ret = guess(mid);
            if(ret == 0) {
                    return (mid);
            }
            if (ret == -1) {
                    right = mid - 1;
            }
            else {
                    left = mid + 1;
            }
    }
    return (-1);
}
