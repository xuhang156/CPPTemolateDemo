#pragma once
// 累计求和的策略
class SumPolicy {
public:
    template<typename T1,typename T2>
    static void accumulate(T1& total, const T2& value) {
        total += value;
    }
};

// 累计乘积的策略
class MultPolicy {
public:
    template<typename T1,typename T2>
    static void accumulate(T1& total, const T2& value) {
        total *= value;
    }
};

