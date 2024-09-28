def solution(a, b):
    day = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    tmp = ["FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"]
    month = 1
    answer = 0
    
    while not month == a :
        answer += day[month]
        month += 1
    answer += b-1
    
    return tmp[answer%7]