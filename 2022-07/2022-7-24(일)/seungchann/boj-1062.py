from itertools import combinations
import sys
input = sys.stdin.readline

# a, c, i, t, n을 제외한 알파벳 고유 번호 딕셔너리
bin_dict = { 'b': 20, 'd': 19, 'e': 18, 'f': 17, 'g': 16, 'h': 15, 'j': 14,
            'k': 13, 'l': 12, 'm': 11, 'o': 10, 'p': 9, 'q': 8, 'r': 7, 
            's': 6, 'u': 5, 'v': 4, 'w': 3, 'x': 2, 'y': 1, 'z': 0 }

def word_to_bin(word):
    answer = 0b0
    for ch in word:
        answer = answer | (1 << bin_dict[ch])
    return answer

def solve(K, bin_list):
    max_val = 0
    power_of_2 = [2 ** i for i in range(21)]

    for comb in list(combinations(power_of_2, K-5)):
        cur = sum(comb)
        cnt = 0
        for bin_number in bin_list:
            if bin_number & cur == bin_number:
                cnt += 1
        max_val = max(max_val, cnt)    
    
    return max_val

if __name__ == "__main__":
    n, k = map(int, input().split())    
    bin_list = []

    for _ in range(n):
        antarctic_word_alpha = set(input().rstrip()[4:-4]).difference('a', 'c',' i', 't', 'n')
        bin_list.append(word_to_bin(antarctic_word_alpha))

    if k < 5:
        print(0)
    else:
        print(solve(k, bin_list))