public class Main {
    public static void main(String[] args) {
        System.out.println("int: " + myAtoi("1337c0d3"));
    }

    public static int myAtoi(String s) {
        int resultaat = 0;
        StringBuilder resultString = new StringBuilder();
        boolean signRead = false;
        boolean letterDetected = false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '-' && s.charAt(i) == '+' && !signRead) {
                resultString.append(s.charAt(i));
                signRead = true;
            }

            if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
                letterDetected = true;
            }
            if (s.charAt(i) != ' ' && s.charAt(i) >= '0' && s.charAt(i) <= '9' && signRead) {
               resultString.append(s.charAt(i));
            }
        }
        System.out.println(resultString);
        return resultaat;
    }
}