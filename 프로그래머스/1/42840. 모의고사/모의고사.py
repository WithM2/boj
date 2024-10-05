def solution(answers):
    answer = []
    
    score = [0, 0, 0]
    
    for i in range(len(answers)):
        if answers[i] == ((i%5)+1) :
            score[0] += 1
        if i%2 == 0 and answers[i] == 2 :
            score[1] += 1
        elif i%2 == 1 :
            if i%8 == 1 and answers[i] == 1 :
                score[1] += 1
            elif i%8 == 3 and answers[i] == 3 :
                score[1] += 1
            elif i%8 == 5 and answers[i] == 4 :
                score[1] += 1
            elif i%8 == 7 and answers[i] == 5 :
                score[1] += 1
        if (i//2)%5 == 0 and answers[i] == 3 :
            score[2] += 1
        elif (i//2)%5 == 1 and answers[i] == 1 :
            score[2] += 1
        elif (i//2)%5 == 2 and answers[i] == 2 :
            score[2] += 1
        elif (i//2)%5 == 3 and answers[i] == 4 :
            score[2] += 1
        elif (i//2)%5 == 4 and answers[i] == 5 :
            score[2] += 1
    
    for i in range(3) :
        if score[i] == max(score) :
            answer.append(i+1)
    
    return answer