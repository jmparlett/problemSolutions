from math import prod

def parseL(bitstr):
    # attempt to decode a literal val
    val=''
    while True:
        try:
            switch = bitstr.pop()
            # get 4 bits from stream
            for i in range(4):
                val+=bitstr.pop()
            if switch == '0':
                return int(val,2),bitstr
        except Exception:
            return -1,bitstr

def parseN(bitstr,n):
    # attempt to parse next n bits into a int
    num=''
    for i in range(n):
        try:
            num+=bitstr.pop()
        except Exception:
            return -1,bitstr
    return int(num,2),bitstr

def processPacketPart1(bitstr):
        # read version, type
        v,bitstr = parseN(bitstr,3)
        t,bitstr = parseN(bitstr,3)
        print(v,t)

        # if literal parse
        if t==4:
            val,bitstr = parseL(bitstr)
            if val==-1:
                return 0,bitstr
            return v, bitstr
        
        else:
        # if operator get type-id
            tid,bitstr = parseN(bitstr,1)
            print("tid",tid)
            if tid==1:
            # if type-id==1 parse next 11 bits and convert to get num of sub packets (n)
                numPackets, bitstr = parseN(bitstr,11)
                # parse the next (n) packets
                versionSum=v
                for i in range(numPackets):
                    v, bitstr = processPacketPart1(bitstr)
                    versionSum+=v
                return versionSum,bitstr
            else:
            # if type-id==0 parse next 15 bits to get total length of subpackets (n)
                numBits, bitstr = parseN(bitstr,15)
                # parse until we've proccessed (n) bits
                targetlen = len(bitstr)-numBits
                versionSum=v
                while len(bitstr)>targetlen:
                    v,bitstr = processPacketPart1(bitstr)
                    versionSum+=v
                print(bitstr)
                return  versionSum,bitstr


def processPacketPart2(bitstr):
        # read version, type
        v,bitstr = parseN(bitstr,3)
        t,bitstr = parseN(bitstr,3)
        print(v,t)

        # if literal parse
        if t==4:
            val,bitstr = parseL(bitstr)
            if val==-1:
                return 0,bitstr
            return val, bitstr
        
        else:
        # if operator get type-id and colect values
            tid,bitstr = parseN(bitstr,1)
            print("tid",tid)
            if tid==1:
            # if type-id==1 parse next 11 bits and convert to get num of sub packets (n)
                numPackets, bitstr = parseN(bitstr,11)
    
                # collection of values for this operator
                values = []

                # parse the next (n) packets
                for i in range(numPackets):
                    val, bitstr = processPacketPart2(bitstr)
                    values.append(val)
            else:
            # if type-id==0 parse next 15 bits to get total length of subpackets (n)
                numBits, bitstr = parseN(bitstr,15)

                # collection of values for this operator
                values = []

                # parse until we've proccessed (n) bits
                targetlen = len(bitstr)-numBits
                while len(bitstr)>targetlen:
                    val,bitstr = processPacketPart2(bitstr)
                    values.append(val)
        # take an action on your values based on the operator
        if t==0: #sum
            return sum(values),bitstr
        elif t==1: # product
            return prod(values),bitstr
        elif t==2: # min
            return min(values),bitstr
        elif t==3: # max
            return max(values),bitstr
        elif t==5: # gt
            return (values[0] > values[1]),bitstr
        elif t==6: # lt
            return (values[0] < values[1]),bitstr
        elif t==7: # eq
            return (values[0] == values[1]),bitstr




def p1n(f):
    # first lets convert our input to a binary stream
    bitstr = list("".join([bin(int(c,16))[2:].zfill(4) for c in f.readline().strip("\n")]))
    bitstr.reverse()

    # now we can treat it like a stream that we can read a single bit from at a time
    
    # solve
    print(processPacketPart1(bitstr)[0])

def p2(f):
    # first lets convert our input to a binary stream
    bitstr = list("".join([bin(int(c,16))[2:].zfill(4) for c in f.readline().strip("\n")]))
    bitstr.reverse()

    print(processPacketPart2(bitstr)[0])

if __name__ == "__main__":

    f = open("input","r")

    #  p1n(f)

    p2(f)

    f.close()
