#include <inttypes.h>

class Fibonacci
{
    protected:
        uint32_t n;

        virtual uint64_t Calc(uint32_t n);
    public:
        Fibonacci(uint32_t n);        
        uint64_t Calc();
};

class FibonacciMemoized : public Fibonacci
{
    private:
        uint64_t* memo;

        uint64_t Calc(uint32_t n) override;
        void CreateMemo();
    public:
        FibonacciMemoized(uint32_t n);
        ~FibonacciMemoized();
        using Fibonacci::Calc;
};