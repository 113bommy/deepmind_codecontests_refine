import math
def get_coefficients(n):
  coefficients = []
  while(n>=1):
    reminder = n%3
    n = n//3
    coefficients.append(reminder)
  return coefficients
def check_ranks(n,coefficients):
  zero_rank = 0
  coefficients.reverse()
  try :
    two_rank = coefficients.index(2)
    try :
      temp = coefficients[:two_rank].copy()
      temp.reverse()
      zero_rank = temp.index(0,0,two_rank)+1
      coefficients[two_rank-zero_rank] = 1
      zero_rank = two_rank-zero_rank
    except ValueError :
      zero_rank = -1
  except ValueError :
    two_rank = -1
  return two_rank, zero_rank
 
q = int(input())
for _ in range(q):
  n = int(input())
  coefficients = get_coefficients(n)
  two_rank, zero_rank = check_ranks(n,coefficients)
  if two_rank == -1 :
    print(n)
  elif zero_rank == -1 :
    s = int(math.pow(3,len(coefficients)))
    print(s)
  else :
    s = 0
    for i in range (zero_rank+1):
      s+=int(math.pow(3,len(coefficients)-1-i))*coefficients[i]
    print(s)
  