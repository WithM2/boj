def min_dice_surface_sum(n, num):
    if n == 1:
        return sum(num) - max(num)
    
    min_one_face = min(num)
    
    min_two_faces = min(
        num[0] + num[1], num[0] + num[2], num[0] + num[3], num[0] + num[4],
        num[1] + num[2], num[1] + num[5], num[1] + num[3],
        num[2] + num[4], num[2] + num[5],
        num[3] + num[4], num[3] + num[5],
        num[4] + num[5]
    )
    
    min_three_faces = min(
        num[0] + num[1] + num[2], num[0] + num[1] + num[3], num[0] + num[2] + num[4], num[0] + num[3] + num[4],
        num[5] + num[1] + num[2], num[5] + num[1] + num[3], num[5] + num[2] + num[4], num[5] + num[3] + num[4]
    )
    
    one_face_count = (n - 2) * (n - 2) + 4 * (n - 2) * (n - 1)
    two_faces_count = 4 * (n - 1) + 4 * (n - 2)
    three_faces_count = 4
    
    answer = (one_face_count * min_one_face) + (two_faces_count * min_two_faces) + (three_faces_count * min_three_faces)
    
    return answer

n = int(input())
num = list(map(int, input().split()))

result = min_dice_surface_sum(n, num)
print(result)
