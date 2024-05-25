#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
using namespace std;
#define NUM 100500

struct Time {
	int start_time;
	int finish_time;
};

int n;
int cnt = 0;

bool compare(const Time& left, const Time& right) {
	if (left.finish_time < right.finish_time) 
		return true;
	else if (left.finish_time == right.finish_time) {
		if (left.start_time < right.start_time)
			return true;
		else return false;
	}
	else return false;
}

int main() {
	scanf("%d", &n);

	//Time* time = new Time[n];
	Time time[NUM];

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &time[i].start_time, &time[i].finish_time);
	}

	sort(time, time + n, compare);

	int present = 0;

	for (int i = 0; i < n; i++) {
		if (time[i].finish_time < present) continue;

		else if (time[i].finish_time == present) {
			if (time[i].start_time == present) cnt++;
		}
		else {
			if (time[i].start_time >= present) {
				cnt++;
				present = time[i].finish_time;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}