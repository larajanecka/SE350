/**
 * @file:   k_memory.h
 * @brief:  kernel memory managment header file
 * @author: GG (yes re), Reesey, RayMak, and LJ
 * @date:   2015/02/01
 */
 
#ifndef K_MEM_H_
#define K_MEM_H_

#include "k_rtx.h"

/* ----- Definitions ----- */
#define RAM_END_ADDR 0x10008000
#define BLOCK_SIZE 128


/* ----- Variables ----- */
/* This symbol is defined in the scatter file (see RVCT Linker User Guide) */  
extern unsigned int Image$$RW_IRAM1$$ZI$$Limit; 

extern PCB **gp_pcbs;
extern PCB *gp_current_process;
extern PROC_INIT g_proc_table[NUM_TEST_PROCS];


/* ----- Functions ------ */
int k_release_processor(void);
void memory_init(void);
U32 *alloc_stack(U32 size_b);
void *k_request_memory_block(void);
int k_release_memory_block(void *);
void pushToReadyQ (int priority, PCB* p_pcb_old);
PCB* popFromReadyQ (int priority);
Queue* getReadyQ(int priority);
Queue* getBlockedResourceQ(int priority);
int getMSP (void);
int k_get_total_num_blocks(void);

#endif /* ! K_MEM_H_ */
