#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
///#include <linux/delay.h>

#define TUBE_IOCTROL 0x11
#define DOT_IOCTROL 0x12

#define B unsigned char

void jmdelay(int n) {
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < 100; j++)
            for (k = 0; k < 100; k++)
                ;
}

int main() {
    int fd;
    fd = open("/dev/s3c2440_led0", O_RDWR);
    if (fd < 0) {
        printf("ERROR: Led device open failed\n");
        return (-1);
    }

    ioctl(fd, 0x12, 0xff00);
    sleep(1);

    FILE *f;
    f = fopen("a.bin", "rb");
    B *buf;
    buf = (B *)malloc(10);

    unsigned int LEDWORD;
    while (10 == fread(buf, 1, 10, f)) {
        LEDWORD = buf[8] << 8 | buf[9];
        ioctl(fd, 0x12, LEDWORD);
        jmdelay(1500);
        // buf[8] = buf[9] = 0;
        write(fd, buf, 10);
        jmdelay(1500);
    }

    close(fd);
    return 0;
}
