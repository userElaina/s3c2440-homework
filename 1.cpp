#include <bits/stdc++.h>
int data1[99]{0x48, 0xC4, 0xEC, 0xC8, 0x84, 0xA8, 0xEC, 0x8C, 0xE8, 0xCE, 0x84, 0xC8, 0xAC, 0xCC, 0x8C, 0x4A, 0x8C, 0xAC, 0x00, 0x00, 0xE8, 0xC0, 0x00, 0x00, 0x99, 0xEC, 0xCA, 0xFE, 0xAA, 0x9A, 0xBD, 0xAC, 0xCC, 0x44, 0xAA, 0xF4, 0xDB, 0xE8, 0x48, 0x24, 0xE4, 0xFA, 0x99, 0x00, 0x00, 0xF0, 0x00, 0x00, 0xAF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

int data2[36];

int main() {
    memset(data2, 0, sizeof(data2));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 6; k++) {
                int x = data1[i * 24 + j * 6 + k] >> 4;
                if((x&1)^((x>>3)&1)){
                    x ^= 0b1001;
                }
                if(((x>>1)&1)^((x>>2)&1)){
                    x ^= 0b0110;
                }
                data2[(i * 6 + k) << 1] |= x << (j << 2);

                x = data1[i * 24 + j * 6 + k] & 15;
                if((x&1)^((x>>3)&1)){
                    x ^= 0b1001;
                }
                if(((x>>1)&1)^((x>>2)&1)){
                    x ^= 0b0110;
                }
                if (i * 12 + k * 2 == 0) {
                    printf("%x %d\n", x >> 4, j);
                }
                data2[(i * 6 + k) << 1 | 1] |= x << (j << 2);
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        int x = data2[i];
        printf("0x%04x, ", x);
        // putchar('a' + i);
        // putchar(10);
        // for (int j = 0; j < 4; j++) {
        //     for (int k = 0; k < 4; k++) {
        //         putchar(x & 1 ? '@' : ' ');
        //         x >>= 1;
        //     }
        //     putchar(10);
        // }
        // putchar(10);
    }
}