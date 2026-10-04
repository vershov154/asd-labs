def good(stalls, k, dist):
    cows_count = 1
    last_cow_position = stalls[0]
    
    # Пытаемся расставить остальных коров
    for position in stalls[1:]:
        if position - last_cow_position >= dist:
            cows_count += 1
            last_cow_position = position  # запоминаем место новой коровы
            
    return cows_count >= k


n, k = map(int, input().split())
stalls = [int(x) for x in input().split()]
    
l = 0
r = stalls[-1] - stalls[0] + 1
    
while r - l > 1:
    m = (l + r) // 2
        
    if good(stalls, k, m):
        l = m 
    else:
        r = m 
            
print(l)
