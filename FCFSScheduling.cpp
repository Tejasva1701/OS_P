#include<iostream> 
using namespace std;

int main()
{
cout << "--------Hello world!! Welcome to FCFS scheduling	\n";
int n; 
int *ar;

cout << "\nEnter the numbers of processes: "; 
cin >> n;
ar = new int[n];

for(int i=0; i<n; i++)
{
cout << "Enter the burst time for P" << i+1 << " : "; 
cin >> ar[i];
}

cout << "\nProcess\tBurst time\n";

for(int i=0; i<n; i++)
{
cout << "P" << i+1 << " \t" << ar[i] << endl;
}

int temp=0, sum=0;

for(int i=1; i<n; i++)
{
temp = temp+ar[i-1]; sum = sum+temp;
}

cout << "\nTotal waiting time for the processes is		: "	<< sum	<< endl; 
cout << "Average waiting time for the processes is	: " << double(sum)/n << endl;

temp = 0;
sum = 0;

for(int i=0; i<n; i++)
{
temp = temp+ar[i]; sum = sum+temp;
}
 
cout << "Total turnaround time for the processes is : "	<< sum	<< endl; 
cout << "Average turnaround time for the processes is: " << double(sum)/n << endl;

}

