package net.jimblacker.questions;

import java.util.ArrayDeque;
import java.util.Random;

public class TreeCount {
  static class Node {
    Node parent;
    Node leftChild;
    Node rightChild;
  }

  private static int CountNodesRecursive(Node node) {
    int count = 1;
    if (node.leftChild != null)
      count += CountNodesRecursive(node.leftChild);
    if (node.rightChild != null)
      count += CountNodesRecursive(node.rightChild);
    return count;
  }

  private static int CountNodesNonRecursive(Node tree) {
    ArrayDeque<Node> nodes = new ArrayDeque<Node>();
    nodes.add(tree);
    int count = 0;
    while (!nodes.isEmpty()) {
      Node node = nodes.remove();
      count++;
      if (node.leftChild != null)
        nodes.add(node.leftChild);
      if (node.rightChild != null)
        nodes.add(node.rightChild);
    }
    return count;
  }

private static Node firstNodeInTree(Node node) {
  while (node.leftChild != null)
    node = node.leftChild;
  return node;
}

private static Node nextNode(Node node) {
  if (node.rightChild != null)
    return firstNodeInTree(node.rightChild);

  while (true) {
    Node parent = node.parent;
    if (parent == null || node == parent.leftChild)
      return parent;
    node = parent;
  }
}

private static int CountNodesZeroStorage(Node tree) {
  int count = 0;
  for (Node node = firstNodeInTree(tree);
       node != null; node = nextNode(node))
    count++;
  return count;
}

  private static Node makeTree(Node parent,
                               Random random, int target) {
    Node node = new Node();
    node.parent = parent;
    target--;
    int leftTarget = random.nextInt(target + 1);
    if (leftTarget > 0)
      node.leftChild = makeTree(node, random, leftTarget);
    int rightTarget = target - leftTarget;
    if (rightTarget > 0)
      node.rightChild = makeTree(node, random, rightTarget);
    return node;
  }

  public static void main(String[] args) {
    Random random = new Random(1);
    int target = 100;
    Node tree = makeTree(null, random, target);

    long startTime = System.nanoTime();
    int result = CountNodesRecursive(tree);
    long endTime = System.nanoTime();
    System.out.println(result + ":" + (endTime - startTime));

    startTime = System.nanoTime();
    result = CountNodesNonRecursive(tree);
    endTime = System.nanoTime();
    System.out.println(result + ":" + (endTime - startTime));

    startTime = System.nanoTime();
    result = CountNodesZeroStorage(tree);
    endTime = System.nanoTime();
    System.out.println(result + ":" + (endTime - startTime));

  }
}
