def getMinPosition(array,start,end):
  min_index = start
  for i in range(start+1,end):
    if array[i] < array[min_index]:
      min_index = i
  return min_index

def reverseByWhile(array,i,j):
  while i < j:
    array[i],array[j] = array[j],array[i]
    i += 1
    j -= 1
  return array
number_of_test_cases = int(input().strip())

for case in range(number_of_test_cases):
  number_of_inputs = int(input().strip())
  cost = 0
  string = list(map(int,input().strip().split()))
  for i in range(len(string)-1):
    min_index = getMinPosition(string,i,len(string))
    string = reverseByWhile(string,i,min_index)
    cost += min_index-i+1
  print(f'Case #{case+1}: {cost}')
