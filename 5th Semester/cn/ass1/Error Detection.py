import random

# CRC IMPLEMENTATION


def xor(a, b):
    # initialize result
    result = []

    # Traverse all bits, if bits are
    # same, then XOR is 0, else 1
    for i in range(1, len(b)):
        if a[i] == b[i]:
            result.append('0')
        else:
            result.append('1')

    return ''.join(result)


def remainderGenerator(dividend,  divisor):
    l = len(divisor)
    f = dividend[0: l]
    while (l < len(dividend)):
        if f[0] == '1':
            f = xor(divisor, f) + dividend[l]
            # print("if, length = ", len(f))

        else:
            f = xor('0' * l, f) + dividend[l]
            # print("else, length = ", len(f))
        l += 1
    if f[0] == '1':
        f = xor(divisor, f)
    else:
        f = xor('0' * l, f)

    return f


def crcEncoder(data, divisor):
    appended_data = data + '0' * (len(divisor)-1)
    remainder = remainderGenerator(appended_data, divisor)
    codeword = data + remainder
    return codeword


# CHECKSUM IMPLEMENTATION
def checksumEncoder(SentMessage, k):
    # Dividing sent message in packets of k bits.
    c1 = SentMessage[0:k]
    c2 = SentMessage[k:2 * k]
    c3 = SentMessage[2 * k:3 * k]
    c4 = SentMessage[3 * k:4 * k]

    # CALCULATING THE BINARY SUM OF PACKETS
    Sum = bin(int(c1, 2) + int(c2, 2) + int(c3, 2) + int(c4, 2))[2:]

    # ADDING THE BITS THAT OVERFLOWED
    if (len(Sum) > k):
        x = len(Sum) - k
        Sum = bin(int(Sum[0:x], 2) + int(Sum[x:], 2))[2:]
    if (len(Sum) < k):
        Sum = '0' * (k - len(Sum)) + Sum

    # CALCULATING THE COMPLEMENT
    Checksum = ''
    for i in Sum:
        if (i == '1'):
            Checksum += '0'
        else:
            Checksum += '1'
    return Checksum


def checkReceiverChecksum(errorMessage, k, prevChecksum):
    # Dividing sent message in packets of k bits.
    c1 = errorMessage[0:k]
    c2 = errorMessage[k:2 * k]
    c3 = errorMessage[2 * k:3 * k]
    c4 = errorMessage[3 * k:4 * k]

    # CALCULATING BINARY SUM OF PACKETS + CHECKSUM
    ReceiverSum = bin(int(c1, 2) + int(c2, 2) + int(prevChecksum, 2) +
                      int(c3, 2) + int(c4, 2))[2:]

    # ADDING THE BITS THAT OVERFLOWED
    if (len(ReceiverSum) > k):
        x = len(ReceiverSum) - k
        ReceiverSum = bin(
            int(ReceiverSum[0:x], 2) + int(ReceiverSum[x:], 2))[2:]

    # CALCULATING THE COMPLEMENT
    ReceiverChecksum = ''
    for i in ReceiverSum:
        if (i == '1'):
            ReceiverChecksum += '0'
        else:
            ReceiverChecksum += '1'
    return ReceiverChecksum


# LRC 2D PARITY CHECK
def lrcEncoder(data):
    temp = data.split()
    n = len(temp)
    redundant = ""
    for i in range(0, 8):
        cnt = 0
        for j in range(0, 4):
            if(temp[j][i] == '1'):
                cnt += 1

        if(cnt % 2 == 0):
            redundant += "0"
        else:
            redundant += "1"

    return redundant


def lrcHelper(data):

    str_modified = data[:8]+' '+data[8:16]+' '+data[16:24]+' '+data[24:]
    redundant = lrcEncoder(str_modified)
    return redundant


# VRC PARITY CHECK
def vrcEncoder(data):
    n = len(data)
    cnt = 0
    for i in range(0, n):
        if(data[i] == '1'):
            cnt += 1

    if(cnt % 2 == 0):
        data = data + "0"
    else:
        data = data + "1"
    return data


def VRCParityCheck(data):
    n = len(data)
    cnt = 0
    for i in range(0, n):
        if (data[i] == '1'):
            cnt += 1
    if (cnt % 2 == 0):
        return True
    else:
        return False


def errorGenerator(data):
    n = len(data)

    pos = 4

    # print(temp)
    while pos > 0:
        index = random.randint(0, n-1)

        if(data[index] == '1'):

            data = data[:index]+'0'+data[index+1:]
        else:

            data = data[:index]+'1'+data[index+1:]

        pos -= 1
    redundant = lrcHelper(data)
    return data, redundant


if __name__ == '__main__':
    dataWord = int(input("Enter your data to be sent = "))
    data = '{:032b}'.format(dataWord)

    error, errored_redundant = errorGenerator(data)

    # 1. VRC
    print()
    print()
    print("**********  VRC ENCODER **********")
    print()
    encoded = vrcEncoder(data)
    encoded_error, _ = errorGenerator(encoded)
    print('VRC encoded = ' + encoded)
    print('Error = ' + encoded_error)
    print()
    print('RESULT : ', end='')
    if(VRCParityCheck(encoded_error)):
        print("Valid data")
    else:
        print("Errored Data")
    print()
    print()

    # 2. LRC
    print()
    print()
    print("**********  LRC ENCODER **********")
    print()
    lrc_redundant = lrcHelper(data)
    print('LRC encoded redundant = ' + lrc_redundant)
    print('Errored redundant = ' + errored_redundant)
    print()
    print('RESULT : ', end='')
    if(lrc_redundant == errored_redundant):
        print("Valid data")
    else:
        print("Errored Data")
    print()
    print()

    # 3. CHECKSUM
    print()
    print()
    print("**********  CHECKSUM ENCODER **********")
    print()
    k = int(input("Enter the packet length for CheckSum = "))
    encoded = checksumEncoder(data, k)
    decoded_after_error = checkReceiverChecksum(error, k, encoded)
    ans = int(decoded_after_error, 2)

    print('CHECKSUM encoded = ' + encoded)
    print('Error = ' + decoded_after_error)
    print()
    print('RESULT : ', end='')
    if(ans == 0):
        print("Valid Data")
    else:
        print("Errored Data")
    print()
    print()

    # 4. CRC
    print()
    print()
    print("**********  CRC ENCODER **********")
    print()
    divisor = int(input("Enter the divisor = "))
    divisor = bin(divisor)[2:]

    encoded = crcEncoder(data, divisor)
    error, _ = errorGenerator(encoded)
    decoded_remainder_after_error = remainderGenerator(error, divisor)
    ans = int(decoded_remainder_after_error, 2)

    print('CRC encoded = ' + encoded)
    print('Data after error insertion = ' + error)
    print('Decoded remainder after error = ' + decoded_remainder_after_error)
    print()
    print('RESULT : ', end='')
    if(ans == 0):
        print("Valid data")
    else:
        print("Errored Data")
    print()
    print()
