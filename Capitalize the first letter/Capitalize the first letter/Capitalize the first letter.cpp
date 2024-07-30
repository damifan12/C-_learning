#include<iostream>
#include<cstring>
using namespace std;


int main() {
	char s[110];
	while (fgets(s, sizeof(s), stdin)) {
		int len = strlen(s);
		for (int i = 0; i < len; ++i) {
			if ( i==0 || s[i-1] == ' ') {
				if (s[i] != ' ') {
					if (s[i] >= 'a' && s[i] <= 'z') {
						s[i] = s[i] - 'a' + 'A';
					}
				}

			}
		}
		printf("%s\n", s);
	}
	return 0;

}