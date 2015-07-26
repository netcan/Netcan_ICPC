#include <iostream>
#include <cstring>
using namespace std;

void to36(long long n, char * id) {
	int i=0;
	int base = 36;
	while(n > 0) {
		id[i++] = n%base;
		n/=base;
	}
}

int main() {
//	freopen("test.in", "r", stdin);
	long long n;
	char id[30];
	while(cin >> n) {
		memset(id, -1, sizeof(id));
//		cout << n << endl;
		to36(n, id);
//		for(int i=0;i<25; ++i) 
//			printf("%d ", id[i]);
//		cout << endl;
		
		
		int len = 0;
		for(int i=24; i>=0; --i)
			if(id[i] >= 0) {
				len = i;
				break;
			}
		for(int i=0; i<=len; ++i)
			if(id[i] >=0 && id[i] <=9) id[i] += '0';
			else id[i] = id[i] - 10 + 'A';

		int k = 1;
		for(int i=len; i>=0; --i, ++k) {
			cout << id[i];
			if(k%5==0 && k!=25)
				cout << "-";
		}
		for(int i=len+1; i<25; ++i, ++k) {
			if(i&1)
				cout << 'G';
			else
				cout << 'B';
			if(k%5==0 && k!=25)
				cout << "-";		
		}
		cout << endl;
	
	}
	return 0;
}
