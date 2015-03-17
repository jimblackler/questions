"use strict";

var denominations = [1, 10, 50];
var quantities = [10, 5, 2];

function combinations(target, minCoin) {
  if (minCoin === denominations.length)
    return target > 0 ? 0 : 1;
  var total = 0;
  for (var n = 0; target >= 0 &&
      n <= quantities[minCoin]; n++) {
    total += combinations(target, minCoin + 1);
    target -= denominations[minCoin];
  }
  return total;
}

function solve(target) {
  return combinations(target, 0);
}

console.log(solve(99));