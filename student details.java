import java.util.*;

class Student1 {
    String usn;
    String name;
    String branch;
    String phone;

    void read() {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter USN:");
        usn = s.next();
        System.out.println("Enter Name:");
        name = s.next();
        System.out.println("Enter Branch:");
        branch = s.next();
        System.out.println("Enter Phone:");
        phone = s.next();
    }

    void display() {
        System.out.println("USN: " + usn);
        System.out.println("Name: " + name);
        System.out.println("Branch: " + branch);
        System.out.println("Phone: " + phone);
    }
}

public class Studentme {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the number of students:");
        int n = s.nextInt();
        Student1[] s1 = new Student1[n];

        // Read student details
        for (int i = 0; i < n; i++) {
            s1[i] = new Student1();
            s1[i].read();
        }

        // Display student details
        for (int i = 0; i < n; i++) {
            s1[i].display();
        }

        // Close the scanner to prevent resource leaks
        s.close();
    }
}
