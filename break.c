public class WhileLoopWithBreak {
    public static void main(String[] args) {
        int i = 1;

        while (true) {
            System.out.println(i);
            i++;
            if (i > 5) {
                break;
            }
        }
    }
}
