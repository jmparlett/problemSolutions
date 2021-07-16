#Find two or more nums that sum to 756008079

puzzle_input=open('input.txt')
numbers=[int(i.strip()) for i in puzzle_input.readlines()]
puzzle_input.close()

for n1 in range(0,len(numbers)-1):
    sum=numbers[n1]
    for n2 in range(n1+1,len(numbers)-1):
        if sum==756008079:
            print(n1,'\n',n2-1)
        sum+=numbers[n2]

largest=0
smallest=100000000
for i in numbers[520:536]:
    if i > largest:
        largest=i
    if i < smallest:
        smallest=i
print(largest+smallest)
# print(sum(numbers[520:536]))
# def find_sums ():
#     correct_nums=[]
#     #Loop through numbers past preamble
#     for c in range(25, len(numbers)-1):
#         #loop through previous 25 numbers
#         for c2 in range((c-25),c):
#             #Search combination of additions of previous 25
#             for c3 in range((c-24),c):
#                 if numbers[c2]+numbers[c3]==numbers[c]:
#                     correct_nums.append(numbers[c])
#                     break
#                     # print(f"{numbers[c]} is a sum of the previous 25.")
#     return correct_nums

# t=find_sums()
# for i in numbers:
#     if (i not in t) and (numbers.index(i) > 25):
#         print(i)