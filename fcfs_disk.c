#include <stdio.h>
#include <stdlib.h>
int main() {
int request[] = {55, 58, 39, 18, 90, 160, 150, 38, 184};
int n = 9;
int head = 50;
int total = 0;
int i;
printf("FCFS Disk Scheduling\n");
printf("Seek Sequence:\n");
printf("%d", head);
for(i = 0; i < n; i++) {
total += abs(request[i] - head);
head = request[i];
printf(" -> %d", head);
}
printf("\n\nTotal Head Movement = %d cylinders\n", total);
return 0;
}