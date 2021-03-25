class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        int length = A.length;
        Arrays.sort(A);// sort A
        int [] res = new int [length];
        // priorityqueue based on b[0] - a[0]
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        // add the b values and index
        for (int i=0; i<B.length; i++) {
            pq.offer(new int []{B[i], i});
        }
        int left = 0;
        int right = length - 1;
        // until pq empty check
        // 1. A[right] > polled value from pq, if yes res[index] = A[right] else res[index] = A[left]
        while (!pq.isEmpty()) {
            int [] current = pq.poll();
            int value = current[0];
            int index = current[1];
            if (A[right] > value)
                res[index] = A[right--];
            else
                res[index] = A[left++];
        }
        return res;
    }
}
