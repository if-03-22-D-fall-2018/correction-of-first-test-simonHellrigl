/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			grade_list.c
 * Author:			P. Bauer
 * Due Date:		November 18, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of grade_list.h.
 * ----------------------------------------------------------
 */
 #include "process_list.h"
 #include <stdbool.h>
 #include <stdio.h>

int get_length( const ProcessList * 	pl);

 bool add_entries (ProcessList *  pl,struct ProcessListEntry *  	e[],int  	n )
 {

   //deleted for loop
     if ((pl->length+n) <= MAX_LIST_ENTRIES) { //+n and <=
       int added = 0;                           //new int
       for (int i = 0; i < n; i++) {        //new for loop
         if (e[i] != 0) {     //new if (checks if e isnt empty)
           pl->processes[pl->length+i] = e[i];   //assign e to processes
           added++;                               //increase n
         }


       }
       pl->length += n;   //added n to length
       return true;   //return true if entry is possible
     }
     return false;   // else return false
    //deleted code




 }
 bool add_entry (ProcessList *  pl, struct ProcessListEntry *  	e	)
 {
   if (pl->length < MAX_LIST_ENTRIES ) {

     pl->length += 1;
     pl->processes[pl->length] = e; //initialize processes with e if it isnt full
     return true;                   //added return true here
   }


   return false;



 }
 int get_bottom_n_processes_cpu 	( 	const ProcessList *  	pl,int  	n,	struct ProcessListEntry *  	result_list[] )
 {
      return 0;
 }


 int get_length( const ProcessList * 	pl)
 {
   return pl->length;
 }


 struct ProcessListEntry* get_process_with_highest_cpu_consumption 	(const ProcessList *  	pl)
 {
   return pl->processes[1]; //this is just implemented bechause we need a return value for the uniTests.

 }
 int get_process_with_id 	(const ProcessList *  	pl,int  	id,	struct ProcessListEntry *  	result_list[] )
 {
   //int entries_found=0; not needed anymore
    for (size_t i = 0; i < pl->length; i++) {

      if (pl->processes[i] != 0 && pl->processes[i]->pid == id) {  //added condition (if process is empty)
        result_list[0] = pl->processes[i]; //assign process to results
        return 1;      //=1 statt ++

      }

    }
    return 0;  //return 0
 }
 struct ProcessListEntry* get_process_with_lowest_cpu_consumption 	( 	const ProcessList *  	pl	)
 {
   return pl->processes[1]; //this is just implemented bechause we need a return value for the uniTests.


 }
 int get_processes_with_state 	( 	const ProcessList *  	pl, enum ProcessState  	state,struct ProcessListEntry *  	result_list[] )
 {
   int entries_found=0;
    for (size_t i = 0; i < pl->length; i++) {

      if (pl->processes[i] != 0) {  //new if

        if (pl->processes[i]->state == state ) {
          result_list[entries_found] = pl->processes[i];  //saving valid process in result_list
          entries_found ++;                                      //Dont return it here
        }
      }

    }
    return entries_found;

 }
 int get_top_n_processes_cpu 	( 	const ProcessList *  	pl,int  	n,struct ProcessListEntry *  	result_list[] )
 {
   return 0;

 }
 void init_process_list 	( 	ProcessList *  	pl	)
 {
   pl->length = 0;
   for (int i = 0; i < MAX_LIST_ENTRIES; i++)
   {
       pl->processes[i] = 0;
   }

 }
