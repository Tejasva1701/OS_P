#include<iostream> 
using namespace std;

void insertionSort(int arr[], int n, int p[], int t[])
{
int i, key, j,pos,time; for (i = 1; i < n; i++)
{
key = arr[i]; pos = p[i]; time = t[i] ; j	= i - 1;

while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
p[j+1]	= p[j];
t[j+1]	= t[j];
j	= j - 1;
}
arr[j + 1] = key; p[j+1]	= pos;
t[j+1]	= time;
}
}

int main()
{
int n, q, t=0;
cout << "	Round Robin Scheduling Algorithm-	-
\n";
cout << "Enter the number of processes: "; cin >> n;
cout << "Enter the time quantum: "; cin >> q;

int p[n], ar[n], at[n], wt[n], tr[n], ct[n], rt[n]; cout << "Enter the arrival and the Burst time:\n"; for(int i=0; i<n; i++)
{
cout << "For process " << i+1 << ": "; cin >> at[i] >>ar[i];
p[i] = i+1;
}
 
cout << "\nProcess\tArrival time\tBurst time\n"; for(int i=0; i<n; i++)
{
cout << "P" << p[i] << " \t" << at[i] << "\t\t" << ar[i] << endl;
}

insertionSort(at, n, p, ar);

for(int i=0; i<n; i++)
{
rt[i] = ar[i];
}

t = at[0];
for(int i=0, j=0; i<n;)
{
if(rt[j]!=0)
{
if(rt[j]<q)
{
 


}
else
{


}
 
t+=rt[j];
rt[j]=0;




t+=q; rt[j]-=q;
 
if(rt[j]==0)
{
ct[j]=t; i++;
}
}
if(at[j+1]<=t)
{
 

}
else
{

}
}
 
j = ++j%n;




j = 0;
 
for(int i=0; i<n; i++)
{
tr[i] = ct[i]-at[i];
wt[i] = tr[i]-ar[i];
}

cout << "\nProcess\tArrival time\tBurst time\tWaiting time\tTurnaround time\n"; for(int i=0; i<n; i++)
{
cout << "P" << p[i] << " \t" << at[i] << "\t\t" << ar[i] << "\t\t" << wt[i] << "\t\t" << tr[i] << endl;
 
}


}

