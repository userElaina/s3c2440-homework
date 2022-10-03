from font import font44, font58, led

f = open('data.txt', 'r').read().split('\n')
l_city = list()
l_des = list()
l_t = list()

flg = True
for i in f:
    if flg:
        a, b = i.split(': ')
        l_city.append(a)
        l_des.append(i)
    else:
        l_t.append(int(i))
    flg = not flg

f = open('data.bin', 'wb')


def w(b: list, c: int):
    if 0 <= c <= 99:
        b.append(led[c // 10])
        b.append(led[c % 10])
    else:
        b.append(0xff)
        b.append(0xff)
    if len(b) != 10:
        print(b)
        assert False
    f.write(bytes(b))


l_city = l_city[1:]
l_des = l_des[1:]
for i in range(len(l_t)):
    bb = list()
    for c in l_des[i]:
        bb += font58[ord(c)]
        bb.append(0)
    # bb += bb[:16]
    for j in range(l_t[i] - 1):
        w(bb[j:j+8], l_t[i] - j)

    a = font44[ord(l_city[i][0])-ord('a')]
    b = font44[ord(l_city[i][1])-ord('a')]
    c = font44[ord(l_city[i][2])-ord('a')]
    d = font44[ord(l_city[i][3])-ord('a')]
    bb = [0]*8
    for j in range(4):
        for k in range(4):
            bb[k] |= (a & 1) << j
            a >>= 1
        for k in range(4, 8):
            bb[k] |= (b & 1) << j
            b >>= 1
    for j in range(4, 8):
        for k in range(4):
            bb[k] |= (c & 1) << j
            c >>= 1
        for k in range(4, 8):
            bb[k] |= (d & 1) << j
            d >>= 1

    for j in range(10):
        w(bb.copy(), 0)
        w(bb.copy(), -1)
