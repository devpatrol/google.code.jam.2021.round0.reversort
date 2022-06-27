def solution(case_number, liste):
    cost = 0
    longueur = len(liste)
    for i in range(longueur-1):

        index_of_min = i
        for j in range(i, longueur):
            if liste[j] < liste[index_of_min]:
                index_of_min = j
        
        while i < index_of_min:
            liste[i], liste[index_of_min] = liste[index_of_min], liste[i]
            i += 1
            index_of_min -= 1

        cost += index_of_min-i+1
    print("Case #{}: {}".format(case_number, cost))

nomber_of_test = int(input())
for i in range(nomber_of_test):
    number_of_elements = int(input())
    liste = list(map(int, input().split()))
    solution(i+1, liste)