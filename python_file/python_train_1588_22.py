import math
def solution(n):
    area = (1/(math.tan(math.pi/2/n)))
    return area

tc = int(input())
for i in range(tc):
    n = int(input())
    print(solution(n))