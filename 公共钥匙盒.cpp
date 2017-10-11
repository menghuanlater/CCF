#include <iostream>
#define MAXEVENT 1000
using namespace std;

struct Event {
	bool isPick;
	int keys;
	int time;
};

void qSort(Event *, int low, int high);
int getPivot(Event *, int low, int high);
void insertEmptyPos(int *, int, int);

int keysNum, EventsNum;

int main(void) {

	cin >> keysNum >> EventsNum;

	Event eventSets[2 * MAXEVENT];
	int * Pos_to_Key = new int[keysNum + 1];
	int * Key_to_Pos = new int[keysNum + 1];
	int * emptyPos = new int[keysNum];
	for (int i = 0; i <= keysNum; i++) {
		Pos_to_Key[i] = Key_to_Pos[i] = i;
		if (i != keysNum)
			emptyPos[i] = 0;
	}

	int v1, v2, v3;
	for (int i = 0; i<EventsNum; i++) {
		cin >> v1 >> v2 >> v3;
		eventSets[2 * i].keys = v1;
		eventSets[2 * i].isPick = true;
		eventSets[2 * i].time = v2;

		eventSets[2 * i + 1].keys = v1;
		eventSets[2 * i + 1].isPick = false;
		eventSets[2 * i + 1].time = v2 + v3;
	}

	qSort(eventSets, 0, 2 * EventsNum - 1);
	int front = 0;

	for (int i = 0; i<2 * EventsNum; i++) {
		Event analysis = eventSets[i];
		if (analysis.isPick) {
			int position = Key_to_Pos[analysis.keys]; // get target key's position
			insertEmptyPos(emptyPos, position, front);
		}
		else {
			int position = emptyPos[front];
			emptyPos[front] = 0;
			front = (front + 1) % keysNum;
			Pos_to_Key[position] = analysis.keys;
			Key_to_Pos[analysis.keys] = position;
		}
	}

	for (int i = 1; i <= keysNum; i++) {
		if (i != keysNum) {
			cout << Pos_to_Key[i] << " ";
		}
		else {
			cout << Pos_to_Key[i] << endl;;
		}
	}

	delete[] Pos_to_Key;
	delete[] Key_to_Pos;
	delete[] emptyPos;
	return 0;
}

void insertEmptyPos(int *emptyPos, int targetPos, int start) {
	int i;
	for (i = start; emptyPos[i%keysNum] != 0; i++) {
		if (targetPos<emptyPos[i%keysNum]) {
			int temp = targetPos; int j; int temp2;
			for (j = i; emptyPos[j%keysNum] != 0; j++) {
				temp2 = emptyPos[j%keysNum];
				emptyPos[j%keysNum] = temp;
				temp = temp2;
			}
			emptyPos[j%keysNum] = temp;
			return;
		}
	}
	emptyPos[i%keysNum] = targetPos;
}

void qSort(Event* eventSets, int low, int high) {
	int pivot;
	if (low < high) {
		pivot = getPivot(eventSets, low, high);
		qSort(eventSets, low, pivot - 1);
		qSort(eventSets, pivot + 1, high);
	}
}

int getPivot(Event* eventSets, int low, int high) {
	Event pivotKey = eventSets[low];
	while (low < high) {
		while (low<high && ((eventSets[high].time > pivotKey.time) ||
			(eventSets[high].time == pivotKey.time && eventSets[high].isPick && !pivotKey.isPick) ||
			(eventSets[high].time == pivotKey.time && !eventSets[high].isPick && !pivotKey.isPick &&
				eventSets[high].keys > pivotKey.keys)))
			high--;
		eventSets[low] = eventSets[high];

		while (low<high && ((eventSets[low].time < pivotKey.time) ||
			(eventSets[low].time == pivotKey.time && !eventSets[low].isPick && pivotKey.isPick) ||
			(eventSets[low].time == pivotKey.time && !eventSets[low].isPick && !pivotKey.isPick &&
				eventSets[low].keys < pivotKey.keys)))
			low++;
		eventSets[high] = eventSets[low];
	}
	eventSets[low] = pivotKey;
	return low;
}