import heapq

n, k, p = map(int, input().split())

orders = []
for _ in range(p):
    orders.append(int(input()))

next_positions = [[] for _ in range(n + 1)]
for idx, car in enumerate(orders):
    next_positions[car].append(idx)

for i in range(1, n + 1):
    next_positions[i].reverse()

floor_set = set() 
floor_heap = []
operations = 0 

current_next_t = [p] * (n + 1)

for idx, car in enumerate(orders):
    next_positions[car].pop()
    
    next_t = next_positions[car][-1] if next_positions[car] else p
    current_next_t[car] = next_t

    if car in floor_set:
        heapq.heappush(floor_heap, (-next_t, car))
        continue

    operations += 1

    if len(floor_set) >= k:
        while floor_heap:
            furthest_t, car_to_remove = heapq.heappop(floor_heap)
            
            if car_to_remove in floor_set and -furthest_t == current_next_t[car_to_remove]:
                floor_set.remove(car_to_remove)
                break

    floor_set.add(car)
    heapq.heappush(floor_heap, (-next_t, car))

print(operations)
