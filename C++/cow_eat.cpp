#include<iostream>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
	int i,j,c=0,d=0,e,f;
	int a,b,m=0,n=0;
    char A[25][25];
	cin>>a>>b;
	for (i=0;i<a;i++)
	{
		for (j=0;j<b;j++)
	    {
	    	cin>>A[i][j];
	    	if(A[i][j] == '.') 
	    	{
	    		m += (i+1);
	    		n += (j+1);
	    		c++;
			}		
	    }
	}
	m=m/c;
	n=n/c;
	for (i=0;i<a;i++)
	{
		for (j=0;j<b;j++)
	    {
	    	
	    	if(A[i][j] == '.') 
	    	{
	    		if(m-i-1>0) e = m-i-1;
	    		else e = i-m+1;
	    		if(n-j-1>0) f = n-j-1;
	    		else f = j-n+1;
	    		if(d < (e+f)) d=e+f;
			}		
	    }
	}
	cout<<d<<" "<<m<<" "<<n<<endl;
}	
	return 0;
} 
