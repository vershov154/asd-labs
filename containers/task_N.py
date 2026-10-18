from collections import deque

player1 = deque(map(int, input().split()))
player2 = deque(map(int, input().split()))

moves = 0
limit = 10**6 

while player1 and player2 and moves < limit:
    moves += 1
    
    card1 = player1.popleft()
    card2 = player2.popleft()
    
    if card1 == 0 and card2 == 9:
        p1_wins = True
    elif card1 == 9 and card2 == 0:
        p1_wins = False
    else:
        p1_wins = card1 > card2
        
    if p1_wins:
        player1.append(card1)
        player1.append(card2)
    else:
        player2.append(card1)
        player2.append(card2)

if moves >= limit:
    print("botva")
elif not player1:
    print("second", moves)
else:
    print("first", moves)
