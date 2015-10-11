#include <stdio.h>
#include <unistd.h>
#include <setjmp.h>
int fork() {
    void *RIP;
    void *RSP;
    //void *EFLAGS;
    void *RAX;
    void *RBX;
    void *RCX;
    void *RDX;
    void *RSI;
    void *RDI;
    void *RBP;
    void *R08;
    void *R09;
    void *R10;
    void *R11;
    void *R12;
    void *R13;
    void *R14;
    void *R15;
    //__asm __volatile("mov %%rip, %0" :  "=m" (RIP) :);
    //__asm __volatile("push %%rip");
    //__asm __volatile("pop %%rax");

    __asm __volatile("mov %%rsp, %0" :  "=m" (RSP) :);
    //    __asm __volatile("mov %%eflags, %0" :  "=m" (EFLAGS) :);
    __asm __volatile("mov %%rax, %0" :  "=m" (RAX) :);
    __asm __volatile("mov %%rbx, %0" :  "=m" (RBX) :);
    __asm __volatile("mov %%rcx, %0" :  "=m" (RCX) :);
    __asm __volatile("mov %%rdx, %0" :  "=m" (RDX) :);
    __asm __volatile("mov %%rsi, %0" :  "=m" (RSI) :);
    __asm __volatile("mov %%rdi, %0" :  "=m" (RDI) :);
    __asm __volatile("mov %%rbp, %0" :  "=m" (RBP) :);
    __asm __volatile("mov %%r8, %0" :  "=m" (R08) :);
    __asm __volatile("mov %%r9, %0" :  "=m" (R09) :);
    __asm __volatile("mov %%r10, %0" :  "=m" (R10) :);
    __asm __volatile("mov %%r11, %0" :  "=m" (R11) :);
    __asm __volatile("mov %%r12, %0" :  "=m" (R12) :);
    __asm __volatile("mov %%r13, %0" :  "=m" (R13) :);
    __asm __volatile("mov %%r14, %0" :  "=m" (R14) :);
    __asm __volatile("mov %%r15, %0" :  "=m" (R15) :);

    //printf("%p\n", RIP);
    printf("RSP:%p\n", RSP);
    //printf("%p\n", EFLAGS);
    printf("RAX:%p\n", RAX);
    printf("RBX:%p\n", RBX);
    printf("RCX:%p\n", RCX);
    printf("RDX:%p\n", RDX);
    printf("RSI:%p\n", RSI);
    printf("RDI:%p\n", RDI);
    printf("RBP:%p\n", RBP);
    printf("R08:%p\n", R08);
    printf("R09:%p\n", R09);
    printf("R10:%p\n", R10);
    printf("R11:%p\n", R11);
    printf("R12:%p\n", R12);
    printf("R13:%p\n", R13);
    printf("R14:%p\n", R14);
    printf("R15:%p\n", R15);
    int is_parent = 1;
    jmp_buf buf;
    if (is_parent == 1) {
        setjmp(buf);
        printf("%x %x %x %x %x %x %x %x %x %x %x\n", buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7], buf[8], buf[9], buf[10]);
        return 0;
    } else {
        jmp_buf buf;
    }
}
int main(void) {
    int tmp[8];
    printf("%d %d\n", sizeof(tmp[0]), sizeof(tmp));
    void *RIP;
    void *RSP;
    //void *EFLAGS;
    void *RAX;
    void *RBX;
    void *RCX;
    void *RDX;
    void *RSI;
    void *RDI;
    void *RBP;
    void *R08;
    void *R09;
    void *R10;
    void *R11;
    void *R12;
    void *R13;
    void *R14;
    void *R15;
    int ret = fork();
    if (ret == 0) {
        printf("OK\n");
    }
/*    //__asm __volatile("mov %%rflags, %0" :  "=m" (RIP) :);
    __asm __volatile("mov %0, %%rsp" :  :"m" (RSP));
    //    __asm __volatile("mov %%eflags, %0" :  "=m" (EFLAGS) :);
    __asm __volatile("mov %0, %%rax" :  :"m" (RAX));
    __asm __volatile("mov %0, %%rbx" :  :"m" (RBX));
    __asm __volatile("mov %0, %%rcx" :  :"m" (RCX));
    __asm __volatile("mov %0, %%rdx" :  :"m" (RDX));
    __asm __volatile("mov %0, %%rsi" :  :"m" (RSI));
    __asm __volatile("mov %0, %%rdi" :  :"m" (RDI));
    __asm __volatile("mov %0, %%rbp" :  :"m" (RBP));
    __asm __volatile("mov %0, %%r8" :  :"m" (R08));
    __asm __volatile("mov %0, %%r9" :  :"m" (R09));
    __asm __volatile("mov %0, %%r10" :  :"m" (R10));
    __asm __volatile("mov %0, %%r11" :  :"m" (R11));
    __asm __volatile("mov %0, %%r12" :  :"m" (R12));
    __asm __volatile("mov %0, %%r13" :  :"m" (R13));
    __asm __volatile("mov %0, %%r14" :  :"m" (R14));
    __asm __volatile("mov %0, %%r15" :  :"m" (R15));
    printf("\n");
    //printf("%p\n", RIP);
    printf("RSP:%p\n", RSP);
    //printf("%p\n", EFLAGS);
    printf("RAX:%p\n", RAX);
    printf("RBX:%p\n", RBX);
    printf("RCX:%p\n", RCX);
    printf("RDX:%p\n", RDX);
    printf("RSI:%p\n", RSI);
    printf("RDI:%p\n", RDI);
    printf("RBP:%p\n", RBP);
    printf("R08:%p\n", R08);
    printf("R09:%p\n", R09);
    printf("R10:%p\n", R10);
    printf("R11:%p\n", R11);
    printf("R12:%p\n", R12);
    printf("R13:%p\n", R13);
    printf("R14:%p\n", R14);
    printf("R15:%p\n", R15);
*/
    return 0;
}
