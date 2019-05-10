#include<bits/stdc++.h> 
                                      // increasing short j f 
using namespace std;                  
struct proc 
{ 
   int prid;  
   int btt;  
}; 

bool compared(proc h, proc kbnn) 
{ 
     return (h.btt < kbnn.btt); 
} 
void waitnigTimeToBeFound(proc pro[], int number, int wat[]) 
{  
    wat[0] = 0; //first procs 
    for (int i = 1; i < number ; i++ ) 
        wat[i] = pro[i-1].btt + wat[i-1] ; 
} 
void turnAroundtimeToBFound(proc pro[], int number, int wat[], int tt[]) 
{ 
    
    for (int i = 0; i < number ; i++) 
    tt[i] = pro[i].btt + wat[i]; 
} 
  
void avgtime(proc pro[], int number) 
{ 
    int wat[number], tt[number], total_wat = 0, total_tt = 0; 
  
    
    waitnigTimeToBeFound(pro, number, wat);  
    turnAroundtimeToBFound(pro, number, wat, tt); 
    cout << "\n\n processes ";
	cout<< "  Burst time ";
	cout<< "Waiting time " ;
	cout<< "Turn around time\n"; 
    for (int i = 0; i < number; i++) 
    { 
        total_wat = total_wat + wat[i]; 
        total_tt = total_tt + tt[i]; 
        cout << "    " << pro[i].prid << " "<< "\t\t"<< pro[i].btt << "\t " << wat[i] << "\t\t " << tt[i] <<endl; 
    } 
    cout << "Avg waiting time = "<< (float)total_wat / (float)number; 
    cout << "\nAvge turn around time = "<< (float)total_tt / (float)number; 
} 
   
int main() 
{ 
    proc pro[] = {{1, 6}, {2, 8}, {3, 7}, {4, 3}}; 
    cout<<" ";
    int number = sizeof pro / sizeof pro[0]; 
    sort(pro, pro + number, compared); // Sorting procses by burst time. 
  
    cout << "process execution order: "; 
    for (int i = 0 ; i < number; i++) 
        cout << pro[i].prid <<" "; 
    avgtime(pro, number); 
    return 0; 
}
