function count_words(sentence) {
  var previous_was_in_word = false;
  var count = 0;
  for (var idx = 0; idx != sentence.length; idx++) {
    var chr = sentence[idx];
    var part_of_word = (chr >= 'a' && chr <= 'z') ||
                       (chr >= 'A' && chr <= 'Z') ||
                       chr == "'";
    if (part_of_word && !previous_was_in_word) {
      count++;
    }
    previous_was_in_word = part_of_word;
  }
  return count;
}

// Test code.
console.log(count_words("If you don't ask, the answer is always no."));
