word1 = input()
word2 = input()

if len(word1) != len(word2):
    print("NO")
else:
    char_cnt = {}
    anagram = True
    
    for char in word1:
        if char in char_cnt:
            char_cnt[char] += 1
        else:
            char_cnt[char] = 1
            
    for char in word2:
        if char in char_cnt:
            char_cnt[char] -= 1
        else:
            anagram = False
            break
            
    if anagram:
        for count in char_cnt.values():
            if count != 0:
                anagram = False
                break
                
    if anagram:
        print("YES")
    else:
        print("NO")
