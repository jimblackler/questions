"use strict";
var s2;

// Make a string
var s = "Hello";

// Find length of a string
console.log(s.length);

// Compare two strings
s2 = "Hello 2";
console.log(s == s2);

// Search for a substring
s2 = "el";
console.log(s.indexOf(s2));

// Make a substring
var b = 1;
var e = 3;
s2 = s.substring(b, e);
console.log(s2);

// Split a string
s = "Hello how are you?";
console.log(s.split(" "));
