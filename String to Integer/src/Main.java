public class Main {
    public static void main(String[] args) {
        System.out.println("int: " + myAtoi("0-1"));
    }

    public static int myAtoi(String s) {
        int resultaat = 0;
        StringBuilder resultString = new StringBuilder();
        boolean signRead = false;
        boolean letterDetected = false;
        int aantalWhite = 0;
        int aantalCijfers = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) != ' ') {

                if ((s.charAt(i) == '-' || s.charAt(i) == '+') && !signRead) {
                    signRead = true;
                    if(aantalCijfers == 0) {
                        resultString.append(s.charAt(i));
                    } else {
                        System.out.println("happens");
                        return Integer.parseInt(resultString.toString());

                    }
                }
                if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
                    letterDetected = true;
                    if(aantalCijfers == 0) {
                        return 0;
                    }
                }
                if(s.charAt(i) >= '0' && s.charAt(i) <= '9' && !letterDetected) {
                    resultString.append(s.charAt(i));
                    aantalCijfers++;
                }

            } else {
                aantalWhite++;
            }

        }
        System.out.println(resultString);
        return Integer.parseInt(resultString.toString());
    }
}