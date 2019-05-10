#include<iostream> 
using namespace std; 
  



void FwaitingTime(int processes[], int n,  
                          int bt[], int wt[]) 
{ 
    
    wt[0] = 0; 
  
    for (int  k = 1; k < n ; k++ ) 
        wt[k] =  bt[k-1] + wt[k-1] ; 
} 

void TurnAroundT( int processes[], int n,  
                  int bt[], int wt[], int tat[]) 
{ 
    for (int  i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 
  
void findAverageTime( int proc[], int n, int bt[]) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
    FwaitingTime(proc, n, bt, wt); 
    TurnAroundT(proc, n, bt, wt, tat); 
  
    cout << "Processes  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n"; 
  
    for (int  k=0; k<n; k++) 
    { 
        total_wt = total_wt + wt[k]; 
        total_tat = total_tat + tat[k]; 
        cout << "   " << k+1 << "\t\t" << bt[k] <<"\t \t"
            << wt[k] <<"\t\t" << tat[k] <<endl; 
    } 
  float us1=(float)total_wt / (float)n; 
  float us2 = (float)total_tat / (float)n; 
    cout << "Average waiting time = "   << us1;
    cout << "\nAverage turn around time = "  << us2;
} 
int main() 
{
    int proc[] = { 1, 2, 3}; 
    int n = sizeof proc / sizeof proc[0]; 
    int  burst_time[] = {13, 4 ,9}; 
    //find avrage tym
    findAverageTime(proc, n,  burst_time); 
    return 0; 
} 
