void
printproc(char state, int ppid, int pgid, unsigned long long mm_start_code, unsigned long long mm_end_code, unsigned long long mm_start_stack, unsigned long long esp, unsigned long long eip) {
	printf("State:\t\t\t%c\n", state);
	printf("ParentPid:\t\t%d\n", ppid);
	printf("ParentGid:\t\t%d\n", pgid);
	printf("StartCode:\t\t0x%x\n", mm_start_code);
	printf("EndCode:\t\t0x%x\n", mm_end_code);
	printf("StartStack:\t\t0x%x\n", mm_start_stack);
	printf("ESP:\t\t\t0x%x\n", esp);
	printf("EIP:\t\t\t0x%x\n", eip);
}


