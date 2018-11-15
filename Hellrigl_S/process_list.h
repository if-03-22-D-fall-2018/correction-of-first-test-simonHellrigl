/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			process_list.h
 * Author:			P. Bauer
 * Due Date:		December 3, 2010
 * ----------------------------------------------------------
 * Description:
 * process_list.h definiert Funktionen zur Verwaltung von UNIX
 * Prozesseinträgen.
 * ----------------------------------------------------------
 */

#ifndef ___Process_List
#define ___Process_List
#define MAX_LIST_ENTRIES   13

enum ProcessState{RUNNING, SLEEPING, IDLE, ZOMBIE, SWAPPEDOUT, STOPPED};

 struct ProcessList{
   int length;
   struct ProcessListEntry * 	processes [MAX_LIST_ENTRIES];
 };

 struct ProcessListEntry{
   int pid;
   const char* process_name;
   int cpu_usage;
   int time;
   int threads;
   long vsize;
   enum ProcessState state;

 };




     bool add_entries (ProcessList *  pl,struct ProcessListEntry *  	e[],int  	n );
     bool add_entry (ProcessList *  pl, struct ProcessListEntry *  	e	);
     int get_bottom_n_processes_cpu 	( 	const ProcessList *  	pl,int  	n,	struct ProcessListEntry *  	result_list[] );


     int get_length 	( 	const ProcessList *  	pl	);


     struct ProcessListEntry* get_process_with_highest_cpu_consumption 	(const ProcessList *  	pl);
     int get_process_with_id 	(const ProcessList *  	pl,int  	id,	struct ProcessListEntry *  	result_list[] );
     struct ProcessListEntry* get_process_with_lowest_cpu_consumption 	( 	const ProcessList *  	pl	);
     int get_processes_with_state 	( 	const ProcessList *  	pl, enum ProcessState  	state,struct ProcessListEntry *  	result_list[] );
     int get_top_n_processes_cpu 	( 	const ProcessList *  	pl,int  	n,struct ProcessListEntry *  	result_list[] );
     void init_process_list 	( 	ProcessList *  	pl	);
     //MAX_LIST_ENTRIES



 #endif
