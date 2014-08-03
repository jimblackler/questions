package net.jimblacker.questions;

public class StringReverse {
private static String reverse(String s) {
  StringBuilder b = new StringBuilder();
  for (int i = s.length() - 1; i >= 0; i--) {
    b.append(s.charAt(i));
  }
  return b.toString();
}

  public static void main(String[] args) {
    String s = "Hello world";
    System.out.println(s);
    s = reverse(s);
    System.out.println(s);
  }

}
