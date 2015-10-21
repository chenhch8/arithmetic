#ifndef MAX_H
#define MAX_H

int max(int a, int b, int c);
// 分治算法（递归思想）
int MaxSubSum(const int *Sum, int left, int right) {
	int maxLeft, maxRight, maxBorderLeft = 0, maxBorderRight = 0;
	int center = (left + right) / 2;
	if (left == right)
		return (left > 0 ? left : 0);
	maxLeft = MaxSubSum(Sum, left, center);
	maxRight = MaxSubSum(Sum, center + 1, right);
    int Border = 0;
    for (int i = center; i >= left; i--) {
        Border += Sum[i];
        if (Border > maxBorderLeft)
            maxBorderLeft = Border;
    }
    Border = 0;
    for (int i = center + 1; i <= right; i++) {
        Border += Sum[i];
        if (Border > maxBorderRight)
            maxBorderRight = Border;
    }
    return max(maxLeft, maxRight, maxBorderLeft + maxBorderRight);
}

int max(int a, int b, int c) {
    if (a < b) a = b;
    if (a < c) a = c;
    return a;
}


// 联机算法（智能算法的典型）
int MaxSubSum2(const int *Sum, int size) {
    int maxSum = 0, thisSum = 0;
    for (int i = 0; i < size; i++) {
        thisSum += Sum[i];
        if (thisSum > maxSum) maxSum = thisSum;
        else if (thisSum < 0) thisSum = 0;
    }
    return maxSum;
}

#endif
