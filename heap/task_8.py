import heapq

data = open(0).read().split()

if data:
    n = int(data[0])
    m = int(data[1])

    start_to_len = {}
    end_to_len = {}

    start_to_len[1] = n
    end_to_len[n] = n

    heap = []
    heapq.heappush(heap, (-n, 1))

    allocations = {}

    for i in range(1, m + 1):
        val = int(data[i + 1])
        
        if val > 0:
            k = val
            allocated_start = -1
            
            while heap:
                neg_length, start = heap[0]
                length = -neg_length
                
                if start in start_to_len and start_to_len[start] == length:
                    if length >= k:
                        heapq.heappop(heap)
                        start_to_len.pop(start)
                        end_to_len.pop(start + length - 1)
                        
                        allocated_start = start
                        
                        remaining_len = length - k
                        if remaining_len > 0:
                            new_start = start + k
                            start_to_len[new_start] = remaining_len
                            end_to_len[new_start + remaining_len - 1] = remaining_len
                            heapq.heappush(heap, (-remaining_len, new_start))
                        break
                    else:
                        break
                else:
                    heapq.heappop(heap)
                    
            if allocated_start != -1:
                allocations[i] = (allocated_start, k)
                print(allocated_start)
            else:
                allocations[i] = None
                print(-1)
                
        else:
            t = -val
            
            if t in allocations and allocations[t] is not None:
                alloc_start, alloc_len = allocations[t]
                
                new_start = alloc_start
                new_len = alloc_len
                
                left_end = alloc_start - 1
                if left_end in end_to_len:
                    left_len = end_to_len[left_end]
                    left_start = left_end - left_len + 1
                    
                    start_to_len.pop(left_start)
                    end_to_len.pop(left_end)
                    
                    new_start = left_start
                    new_len += left_len
                    
                right_start = alloc_start + alloc_len
                if right_start in start_to_len:
                    right_len = start_to_len[right_start]
                    right_end = right_start + right_len - 1
                    
                    start_to_len.pop(right_start)
                    end_to_len.pop(right_end)
                    
                    new_len += right_len
                    
                start_to_len[new_start] = new_len
                end_to_len[new_start + new_len - 1] = new_len
                heapq.heappush(heap, (-new_len, new_start))
