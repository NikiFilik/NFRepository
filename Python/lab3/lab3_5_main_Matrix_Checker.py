def matrixChecker(mat):
    #Если определитель равен нулю, то у него есть столбец, который является линейной комбинацией остальных столбцов
    determinant = int(mat[0][0]) * int(mat[1][1]) * int(mat[2][2]) + int(mat[0][1]) * int(mat[1][2]) * int(mat[2][0]) + int(mat[0][2]) * int(mat[1][0]) * int(mat[2][1]) \
        - int(mat[0][2]) * int(mat[1][1]) * int(mat[2][0]) - int(mat[0][0]) * int(mat[1][2]) * int(mat[2][1]) - int(mat[0][1]) * int(mat[1][0]) * int(mat[2][2])
    
    if determinant == 0:
        print("Столбцы линейно зависимы", mat)
    else:
        print("Столбцы линейно независимы", mat)


print("Введите матрицу 3х3:")
mat = [input().split() for i in range(3)]

matrixChecker(mat)