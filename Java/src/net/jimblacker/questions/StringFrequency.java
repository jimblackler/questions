package net.jimblacker.questions;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class StringFrequency {
  private static String singleAppearances(String input) {
    // Load a map with character frequencies in the string.
    Map<Character, Integer> frequencies =
        new HashMap<Character, Integer>();
    for (int i = 0; i < input.length(); i++) {
      char c = input.charAt(i);
      if (frequencies.containsKey(c)) {
        // Not the first appearance.
        frequencies.put(c, frequencies.get(c) + 1);
      } else {
        // First appearance.
        frequencies.put(c, 1);
      }
    }

    // Load a string with all characters with a frequency of one.
    StringBuilder result = new StringBuilder();
    for (Character c : frequencies.keySet()) {
      if (frequencies.get(c) == 1) {
        result.append(c);
      }
    }
    return result.toString();
  }

private static String singleAppearances2(String input) {

  Set<Character> singleAppearance = new HashSet<Character>();
  Set<Character> multipleAppearances = new HashSet<Character>();
  for (int i = 0; i < input.length(); i++) {
    char c = input.charAt(i);
    if (multipleAppearances.contains(c))
      continue;
    if (singleAppearance.add(c))
      continue;
    singleAppearance.remove(c);
    multipleAppearances.add(c);
  }

  // Load a string with all characters with a frequency of one.
  StringBuilder result = new StringBuilder();
  for (Character c : singleAppearance) {
    result.append(c);
  }
  return result.toString();
}

  public static void main(String[] args) {

    System.out.println(singleAppearances("abracadabra"));
    System.out.println(singleAppearances2("abracadabra"));
  }


}
