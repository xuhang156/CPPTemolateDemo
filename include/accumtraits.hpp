#pragma once
//Fixed trait
template<typename T>
class AccumTraits;
template<>
class AccumTraits<char>
{
    public:
    typedef int AccT;
    static AccT zero(){
        return 0;
    }
};
template<>
class AccumTraits<short>{
    public:
    typedef int AccT; 
    static AccT zero(){
        return 0;
    }
};
template<>
class AccumTraits<int>{
    public:
    typedef long AccT; 
    static AccT zero(){
        return 0;
    }
};
template<>
class AccumTraits<float>{
    public:
    typedef double AccT; 
    static AccT zero(){
        return 0;
    }
};