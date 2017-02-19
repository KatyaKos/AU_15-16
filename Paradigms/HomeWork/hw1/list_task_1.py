__author__ = 'KatyaKos'


def remove_adjacent(lis):
    if lis == []:
        return lis
    mass = [lis[0]]

    for i in range(1, len(lis)):
        if lis[i] != lis[i - 1]:
            mass.append(lis[i])

    return mass

def linear_merge(lis1, lis2):
    i, j = 0, 0
    ans = []
    while i != len(lis1) and j != len(lis2):
        if lis1[i] <= lis2[j]:
            ans.append(lis1[i])
            i += 1
        else:
            ans.append(lis2[j])
            j += 1
    return ans + lis1[i:] + lis2[j:]

print('List for removing')
mass1 = list(map(int, input().split()))
print('Lists for sorting')
mass2 = list(map(int, input().split()))
mass3 = list(map(int, input().split()))

mass = remove_adjacent(mass1)
print('Unique list:')
print(*mass)

mass = linear_merge(mass2, mass3)
print("Merged'n'Sorted list:")
print(*mass, end = '\n')