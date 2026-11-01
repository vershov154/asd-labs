import heapq

n = int(input())

a = []
for _ in range(n):
    a.append(int(input()))

heap = []

for idx in range(n):
    f = a[idx]
    first_time = max(1000 - f, 1)
    heapq.heappush(heap, (first_time, idx, f))

igor_pos = 0
igor_time = 0  

while heap:
    curr_time, curr_idx, curr_f = heapq.heappop(heap)
    
    if heap and heap[0][0] == curr_time:
        print(curr_time)
        break
        
    distance = abs(curr_idx - igor_pos)
    if curr_time - igor_time < distance:
        print(curr_time)
        break
        
    igor_pos = curr_idx
    igor_time = curr_time
    
    next_f = curr_f + 1
    next_time = curr_time + max(1000 - next_f, 1)
    heapq.heappush(heap, (next_time, curr_idx, next_f))
