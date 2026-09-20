if __name__ == "__main__":
    list1 = list(map(int, input().split()))
    list2 = list(map(int, input().split()))

    list1.sort()
    list2.sort(reverse=True)

    sum = 0

    for i in range(len(list1)):
        sum = sum + (list1[i] * list2[i])

    print(sum)