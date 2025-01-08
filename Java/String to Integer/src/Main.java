public class Main {
    public static void main(String[] args) {
        System.out.println("int: " + myAtoi("  +  413"));//4193 with
    }

    public static int myAtoi(String s) {
        StringBuilder resultString = new StringBuilder();
        boolean tekenGelezen = false;
        boolean letterGedetecteerd = false;
        int aantalCijfers = 0;
        int resultaat = 0;
        char teken = 0;
        for (int i = 0; i < s.length(); i++) {
            char huidigChar = s.charAt(i);
            if (huidigChar != ' ') {
                if ((huidigChar == '-' || huidigChar == '+')) {
                    if (!tekenGelezen) {
                        if (aantalCijfers == 0) {
                            resultString.append(huidigChar);
                            tekenGelezen = true;
                            teken = huidigChar;
                        } else {
                            break;
                        }
                    } else {
                        if(aantalCijfers > 0) {
                            break;
                        } else {
                            return 0;
                        }
                    }
                } else if (huidigChar >= 'a' && huidigChar <= 'z') {
                    letterGedetecteerd = true;
                    if (aantalCijfers == 0) {
                        return 0;
                    }
                } else if (huidigChar >= '0' && huidigChar <= '9' && !letterGedetecteerd) {
                    resultString.append(huidigChar);
                    aantalCijfers++;
                } else if (huidigChar == '.') {
                    if (aantalCijfers == 0) {
                        return 0;
                    } else {
                        break;
                    }
                }
                if(!tekenGelezen && i > 0) {
                    teken = '+';
                }
            } else if(aantalCijfers > 0 || tekenGelezen){
                break;
            }
        }
        try {
            resultaat = Integer.parseInt(resultString.toString());

        } catch (NumberFormatException ex) {
            if (teken == '-' && aantalCijfers > 1) {
                return Integer.MIN_VALUE;
            } else if (teken == '+' && aantalCijfers > 1) {
                return Integer.MAX_VALUE;
            }
        }
        return resultaat;
    }
}