def solution(number, limit, power):
    answer = 0
    for i in range(1, number+1) :
        tmp = 0
        for j in range(1, int(i**(1/2))+1):
            if i % j == 0 :
                tmp += 1
                if j**2 != i :
                    tmp += 1
            if tmp > limit :
                tmp = power
                break
        answer += tmp
    return answer