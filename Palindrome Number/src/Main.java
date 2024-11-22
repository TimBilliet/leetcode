public class Main {
    public static void main(String[] args) {
        System.out.println(isPalindrome(121));

    }



    public static boolean isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        String xStr = String.valueOf(x);
        for(int i = 0; i < xStr.length(); i++) {
            char left = xStr.charAt(i);
            char right = xStr.charAt(xStr.length()-1-i);
            if(left != right) {
                return false;
            }
        }
        return true;
    }
}