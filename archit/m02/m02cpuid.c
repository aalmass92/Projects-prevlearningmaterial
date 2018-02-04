#include <stdio.h>


void main(){

 int reg_a, reg_b, reg_c, reg_d;
  
 int request_code = 2; 
  
  asm volatile ( "cpuid" : "=a"(reg_a), "=b"(reg_b), "=c"(reg_c),
		 "=d"(reg_d) : "0"(request_code));

  printf("EAX: 0x%05x\n", reg_a);
  printf("EBX: 0x%05x\n", reg_b); 
  printf("ECX: 0x%05x\n", reg_c);
  printf("EDX: 0x%05x\n", reg_d);

  //return 0;

}
