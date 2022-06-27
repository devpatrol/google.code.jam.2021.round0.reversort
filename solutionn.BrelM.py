import sys

def reverse(numbs, start, end):
    i = 0
    while start+i < end-i:
        s, e = start+i, end-i
        numbs[s], numbs[e] = numbs[e], numbs[s]
        i +=1
    return numbs


nb_of_tests = int(sys.stdin.readline().strip())
for x in range(nb_of_tests):
    l = int(sys.stdin.readline().strip())
    numbers = list(map(int, sys.stdin.readline().strip().split(' ')))
    cost = 0
    length = len(numbers)
    for i in range(length-1):
        j = i
        for imin in range(i, length):
            if numbers[imin] < numbers[j]:
                j = imin
        cost += j - i + 1
        numbers = reverse(numbers, i, j)
    
    print(f"Case #{x + 1}: {cost}")

