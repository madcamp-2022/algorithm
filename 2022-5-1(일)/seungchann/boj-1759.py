from itertools import combinations
import sys
input = sys.stdin.readline

l, c = map(int, input().split())
array = input().rstrip().split()
array.sort()

for pw in combinations(array, l):
    vowel_cnt = 0
    consonant_cnt = 0
    passwd = ""
    for ch in pw:
        passwd += ch
        if ch in ['a', 'e', 'i', 'o', 'u']:
            vowel_cnt += 1
        else:
            consonant_cnt += 1
    if vowel_cnt >= 1 and consonant_cnt >= 2:
        print(passwd)