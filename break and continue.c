public class WhileLoopWithBreakContinue {
    public static void main(String[] args) {
        int i = 1;

        while (i <= 10) {
            if (i % 2 == 0) {
                i++;
                continue;
            }
            System.out.println(i);
            i++;
            if (i > 5) {
                break;
            }
        }
    }
}

