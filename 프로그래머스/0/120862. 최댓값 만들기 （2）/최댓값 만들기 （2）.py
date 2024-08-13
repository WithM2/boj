def solution(numbers):
#     answer = -999999999
    
#     for i in range(len(numbers)-1):
#         for j in range(i+1, len(numbers)) :
#             if numbers[i]*numbers[j] > answer :
#                 answer = numbers[i]*numbers[j]

    answer = 0
    numbers.sort()
    
    answer = numbers[0]*numbers[1]
    if numbers[-1]*numbers[-2] > answer :
        answer = numbers[-1]*numbers[-2]
    
    
    
    
    return answer