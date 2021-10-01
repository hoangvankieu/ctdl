//Đệ quy (the recursive)
#include<iostream>
using namespace std;
void Enter(int a[], int n, int i = 0) {
	if (i == n) {
		return;
	}
	else {
		cout << "Nhap a[" << i << "]";
		cin >> a[i];
		Enter(a, n, i + 1);
	}
}
void Display(int a[], int n, int i = 0) {
	if (n == i) {
		return;
	}
	else {
		cout << a[i] << "\t";
		Display(a, n, i + 1);
	}
}
void LietKeChan(int a[], int n, int i = 0) {
	if (i == n) {
		return;
	}
	else {
		if (a[i] % 2 == 0) {
			cout << a[i] << "\t";
		}
	}
	LietKeChan(a, n, i + 1);
}
void PstEven(int a[], int n, int i = 0) {
	if (n == i) {
		return;
	}
	else {
		if (a[i] % 2 == 0) {
			cout << i << "\t";
		}
		PstEven(a, n, i + 1);
	}
}
void SearchMax(int a[], int n, int i = 0) {
	if(n==0){
		cout<<a[i];
		return;
	}
	if(a[n-1]>a[i]){
		i=n-1;
	}
	SearchMax(a,n-1,i);
}

int main() {
	int a[100], n = 5;
	Enter(a, n);
	SearchMax(a, n);
}