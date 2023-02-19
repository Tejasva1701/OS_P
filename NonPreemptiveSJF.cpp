#include<iostream> 
using namespace std;

void insertionSort(int arr[], int n,int p[])
{
int i, key, j,pos;
for (i = 1; i < n; i++)
{
key = arr[i]; pos = p[i]; j = i - 1;

while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
p[j+1] = p[j]; j = j - 1;
}
arr[j + 1] = key; p[j+1] = pos;
}
}

int main()
{
cout<<"--------Hello world!! Welcome to SJF scheduling	\n";
int n,twt;
int *ar,*p,*at,*wt,*t;
cout<<"Enter the numbers of processes: "; cin>>n;
ar = new int[n]; //burst time p = new int[n]; //process
at= new int[n]; //arrival time wt = new int[n]; //wait time
t = new int[n]; //turnaround time for(int i=0;i<n;i++)
{
cout<<"Enter the arrival time and the burst time for P"<<i+1<<" : "; cin>>at[i]>>ar[i];
p[i] = i+1;
}
cout<<"\nProcess\tArrival time\tBurst time\n"; for(int i=0;i<n;i++)
{
cout<<"P"<<i+1<<" \t"<<at[i]<<"\t\t"<<ar[i]<<endl;
 
}
insertionSort(ar,n,p); int temp=0,sum=0; wt[0]=0;
//calc waiting time for(int i=1;i<n;i++)
{
temp=temp+ar[i-1]; wt[i]=temp; sum=sum+temp;
}
twt = sum; temp=0; sum=0;
for(int i=0;i<n;i++)
{
temp=temp+ar[i]; t[i]=temp; sum=sum+temp;
}
cout<<"\nProcess\tBurst time\tWaiting time\tTurnaround time\n"; for(int i=0;i<n;i++)
{
cout<<"P"<<p[i]<<" \t"<<ar[i]<<" \t\t"<<wt[i]<<" \t\t"<<t[i]<<endl;
}
cout<<"Total waiting time for the processes is: "<<twt<<endl; cout<<"Average waiting time for the processes is: "<<double(twt)/n<<endl; cout<<"Total turnaround time for the processes is: "<<sum<<endl; cout<<"Average turnaround time for the processes is: "<<double(sum)/n<<endl;

}

