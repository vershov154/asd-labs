import heapq

n = int(input())

numbers = list(map(int, input().split()))

heapq.heapify(numbers)

cost = 0.0

while len(numbers) > 1:
    first = heapq.heappop(numbers)
    second = heapq.heappop(numbers)
    
    current_sum = first + second
    cost += current_sum * 0.05  
    
    heapq.heappush(numbers, current_sum)

print(f"{cost:.2f}")
