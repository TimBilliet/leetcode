public class Main {
    public static void main(String[] args) {
        System.out.println("int: " + myAtoi("0-1"));
    }

    public static int myAtoi(String s) {
        StringBuilder resultString = new StringBuilder();
        boolean tekenGelezen = false;
        boolean letterGedetecteerd = false;
        int aantalCijfers = 0;
        for (int i = 0; i < s.length(); i++) {
            char huidigChar = s.charAt(i);
            if (huidigChar != ' ') {
                if ((huidigChar == '-' || huidigChar == '+') && !tekenGelezen) {
                    if (aantalCijfers == 0) {
                        resultString.append(huidigChar);
                        tekenGelezen = true;
                    } else {
                        return Integer.parseInt(resultString.toString());
                    }
                } else if (huidigChar >= 'a' && huidigChar <= 'z') {
                    letterGedetecteerd = true;
                    if (aantalCijfers == 0) {
                        return 0;
                    }
                } else if (huidigChar >= '0' && huidigChar <= '9' && !letterGedetecteerd) {
                    resultString.append(huidigChar);
                    aantalCijfers++;
                }
            }
        }
        return Integer.parseInt(resultString.toString());
    }
}