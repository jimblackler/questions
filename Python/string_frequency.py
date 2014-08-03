from collections import Counter

def singleAppearances(input):
    return "".join(k for k,v in Counter(input).items() if v == 1)

print singleAppearances("abracadabra")