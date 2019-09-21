#include<stdio.h>
int count(int ar[],int n);
int max = 999999;
void sort(int ar[],int start,int n);
void merge(int ar1[],int m,int ar2[],int n,int C[]);

void swap(int ar[],int start,int minpos);
int main(){

 int m,n,o,p,q,i,r,s,t,u,c;
    scanf("%d %d %d %d %d",&m,&n,&o,&p,&q);
    r = m+n;
    s = o+p;
    t = r+s;
    u = t+q;
    
    
  int ar1[m],ar2[n],ar3[o],ar4[p],ar5[q],C[r],ar[m],D[s],E[t],F[u];
    

    for(i = 0;i<m;i++)
     scanf("%d",&ar1[i]);
     
    for(i = 0;i<n;i++)
     scanf("%d",&ar2[i]); 
    
    for(i = 0;i<o;i++)
     scanf("%d",&ar3[i]);
    
    for(i = 0;i<p;i++)
     scanf("%d",&ar4[i]);
     
    for(i = 0;i<q;i++)
     scanf("%d",&ar5[i]);
    
    for(i = 0;i<r;i++)
      C[i] = max;
     
    for(i=0;i<s;i++)
     D[i] = max;
  	for(i=0;i<t;i++)
     E[i] = max;
	for(i=0;i<u;i++)
     F[i] = max;

  

 
  sort(ar1,0,m);
  sort(ar2,0,n);
  sort(ar3,0,o);
  sort(ar4,0,p);
  sort(ar5,0,q);
  
  merge(ar1,m,ar2,n,C);
  merge(ar3,o,ar4,p,D);
  merge(C,r,D,s,E);
  
 merge(E,t,ar5,q,F);

  c =  count(F,u);
  printf("%d",c);
  
}

void sort(int ar[],int start,int n)
{
  int i;
  if(start>=n)
    return;
  //locate minimum element and move to start of segment
  
  int minpos = start;
  for(i = start+1;i<n;i++)
    if(ar[i]<ar[minpos])
      minpos = i;
    swap(ar,start,minpos);
  //Recursively Sort the rest
  sort(ar,start+1,n);
}

void swap(int ar[],int start,int minpos)
{
 
  int temp,i;
  temp = ar[start];
  ar[start] = ar[minpos];
  ar[minpos] = temp;
  
}
void merge(int A[],int m,int B[],int n,int C[]){

  //Merge A[0...m-1,B[0...n-1] into C[0...m+n-1]
  
  int i = 0,j = 0,k =0;
  
  //Current positions in A,B,C respectively
  while(k<m+n)
  {
     
    // Case 1:Move head of A into C
    
    if(j==n){
      C[k] = A[i];
      i++;
      k++;
      
    }
     //Case 2:Move head of B into C
    else if((i==m)){
        
      C[k] = B[j];
       j++;
       k++;
    }
    else if(A[i]<=B[j]){
      C[k] = A[i];
      i++;
      k++;
    }
    else if(A[i]>B[j])
    {
      C[k] = B[j];
      j++;
      k++;
    }
    
    
  
  }
    
}

int count(int ar[],int n){
  int i,j,count1=1,count=0;
  for(i=0;i<n;)
    {  
        count1=1;
        for(j=i+1;j<n;++j)
        {
            if(ar[j]==ar[i])
            {
                count1++;
                
            }
            else{
                
                break;
            }
        }
        i=j;
        if(count1>=3)
          ++count;
    }
  return count;
}
