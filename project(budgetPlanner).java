import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

interface Actions {
    void addIncome(double incomeAmt, String incomeSrc);
    void addExpense(double expenseAmt, String expenseCat);
    void showSummary();
}

abstract class BaseBudget implements Actions {

    protected double income = 0;
    protected double exp = 0;
    protected String logs = "";

    public abstract void saveToFile(String file);

    public double getBal() {
        return income - exp;
    }
}

class Budget extends BaseBudget {

    private String user;
    private String fullName;
    private String email;
    private String password;
    private String address;

    public Budget(String user, String fullName, String email, String password, String address) {
        this.user = user;
        this.fullName = fullName;
        this.email = email;
        this.password = password;
        this.address = address;
        logs += "Budget created for user: " + user + "\n";
    }

    @Override
    public void addIncome(double incomeAmt, String incomeSrc) {
        if (incomeAmt <= 0) {
            System.out.println("Invalid Income!");
            return;
        }
        income += incomeAmt;
        logs += "Income: " + incomeAmt + " | Source: " + incomeSrc + "\n";
        System.out.println("Income Added.");
    }

    @Override
    public void addExpense(double expenseAmt, String expenseCat) {
        if (expenseAmt <= 0) {
            System.out.println("Invalid Expense!");
            return;
        }
        exp += expenseAmt;
        logs += "Expense: " + expenseAmt + " | Category: " + expenseCat + "\n";
        System.out.println("Expense Added.");
    }

    @Override
    public void showSummary() {
        System.out.println("\n--- Summary ---");
        System.out.println("User ID: " + user);
        System.out.println("Full Name: " + fullName);
        System.out.println("Email: " + email);
        System.out.println("Password: " + password);
        System.out.println("Address: " + address);
        System.out.println("Income: " + income);
        System.out.println("Expense: " + exp);
        System.out.println("Balance: " + getBal());
    }

    @Override
    public void saveToFile(String file) {
        try (FileWriter fw = new FileWriter(file)) {

            fw.write("--- Budget Report ---\n");
            fw.write("User ID: " + user + "\n");
            fw.write("Full Name: " + fullName + "\n");
            fw.write("Email: " + email + "\n");
            fw.write("Password: " + password + "\n");
            fw.write("Address: " + address + "\n\n");

            fw.write(logs);

            fw.write("----------------------\n");
            fw.write("Income: " + income + "\n");
            fw.write("Expense: " + exp + "\n");
            fw.write("Balance: " + getBal() + "\n");

            System.out.println("Saved.");
        }
        catch (IOException e) {
            System.out.println("File Error: " + e.getMessage());
        }
    }
}

class PremiumBudget extends Budget {
    public PremiumBudget(String user, String fullName, String email, String password, String address) {
        super(user, fullName, email, password, address);
    }

    @Override
    public void showSummary() {
        System.out.println("\n--- Premium Summary ---");
        super.showSummary();
        System.out.println("Extra Feature: Analysis Added");
    }
}

class budgetplanner {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Username: ");
        String user = sc.nextLine();

        System.out.print("Enter Full Name: ");
        String fullName = sc.nextLine();

        System.out.print("Enter Email: ");
        String email = sc.nextLine();

        System.out.print("Enter Password: ");
        String password = sc.nextLine();

        System.out.print("Enter Address: ");
        String address = sc.nextLine();

        Budget b = new PremiumBudget(user, fullName, email, password, address);

        int choice;

        do {
            System.out.println("\n1. Add Income");
            System.out.println("2. Add Expense");
            System.out.println("3. Summary");
            System.out.println("4. Save");
            System.out.println("5. Exit");
            System.out.print("Choice: ");

            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {

                case 1:
                    System.out.print("Income Amount: ");
                    double incAmt = sc.nextDouble();
                    sc.nextLine();
                    System.out.print("Source: ");
                    String src = sc.nextLine();
                    b.addIncome(incAmt, src);
                    break;

                case 2:
                    System.out.print("Expense Amount: ");
                    double expAmt = sc.nextDouble();
                    sc.nextLine();
                    System.out.print("Category: ");
                    String cat = sc.nextLine();
                    b.addExpense(expAmt, cat);
                    break;

                case 3:
                    b.showSummary();
                    break;

                case 4:
                    b.saveToFile("budget.txt");
                    break;

                case 5:
                    System.out.println("Bye!");
                    break;

                default:
                    System.out.println("Invalid!");
            }

        } while (choice != 5);

        sc.close();
    }
}
