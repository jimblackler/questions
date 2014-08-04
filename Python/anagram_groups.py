from collections import Counter, defaultdict


def display_anagrams(*words):
    groups = defaultdict(set)
    for word in words:
        groups[frozenset(Counter(word).iteritems())].add(word)
    print list(list(words) for words in groups.values())


display_anagrams("pats", "pot", "pots", "stop", "taps", "tops")