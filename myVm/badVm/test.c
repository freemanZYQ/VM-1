#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<string.h>
#include<unistd.h>

#include"vmopcode.h"

// v03D-@/e+{iTq=sD
//118 48 51 68 45 64 47 101 43 123 105 84 113 61 115 68
uint8_t vm_codeTest[]={
    MovImm2Reg,0x11,0x11,0x11,0x11,EBX,//MovImm2Reg 0x11111111 ebx
    PushReg32,ECX,                    //PushReg32    ecx
    PushImm32,0x22,0x22,0x22,0x22,   //PushImm32 0x22222222
    PopReg32,EDX,                  //PopReg32 edx
    PushMem32,0x00,                  //PushMem32 0ffset[0x0]
    Nop,                       //vNop
    PopReg32,ESI,                  //PopReg32 esi
    MovImm2Reg,0x11,0x11,0x11,0x11,EAX,//MovImm2Reg 0x11111111 eax
    Sal,0x10,                  // sal
    RET                            //RET
};

uint8_t vm_code[] = {
    //init data
    //one 20
    MovMem2Reg,0x0,EAX,
    MovReg2Reg,EAX,EBX,
    Sal,0x18,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,116,0x0,0x0,0x0,EDI,
    PushReg32,EDI,
    
    //two 17
    MovReg2Reg,EBX,EAX,
    Sal,0x10,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,66,0x0,0x0,0x0,EDI,
    PushReg32,EDI,

    //three 17
    MovReg2Reg,EBX,EAX,
    Sal,0x8,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,15,0x0,0x0,0x0,EDI,
    PushReg32,EDI,

    //four 15
    MovReg2Reg,EBX,EAX,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,66,0x0,0x0,0x0,EDI,
    PushReg32,EDI,

    //5
    MovMem2Reg,0x1,EAX,
    MovReg2Reg,EAX,EBX,
    Sal,0x18,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,96,0x0,0x0,0x0,EDI,
    PushReg32,EDI,
    
    //6
    MovReg2Reg,EBX,EAX,
    Sal,0x10,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,92,0x0,0x0,0x0,EDI,
    PushReg32,EDI,

    //7
    MovReg2Reg,EBX,EAX,
    Sal,0x8,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,77,0x0,0x0,0x0,EDI,
    PushReg32,EDI,

    //8
    MovReg2Reg,EBX,EAX,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,28,0x0,0x0,0x0,EDI,
    PushReg32,EDI,
    
    //9
    MovMem2Reg,0x2,EAX,
    MovReg2Reg,EAX,EBX,
    Sal,0x18,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,93,0x0,0x0,0x0,EDI,
    PushReg32,EDI,
    
    //10
    MovReg2Reg,EBX,EAX,
    Sal,0x10,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,22,0x0,0x0,0x0,EDI,
    PushReg32,EDI,

    //11
    MovReg2Reg,EBX,EAX,
    Sal,0x8,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,122,0x0,0x0,0x0,EDI,
    PushReg32,EDI,

    //12
    MovReg2Reg,EBX,EAX,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,22,0x0,0x0,0x0,EDI,
    PushReg32,EDI,

    //13
    MovMem2Reg,0x3,EAX,
    MovReg2Reg,EAX,EBX,
    Sal,0x18,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,120,0x0,0x0,0x0,EDI,
    PushReg32,EDI,
    
    //14
    MovReg2Reg,EBX,EAX,
    Sal,0x10,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,14,0x0,0x0,0x0,EDI,
    PushReg32,EDI,

    //15
    MovReg2Reg,EBX,EAX,
    Sal,0x8,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,14,0x0,0x0,0x0,EDI,
    PushReg32,EDI,

    //16
    MovReg2Reg,EBX,EAX,
    Sar,0x18,
    PushReg32,EAX,
    MovImm2Reg,73,0x0,0x0,0x0,EDI,
    PushReg32,EDI,

    //276 + 18 = 294
    MovImm2Reg,0x16,0x0,0x0,0x0,ECX,
    MovImm2Reg,0x0,0x0,0x0,0x0,EBX,
    XorReg2Reg,EDX,EDX,
    XorReg2Reg,ESI,ESI,

    // 294 + 33 = 327
    Jmp,324,
    MovReg2Reg,EBX,EDI,
    AddImm2Reg,0x30,0x0,0x0,0x0,EDI,
    PopReg32,EAX,
    PopReg32,ESI,
    XorReg2Reg,EDI,EAX,
    XorReg2Reg,ESI,EAX,
    AddReg2Reg,EAX,EDX,
    AddImm2Reg,0x1,0x0,0x0,0x0,EBX,
    CmpReg2Reg,EBX,ECX,
    
    Jb,296,
    MovReg2Mem,EDX,4,

    Nop,
    RET

};

void vm_init(vm_cpu *cpu)	
{
    cpu->v_eax = 0;
    cpu->v_ebx = 0;
    cpu->v_ecx = 0;
    cpu->v_edx = 0;

    cpu->v_esi = 0;
    cpu->v_edi = 0;

    cpu->v_ebp = (uint8_t *)vm_code;
    cpu->v_esp = 0xffffffff;
    cpu->v_efl = 0;

    cpu->v_eip = (uint8_t *)vm_code;

    cpu->op_list[0].opcode = 0xe1;
    cpu->op_list[0].handle = (void (*)(void *))vPushReg32;
    cpu->op_list[1].opcode = 0xe3;
    cpu->op_list[1].handle = (void (*)(void *))vPushImm32;
    cpu->op_list[2].opcode = 0xe4;
    cpu->op_list[2].handle = (void (*)(void *))vPushMem32;
    cpu->op_list[3].opcode = 0xe5;
    cpu->op_list[3].handle = (void (*)(void *))vPopReg32;

    cpu->op_list[4].opcode = 0xa1;
    cpu->op_list[4].handle = (void (*)(void *))vMovImm2Reg;
    cpu->op_list[5].opcode = 0xa2;
    cpu->op_list[5].handle = (void (*)(void *))vMovReg2Reg;
    cpu->op_list[6].opcode = 0xa3;
    cpu->op_list[6].handle = (void (*)(void *))vMovMem2Reg;
    cpu->op_list[7].opcode = 0xa4;
    cpu->op_list[7].handle = (void (*)(void *))vMovReg2Mem;

    cpu->op_list[8].opcode = 0xa5;
    cpu->op_list[8].handle = (void (*)(void *))vAddReg2Reg;
    cpu->op_list[9].opcode = 0xa6;
    cpu->op_list[9].handle = (void (*)(void *))vAddImm2Reg;
    cpu->op_list[10].opcode = 0xa7;
    cpu->op_list[10].handle = (void (*)(void *))vAddMem2Reg;
    cpu->op_list[11].opcode = 0xa8;
    cpu->op_list[11].handle = (void (*)(void *))vAddImm2Mem;
    cpu->op_list[12].opcode = 0xa9;
    cpu->op_list[12].handle = (void (*)(void *))vAddReg2Mem;
    cpu->op_list[13].opcode = 0xa0;
    cpu->op_list[13].handle = (void (*)(void *))vAddMem2Mem;

    cpu->op_list[14].opcode = 0xe6;
    cpu->op_list[14].handle = (void (*)(void *))vMulReg2Reg;
    cpu->op_list[15].opcode = 0xe7;
    cpu->op_list[15].handle = (void (*)(void *))vMulImm2Reg;
    cpu->op_list[16].opcode = 0xe8;
    cpu->op_list[16].handle = (void (*)(void *))vMulMem2Reg;
    cpu->op_list[17].opcode = 0xe9;
    cpu->op_list[17].handle = (void (*)(void *))vMulImm2Mem;
    cpu->op_list[18].opcode = 0xea;
    cpu->op_list[18].handle = (void (*)(void *))vMulReg2Mem;
    cpu->op_list[19].opcode = 0xeb;
    cpu->op_list[19].handle = (void (*)(void *))vMulMem2Mem;

    cpu->op_list[20].opcode = 0xc0;
    cpu->op_list[20].handle = (void (*)(void *))vXorReg2Reg;
    cpu->op_list[21].opcode = 0xc1;
    cpu->op_list[21].handle = (void (*)(void *))vXorImm2Reg;
    cpu->op_list[22].opcode = 0xc2;
    cpu->op_list[22].handle = (void (*)(void *))vXorMem2Reg;
    cpu->op_list[23].opcode = 0xc3;
    cpu->op_list[23].handle = (void (*)(void *))vXorImm2Mem;
    cpu->op_list[24].opcode = 0xc4;
    cpu->op_list[24].handle = (void (*)(void *))vXorReg2Mem;
    cpu->op_list[25].opcode = 0xc5;
    cpu->op_list[25].handle = (void (*)(void *))vXorMem2Mem;

    cpu->op_list[26].opcode = 0xb0;
    cpu->op_list[26].handle = (void (*)(void *))vJmp;
    cpu->op_list[27].opcode = 0xb1;
    cpu->op_list[27].handle = (void (*)(void *))vJa;
    cpu->op_list[28].opcode = 0xb2;
    cpu->op_list[28].handle = (void (*)(void *))vJb;
    cpu->op_list[29].opcode = 0xb3;
    cpu->op_list[29].handle = (void (*)(void *))vJe;
    cpu->op_list[30].opcode = 0xb4;
    cpu->op_list[30].handle = (void (*)(void *))vJz;

    cpu->op_list[31].opcode = 0x99;
    cpu->op_list[31].handle = (void (*)(void *))vSal;
    cpu->op_list[32].opcode = 0x88;
    cpu->op_list[32].handle = (void (*)(void *))vSar;
    cpu->op_list[33].opcode = 0x77;
    cpu->op_list[33].handle = (void (*)(void *))vCmpReg2Reg;
    cpu->op_list[34].opcode = 0x66;
    cpu->op_list[34].handle = (void (*)(void *))vNop;


    vm_stack = malloc(0x1024);
    memset(vm_stack,0,0x1024);
    //init mem section
    vm_MemBase = (uint32_t*)(vm_stack+4*0x512);
}

void vm_dispatcher(vm_cpu *cpu)
{
    uint8_t i;
    for(i=0 ; i < OPCODE_N ; i++) 
    {
        if(*cpu->v_eip == cpu->op_list[i].opcode)	
        {
            cpu->op_list[i].handle(cpu);//(void (*)(void *))
            break;
        }
    }
    
}

void vm_start(vm_cpu *cpu)
{

    cpu->v_eip = (uint8_t*)vm_code;
    while((*cpu->v_eip)!= RET)
    {
        vm_dispatcher(cpu);
    }

}

int main(int argc, char ** argv){

    vm_cpu *cpu={0};
    puts("power by badrer");
    puts("---------------------");
    puts("please input the flag:");
    setbuf(stdin,0);
    setbuf(stdout,0);
    setbuf(stderr,0);

    vm_init(&cpu);

    read(0,vm_MemBase,16);

    vm_start(&cpu);

    if(*(vm_MemBase+4) == 0x8){
        printf("You Win!\n");
    }else{
        printf("You Lost!\n");
    }

    exit(0);

    return 0;
}