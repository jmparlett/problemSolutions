import copy

inp=open('input.txt')

program=[[i[0].strip(),int(i[1])] for i in [i.split() for i in [i for i in inp.read().split('\n')]]]

inp.close()



def test_program(program):
    last_instruction=len(program)-1

    instructions_run=[]
    program_counter=0
    accumulator=0
    
    #Program main loop
    while program_counter < last_instruction:
        isloop=False
        if program_counter in instructions_run:
            print(f'Instruction {program_counter} repeated')
            isloop=True
            break
        instructions_run.append(program_counter)

        if program[program_counter][0]=='jmp':
            program_counter+=program[program_counter][1]
        elif program[program_counter][0]=='acc':
            accumulator+=program[program_counter][1]
            program_counter+=1
        elif program[program_counter][0]=='nop':
            program_counter+=1
    if isloop:
        return isloop
    else:
        return accumulator

def modify_program(program):
    #Find instructions to modify
    instructions_to_test=[]
    for n in range(len(program)):
        if program[n][0]=='jmp' or program[n][0]=='nop':
            instructions_to_test.append(n)
    instructions_to_test.sort()

    #Create a copy of the program with a single modified instruction for each instruction found
    for instruction in instructions_to_test:
        copy_program=copy.deepcopy(program)
        if program[instruction][0]=='jmp':
            copy_program[instruction][0]='nop'
        elif program[instruction][0]=='nop':
            copy_program[instruction][0]='jmp'
        if test_program(copy_program)!=True:
            print(test_program(copy_program),instruction)
            break


modify_program(program)
# print(test_program(program))