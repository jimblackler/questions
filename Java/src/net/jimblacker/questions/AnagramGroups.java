package net.jimblacker.questions;

import java.util.*;

public class AnagramGroups {

  static Map<Character, Integer> getFrequencies(String word) {
    Map<Character, Integer> frequencies =
        new HashMap<Character, Integer>();
    for (char chr : word.toCharArray()) {
      if (frequencies.containsKey(chr)) {
        frequencies.put(chr, frequencies.get(chr) + 1);
      } else {
        frequencies.put(chr, 1);
      }
    }
    return frequencies;
  }

  static void displayAnagrams(ArrayList<String> sourceWords) {
    Map<Map<Character, Integer>, Set<String>> groups =
        new HashMap<Map<Character, Integer>, Set<String>>();
    for (String word : sourceWords) {
      Map<Character, Integer> frequencies = getFrequencies(word);
      if (groups.containsKey(frequencies)) {
        Set<String> words = groups.get(frequencies);
        words.add(word);
      } else {
        Set<String> words = new HashSet<String>();
        words.add(word);
        groups.put(frequencies, words);
      }
    }

    for (Set<String> words : groups.values()) {
      System.out.println(words);
    }
  }

  public static void main(String[] args) {
    ArrayList<String> sourceWords =
        new ArrayList<String>(Arrays.asList(
            "pats", "pot", "pots", "stop", "taps", "tops"));
    displayAnagrams(sourceWords);
  }

}
