#include <linux/futex.h>
#include <sys/syscall.h>
#include <unistd.h>
int futex_wait(int *addr, int expected) { // futex_wait(&number, 0); with int number = 0;
    return syscall(SYS_futex, addr, FUTEX_WAIT, expected, NULL, NULL, 0);
}

int futex_wake(int *addr, int count) { // futex_wake(&number, 1); // count of thread to wake
    return syscall(SYS_futex, addr, FUTEX_WAKE, count, NULL, NULL, 0);
}
