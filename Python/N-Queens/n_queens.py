# TC:O(N^N)
def queens_helper(n, row, col, asc_des, desc_des, possibilities):
    curr_row = len(possibilities)
    for curr_col in range(n):
        if col[curr_col] and row[curr_row] and asc_des[curr_col+curr_row] and desc_des[curr_row-curr_col]:
            row[curr_row] = False
            col[curr_col] = False
            asc_des[curr_col+curr_row] = False
            desc_des[curr_row-curr_col] = False
            possibilities.append((curr_row, curr_col))
            possibilities = queens_helper(
                n, row, col, asc_des, desc_des, possibilities)
            # print(possibilities)
            if(len(possibilities) == n):
                return possibilities
            
            # Otherwise we are backtracking
            row[curr_row] = True
            col[curr_col] = True
            asc_des[curr_col+curr_row] = True
            desc_des[curr_row-curr_col] = True
            possibilities.pop()
    return possibilities


def queens(n):
    col = [True]*n
    row = [True]*n
    asc_des = [True]*(n*2-1)
    desc_des = [True]*(n*2-1)
    return queens_helper(n, row, col, asc_des, desc_des, [])


s = queens(4)
l = ""
ans = []
for i in range(4):
    for j in range(4):
        if((i, j) in s):
            l += "Q"
        else:
            l += "."
    ans.append(l)
    l = ""
print(ans)
# Output:
['.Q..', '...Q', 'Q...', '..Q.']
