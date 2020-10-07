def spiralTraverse(array):
    result = []
    startRow, endRow = 0, len(array)-1
    startCol, endCol = 0, len(array[0])-1
    # Equal is imp if we have single line in matrix afterwards
    while startRow <= endRow and startCol <= endCol:
        for col in range(startCol, endCol+1):
            result.append(array[startRow][col])

        for row in range(startRow+1, endRow+1):
            result.append(array[row][endCol])

        for col in reversed(range(startCol, endCol)):
            result.append(array[endRow][col])

        for row in reversed(range(startRow+1, endRow)):
            result.append(array[row][startCol])
        # Now for the inward parameters we have to the following choices:
        startRow, endRow = startRow+1, endRow-1
        startCol, endCol = startCol+1, endCol-1
    return result


matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]
print(spiralTraverse(matrix))
# [1, 2, 3, 6, 9, 8, 7, 4, 5]
