def matmul(A,B):
    # Get the dimensions of the matrices
    n = len(A)

    # Initialize the resulting matrix with zeros
    result = [[0 for _ in range(n)] for _ in range(n)]

    # Perform matrix multiplication using nested loops
    for i in range(n):
        for j in range(n):
            for k in range(n):
                result[i][j] += A[i][k] * B[k][j]

    return result
