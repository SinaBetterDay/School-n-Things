import java.util.Scanner;

public class Bank {
  static BankAccount[] accounts; 
  static int noOfAccs;

  public static void main(String[] args) {
    accounts = new BankAccount[1]; 
    noOfAccs = 0; 
    bankMenu();
  }

  static void bankMenu() {
    Scanner scnr = new Scanner(System.in);
    int currentIndex = -1;
    char userSelection;
    boolean quit = false;

    do {
      printMenu(currentIndex);
      System.out.print("Enter command: ");
      userSelection = scnr.next().charAt(0);
      System.out.println();

      switch (userSelection) {
        case 'O':
        case 'o':
          currentIndex = openAcc();
          break;
        case 'D':
        case 'd':
          if (currentIndex != -1) {
            accounts[currentIndex].deposit();
          } else {
            System.out.println("Please select an account");
          }
          break;
        case 'S':
        case 's':
          currentIndex = selectAcc();
          break;
        case 'C':
        case 'c':
          if (currentIndex != -1) {
            closeAcc(currentIndex);
          } else {
              System.out.println("Please select an account");
          }
          break;
        case 'W':
        case 'w':
          if (currentIndex != -1) {
            accounts[currentIndex].withdraw();
          } else {
            System.out.println("Please select an account");
          }
          break;
        case 'L':
        case 'l':
          listAccounts();
          break;
        case 'Q':
        case 'q':
          quit = true;
          break;
        default:
          System.out.println("Invalid command. Please try again.");
      }
      System.out.println();
    } while (!quit);
  }

  static void printMenu(int index) {
    System.out.println("O: Open account\n" +
            "D: Deposit\n" +
            "S: Select account\n" +
            "C: Close account\n" +
            "W: Withdraw\n" +
            "L: List all accounts\n" +
            "Q: Quit");
    if (index != -1 && accounts[index] != null) {
      System.out.println("Current account selected: " + accounts[index].getAcc() + " Balance: $" + accounts[index].getBalance());
    } else {
      System.out.println("Current account selected: NONE");
    }
  }
 
  static int openAcc() {
    Scanner scnr = new Scanner(System.in);
    System.out.print("Enter new account number: ");
    String accNumber = scnr.nextLine();

    for (int i = 0; i < noOfAccs; i++) {
      if (accounts[i].getAcc().equals(accNumber)) {
        System.out.println("Account number already exists. Please enter a different one.");
            return -1;
        }
    }

    double initialBalance;
    do {
      System.out.print("Enter initial balance: ");
      initialBalance = scnr.nextDouble();
      scnr.nextLine(); 

      if (initialBalance < 1) {
        System.out.println("Initial balance must be at least $1.00. Please try again.");
      }
    } while (initialBalance < 1);

    if (noOfAccs == accounts.length) {
      resize();
    }

    accounts[noOfAccs] = new BankAccount(accNumber, initialBalance);
    noOfAccs++;
    return noOfAccs - 1; 
  }

  static void resize() {
    BankAccount[] newArray = new BankAccount[accounts.length * 2];
    System.arraycopy(accounts, 0, newArray, 0, accounts.length);
    accounts = newArray;
  }

  static void listAccounts() {
    if (noOfAccs == 0) {
      System.out.println("No accounts");
      return;
    }

    double totalAssets = 0;
    for (int i = 0; i < noOfAccs; i++) {
      System.out.println((i + 1) + ") Acct #: " + accounts[i].getAcc() + " Bal: $" + accounts[i].getBalance());
      totalAssets += accounts[i].getBalance();
    }
    System.out.println("Total Bank assets: $" + totalAssets);
  }

  static int selectAcc() {
    Scanner scnr = new Scanner(System.in);
    System.out.print("Enter account number: ");
    String accNumber = scnr.nextLine();

    for (int i = 0; i < noOfAccs; i++) {
      if (accounts[i].getAcc().equals(accNumber)) {
        return i;
      }
    }
    System.out.println("Account number was not found");
    return -1;
  }

  static void closeAcc(int index) {
    if (noOfAccs == 1) { 
      accounts[index] = null;
      noOfAccs--;
      System.out.println("All accounts closed");
      return;
    }
    System.out.println("Account " + accounts[index].getAcc() + " is closed");
    
    accounts[index] = accounts[noOfAccs - 1]; 
    accounts[noOfAccs - 1] = null; 
    noOfAccs--; 
  }
}

class BankAccount {
  private String accNbr;
  private double balance;

  BankAccount(String accNbr, double balance) {
    this.accNbr = accNbr;
    this.balance = balance;
  }

  String getAcc() {
    return accNbr;
  }

  double getBalance() {
    return balance;
  }

  void deposit() {
    Scanner scnr = new Scanner(System.in);
    System.out.print("Enter amount of deposit: ");
    double amount = scnr.nextDouble();
    if (amount > 0) {
      balance += amount;
      System.out.println("Deposit successful. New balance: $" + balance);
    } else {
      System.out.println("Invalid deposit amount.");
    }
  }

  void withdraw() {
    Scanner scnr = new Scanner(System.in);
    System.out.print("Enter amount to withdraw: ");
    double amount = scnr.nextDouble();
    if (balance - amount >= 1) {
      balance -= amount;
      System.out.println("Withdrawal successful. New balance: $" + balance);
    } else {
      System.out.println("You are withdrawing too much. Please try again.");
    }
  }
}
