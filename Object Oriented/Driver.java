import java.util.Scanner;

class Address {
  private String city;
  private String state;

  public Address(String city, String state) {
    this.city = city;
    this.state = state;
  }

  public String getCity() {
    return city;
  }

  public void setCity(String city) {
    this.city = city;
  }

  public String getState() {
    return state;
  }

  public void setState(String state) {
    this.state = state;
  }
}

class Employee {
  private String fName;
  private String lName;
  private Employee boss = null;
  private Address addr;
  private static int count;

  {
    count++;
  }

  public Employee(String fName, String lName) {
    this.fName = fName;
    this.lName = lName;
  }

  public Employee(String fName, String lName, Employee boss) {
    this(fName, lName);
    this.boss = boss;
  }

  public Employee(String fName, String lName, Employee boss, Address addr) {
    this(fName, lName, boss);
    this.addr = addr;
  }

  public String getFName() {
    return fName;
  }

  public void setFName(String fName) {
    this.fName = fName;
  }

  public String getLName() {
    return lName;
  }

  public void setLName(String lName) {
    this.lName = lName;
  }

  public Employee getBoss() {
    return boss;
  }

  public void setBoss(Employee boss) {
    this.boss = boss;
  }

  public Address getAddr() {
    return addr;
  }

  public void setAddr(Address addr) {
    this.addr = addr;
  }

  public static int getCount() {
    return count;
  }

  public void displayInfo() {
    System.out.println("----------------------");
    System.out.println("Employee: " + fName + " " + lName);

    if (addr != null) {
      System.out.println("City: " + addr.getCity());
      System.out.println("State: " + addr.getState());
    } else {
      System.out.println("City: Unknown");
      System.out.println("State: Unknown");
    }

    System.out.println("Boss: " + (boss != null ? boss.getFName() + " " + boss.getLName() : "None"));
  }
}

public class Driver {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    Employee emp1 = createEmployee(scanner, null);
    Employee emp2 = createEmployee(scanner, emp1);
    Employee emp3 = createEmployee(scanner, emp2);

    emp1.displayInfo();
    emp2.displayInfo();
    emp3.displayInfo();

    System.out.println("----------------------");
  }

  private static Employee createEmployee(Scanner scnr, Employee previousEmployee) {
    System.out.print("Enter employee name (first, last): ");
    String fName = scnr.next();
    String lName = scnr.next();

    Address addr = null;

    // If there is a previous employee, ask for the address
    if (Employee.getCount() == 2) {
        System.out.print("Enter employee address (city, state) ");
        String city = scnr.next();
        String state = scnr.next();
        addr = new Address(city, state);
    }

    System.out.println("Creating employee " + fName + " " + lName);
    if (Employee.getCount() == 0) {
      return new Employee(fName, lName);
    } else if (Employee.getCount() == 1) {
      return new Employee(fName, lName, previousEmployee);
    } else {
      return new Employee(fName, lName, previousEmployee, addr);
    }
  }
}
