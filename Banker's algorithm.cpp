#include<iostream>
using namespace std;
int A;//Num of Processes
int B;//Num of resourse
int sequence[20];
int allocat[20][20],
RNN[20][20],
available[20];
int cd;

void getdata()//get data from user
{
	 cout<<"Enter Num of Processes  : ";
	 
    cin>>A;
    
    cout<<"Enter Num of resourse : ";
    
    cin>>B;
    
    cout<<" Enter number of instances available of each resource : ";
    for(int i=0;i<B;i++)
        cin>>available[i];
    for(int i=0;i<A;i++)
    {
        cout<<" number of instances of resources allocatocated  p["<<i<<"] : ";
        for(int y=0;y<B;y++)
            cin>>allocat[i][y];
    }
    for(int i=0;i<A;i++)
    {
        cout<<"maximum number of instances of resources process p["<<i<<"] needs : ";
        for(int y=0;y<B;y++)
            cin>>RNN[i][y];
    }
}

int com_pr()
{
	 int flag=0;
	 int fl=0;
    for(int i=0;i<A;i++)
    {
        for(int j=0;j<cd;j++)
            if(A==sequence[j])
            {
                fl=1;
                break;
            }
        if(fl!=1)
        {
            for(int j=0;j<B;j++)
            {
                if(available[j]-RNN[A][j]+allocat[A][j]<0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                return A;
            flag=0;
        }
        fl=0;
    }
    return -1;
}
void safe_sequence()
{
    int temp,flag=0;
    cd=0;
    for(int i=0;i<A;i++)
    {
        temp=com_pr();
        if(temp!=-1)
        {
            for(int y=0;y<B;y++)
                available[y]+=allocat[temp][y];
            sequence[cd++]=temp;
        }
        else{
            cout<<"\n  System in  unsafe state  ";
            flag=1;
            break;}
    }
    if(flag!=1)
    {
        cout<<"     Safe sequence created : ";
        for(int i=0;i<cd;i++)
            cout<<"p["<<sequence[i]<<"]  ";
    }
}

int main()
{
    getdata();
    safe_sequence();
    return 0;
}
