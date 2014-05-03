package net.jimblacker.questions;

public class StringExamples {
  public static void main(String[] args) {

    // Make a string
    String s = "Hello";

    // Find length of a string
    System.out.println(s.length());

    // Compare two strings
    String s2 = "Hello 2";
    System.out.println(s.equals(s2));

    // Search for a substring
    s2 = "el";
    System.out.println(s.indexOf(s2));

    // Make a substring
    int b = 1;
    int e = 3;
    s2 = s.substring(b, e);
    System.out.print(s2);
  }

}
