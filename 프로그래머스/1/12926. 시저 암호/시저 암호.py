def solution(s, n):
    lower_list = "abcdefghijklmnopqrstuvwxyz"
    upper_list = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    
    answer = ''
    
    for letter in s :
        if letter == ' ' :
            answer += ' '
        elif letter.islower() :
            newLetterNum = lower_list.find(letter) + n
            answer += lower_list[newLetterNum % 26]
        else :
            newLetterNum = upper_list.find(letter) + n
            answer += upper_list[newLetterNum % 26]
    
    
    
    return answer