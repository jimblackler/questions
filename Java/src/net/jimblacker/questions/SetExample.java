package net.jimblacker.questions;

import java.util.HashSet;
import java.util.Set;

public class SetExample {
  public static void main(String[] args) {

    {
      Set<Character> letters = new HashSet<Character>();

      letters.add('C');  // Add letters
      letters.add('Q');

      letters.remove('C');  // Remove a letter

      // Test for a letter
      System.out.println(letters.contains('Q'));
    }

    {
      boolean letters[] = new boolean[26];

      letters['C' - 'A'] = true;  // Add a letter
      letters['Q' - 'A'] = true;

      letters['C' - 'A'] = false;  // Remove a letter

      // Test for a letter
      System.out.println(letters['Q' - 'A']);
    }

    {
    int letters = 0;

    letters |= 1 << ('C' - 'A');  // Add a letter
    letters |= 1 << ('Q' - 'A');

    letters &= ~(1 << ('C' - 'A'));  // Remove a letter

    // Test for a letter
    System.out.println(
        (letters & (1 << ('Q' - 'A'))) != 0);
    }


  }
}
