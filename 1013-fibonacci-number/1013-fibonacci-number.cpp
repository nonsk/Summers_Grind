class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;
        return fib(n-1) + fib(n-2);
    }
};
// auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });