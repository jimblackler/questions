package net.jimblacker.questions;

import java.util.*;

public class HoppingGame {
  // Returns 'true' if the given values represent a completable game.
  static boolean canSolve(List<Integer> values) {
    Set<Integer> reachable = new HashSet<Integer>();
    completeReachStatus(values, 0, reachable);
    return reachable.contains(values.size() - 1);
  }

  // Loads the set with all positions that can be reached from 'pos'.
  static void completeReachStatus(List<Integer> values, int pos,
                                  Set<Integer> reachable) {
    if (!reachable.add(pos))
      return;  // Position has already been considered.
    int hop = values.get(pos);
    // Test for hop forwards.
    if (pos + hop < values.size())
      completeReachStatus(values, pos + hop, reachable);
    // Test for hop backwards.
    if (pos > hop)
      completeReachStatus(values, pos - hop, reachable);
  }

  public static void main(String[] args) {
    // Build the array.
    ArrayList<Integer> values = new ArrayList<Integer>();
    Random random = new Random();
    for (int i = 0; i != 10; i++) {
      values.add(random.nextInt(5));
    }

    // Run the test.
    System.out.println(values);
    boolean canSolve = canSolve(values);
    System.out.println(canSolve);
  }
}
