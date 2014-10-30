package net.jimblacker.questions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ListExamples {
  public static void main(String[] args) {
    // Create a list
    List<Integer> l = new ArrayList<Integer>(Arrays.asList(1, 2, 3));

    // Add an item
    l.add(4);

    // Get length of the list
    System.out.println(l.size());

    // Return the second item
    System.out.println(l.get(1));

    // Remove the first item
    l.remove(0);

    // Clear the list
    l.clear();
  }
}
