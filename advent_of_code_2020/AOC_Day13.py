
#find each buses position in the leaving order
#bus 1 will leave at time t bus 2 t+7 bus t+15 etc
puzzle_input=open('input.txt')
buses=[]
x_c=0
for c in puzzle_input.read().split(','):
    if c == 'x':
        x_c+=1
    elif c !='x':
        buses.append([int(c),x_c])
puzzle_input.close()

#increment bus id until it is >= target t
#if difference of incremented time and target time is desired value return True
def find_bus_t(target_t,bus):
    while bus[0] < target_t:
        bus[0]+=bus[0]
    if bus[0]-target_t==bus[1]:
        print(bus[0]-target_t==bus[1])
        return True
    else:
        print(bus[0]-target_t==bus[1])
        return False

#test value by using find_bus_t for next bus in order if it fits the desired pattern move to the next bus
def test_time(t,bus_list):
    check_passed=True
    for bus in bus_list:
        # print(bus)
        if find_bus_t(t,bus)==False:
            check_passed=False
            break
    return check_passed

def main(bus_list):
    #inital value for t will be id of first bus in pattern
    t=bus_list[0][0] 
    #if it does not fit pattern restart loop and increment t by t
    # run_count=0
    while test_time(t,bus_list)==False:
        # print(t)
        t+=t
        # run_count+=1
        # print(run_count,'\n\n\n')
    return t

print(main(buses))
# print(test_time(buses[0][0],buses))
# print(buses)
