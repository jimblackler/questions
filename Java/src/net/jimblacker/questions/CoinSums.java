package net.jimblacker.questions;

import java.util.Arrays;
import java.util.List;

public class CoinSums {

  private static void complete(List<Integer> denominations,
                               int position, int target,
                               String string) {
    // Target reached. Display denominations used.
    if (target == 0) {
      System.out.println(string);
      return;
    }
    // No more denominations.
    if (position == denominations.size())
      return;

    int denomination = denominations.get(position);

    // Select no coins of this denomination.
    complete(denominations, position + 1, target, string);

    // Select 1 .. max coins of this denomination.
    for (int m = 1; m <= target / denomination; m++) {
      complete(denominations, position + 1,
          target - m * denomination,
          string + m + "x" + denomination + " ");
    }
  }

  public static void solve(int target) {
    complete(Arrays.asList(5, 10, 25, 50), 0, target, "");
  }

  public static void main(String[] args) {
    solve(95);
  }
}
