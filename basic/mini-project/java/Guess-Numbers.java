import java.util.Scanner;

public class miniProject {
    public static void main(String[] args) {
       // MINI PROJECT
        Scanner sc = new Scanner(System.in);
        int userNumber = 0;
        int num = (int)(Math.random()*100);
        do {
            System.out.println("Guess My Number  ");
            userNumber = sc.nextInt();

            if (userNumber == num) {
                System.out.println("WOOHOO... CORRECT");
                break;
            }
            else if(userNumber > num) {
                System.out.println("Your Number Is Too Large ");
            }
            else {
                System.out.println("Your Number Is Too Small");
            }

        }while(userNumber >= 0);

        System.out.println("My Number Was " + num);
    }
}
