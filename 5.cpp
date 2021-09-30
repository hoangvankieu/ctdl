#include<iostream>
#include<fstream>
using namespace std;
void nhap(int G[][10],int &n,int &a,int &b,int &sum){
	ifstream fi;
	fi.open("C:\\Users\\Admin\\Documents\\mactrix.txt", ios_base::in);
	if(fi.fail()==true){
		cout<<"File khong ton tai!";
		return ;
	}
	fi>>n>>a>>b;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fi>>G[i][j];
			sum+=G[i][j];
		}
	}	
}
void Reset(int G[][10],int n,int sum){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j && G[i][j]==0){
				G[i][j]=sum;
			}
		}
	}
}
void Create(int Len[],int S[],int P[],int a,int sum,int n){
	for(int i=0;i<n;i++){
		Len[i]=sum;
		S[i]=0;
		P[i]=a;
	}
	Len[a]=0;
}
void Search(int G[][10],int Len[],int S[],int P[],int n,int a,int b,int sum){
	int i;
	while(!S[b]){
		for(i=0;i<n;i++){
			if(!S[i] && Len[i]<sum){
				break;
			}
		}
		if(i>=n){
			break;
		}
		for(int j=0;j<n;j++){
			if(!S[j] && Len[i]>Len[j]){
				i=j;
			}
		}
		S[i]=1;
		for(int j=0;j<n;j++){
			if(!S[j] && Len[i]+G[i][j]<Len[j]){
				Len[j]= Len[i]+G[i][j];
				P[j]=i;
			}
		}
	}
}
void Display(int Len[],int P[],int S[],int n,int a,int b,int sum){
	int i=b;
	if(Len[b]>0 && Len[b]<sum){
		cout<<"Do dai tu "<<char (a+'A')<<" den "<<char (b+'A')<<" la:"<<Len[b]<<endl;
		while(i!=a){
			cout<<char (i+'A')<<"<-----";
			i=P[i];
		}
		cout<<char (a+'A');
	}
	else{
		cout<<"Khong co duong di!";
	}
}
int main(){
	int n,a,b,G[10][10],sum=0;
	nhap(G,n,a,b,sum);
	int Len[n],S[n],P[n];
	a--;
	b--;
	Reset(G,n,sum);
	Create(Len,S,P,a,sum,n);
	Search(G,Len,S,P,n,a,b,sum);
	Display(Len,P,S,n,a,b,sum);
	return 0;
}