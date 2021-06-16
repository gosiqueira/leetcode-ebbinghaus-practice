char findKthBit (int n, int k) {
    int mid = 1 << (n-1);

    if (n == 1) {
        return '0';
    }

    if (k < mid) {
        return findKthBit(n - 1, k);
    } else if (k > mid) {
        return findKthBit(n - 1, 2 * mid - k) == '0' ? '1' : '0';
    }

    return '1';
}