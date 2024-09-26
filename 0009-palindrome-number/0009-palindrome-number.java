class Solution {
    public boolean isPalindrome(int x) {
   if (x < 0) {
            return false;
        }

        long y = 0;
        long z = x;

        while (z != 0) {
            int digit = (int) (z % 10);
            y = y * 10 + digit;
            z /= 10;
        }

        return (y == x);     
    }
}