#include "cave.h"

bool keep[5005];
int s[5005],d[5005]; 
void flip(int l,int r) {
	for (int j=l;j<=r;j++) {
		if (!keep[j]) s[j]=1-s[j];
	}
}
void exploreCave(int N) {
	for (int i=0;i<N;i++) s[i]=0;
	int x;
	int l,r,mid;
	for (int i=0;i<N;i++) {
		x=tryCombination(s);
		if (x!=i) flip(0,N-1);
		l=0,r=N-1;
		while (l<=r) {
			mid=(l+r)>>1;
			flip(l,mid);
			x=tryCombination(s);
			if (l==r) {
				if (x==i) s[l]=1-s[l],keep[l]=1;
				else keep[l]=1;
				d[l]=i;
				break;
			}
			if (x!=i) {
				flip(l,mid);
				r=mid;
				if (l==r) {
					s[l]=1-s[l];
					keep[l]=1;
					d[l]=i;
					break;
				}
			} else {
				l=mid+1;
				if (l==r) {
					s[l]=1-s[l];
					keep[l]=1;
					d[l]=i;
					break;
				}
			}
		}
	}
	answer(s,d);
}
