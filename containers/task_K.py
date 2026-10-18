import sys

def solve():
    # Чтение всех данных из стандартного ввода
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    a = [int(x) for x in input_data[1:n+1]]
    
    # Массивы для хранения левой и правой границ для каждого элемента
    L = [0] * n
    R = [0] * n
    
    # Ищем левые границы с помощью стека
    stack = []
    for i in range(n):
        while stack and a[stack[-1]] >= a[i]:
            stack.pop()
        L[i] = stack[-1] + 1 if stack else 0
        stack.append(i)
        
    # Ищем правые границы с помощью стека
    stack = []
    for i in range(n - 1, -1, -1):
        while stack and a[stack[-1]] >= a[i]:
            stack.pop()
        R[i] = stack[-1] - 1 if stack else n - 1
        stack.append(i)
        
    # Считаем префиксные суммы
    pref = [0] * (n + 1)
    for i in range(n):
        pref[i+1] = pref[i] + a[i]
        
    max_val = -1
    best_l = 1
    best_r = 1
    
    # Находим лучший отрезок
    for i in range(n):
        l, r = L[i], R[i]
        current_sum = pref[r+1] - pref[l]
        current_val = current_sum * a[i]
        
        if current_val > max_val:
            max_val = current_val
            best_l = l + 1  # перевод в 1-индексацию
            best_r = r + 1
            
    print(max_val)
    print(best_l, best_r)

if __name__ == '__main__':
    solve()
