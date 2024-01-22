#include <iostream>

template<typename T>
constexpr bool is_float_or_double_v = 
    std::is_same<T, double>::value || std::is_same<T, float>::value || std::is_same<T, long double>::value;

template<typename T>
class Complex {
    static_assert(is_float_or_double_v<T>, "Не поддерживается этот тип");
    T real, imag;
public:
    Complex() : real(0), imag(0) {}
    Complex(T x) : real(x), imag(0) {}
    Complex(T x, T y) : real(x), imag(y) {}
    Complex(const Complex& other) : real(other.real), imag(other.imag) {}
    void setReal(T real)
    {
        this->real = real;
    };
    void setImag (T imag)
    {
        this->imag = imag;
    }
    T getReal () { return real; }
    T getImag () { return imag; }
    Complex<T> conj() { return Complex<T>(real, -imag); }       // Сопряжённое
    Complex<T> operator + (const Complex& other) {              // Перегрузка оператора сложения "complexNum1 + complexNum2"
        return Complex<T>(real + other.real, imag + other.imag);
    }
    Complex<T> operator += (const Complex& other) {             // Перегрузка += "complexNum1 += complexNum2"
        real += other.real;
        imag += other.imag;
        return *this;
    }
    Complex<T> operator += (const T& other) {                   // Перегрузка += "complexNum1 += num"
        real += other;
        return *this;
    }
    Complex<T> operator - () {                                  // Перегрузка -complexNum
        return *this * -1;
    }
    Complex<T> operator + (const T& other) {                    // Перегрузка оператора сложения "complexNum1 + num"       
        return Complex<T>(real + other, imag);
    }
    Complex<T> operator * (const T& other) {                    // Перегрузка оператора умножения "complexNum1 * num"
        return Complex<T>(real * other, imag * other);
    }
    Complex<T> operator * (const Complex& other) {              // Перегрузка оператора умножения "complexNum1 * complexNum2"
        return Complex<T>(real*other.real-imag*other.imag, imag*other.real + real*other.imag);
    }
    Complex<T> operator *= (const Complex& other) {             // Перегрузка *= "complexNum1 *= complexNum2"
        T real_bf = real;
        real = real*other.real-imag*other.imag;
        imag = imag*other.real+real_bf*other.imag;
        return *this;
    }
    Complex<T> operator *= (const T& other) {                   // Перегрузка *= "complexNum1 *= num"
        real *= other;
        imag *= other;
        return *this;
    }
    Complex<T> operator - (Complex& other) {                    // Перегрузка оператора вычитания "complexNum1 - complexNum2"
        return *this + (-other);
    }
    Complex<T> operator - (const T& other) {                    // Перегрузка оператора вычитания "complexNum1 - num"
        return Complex<T>(real - other, imag);
    }
    Complex<T> operator -= (const T& other) {                   // Перегрузка -= "complexNum1 -= num"
        real -= other;
        return *this;
    }
    Complex<T> operator -= (const Complex& other) {             // Перегрузка -= "complexNum1 -= complexNum2"
        real -= other.real;
        imag -= other.imag;
        return *this;
    }
    Complex<T> operator / (const T& other) {                    // Перегрузка оператора / "complexNum1 / num"
        return Complex<T>(real/other, imag/other);
    }
    Complex<T> operator /= (const T& other) {                    // Перегрузка оператора /= "complexNum1 /= num"
        real /= other;
        imag /= other;
        return *this;
    }
    Complex<T> operator / (const Complex& other) {               // Перегрузка оператора / "complexNum1 / complexNum2"
        T real_bf = (real*other.real+imag*other.imag)/(other.real*other.real+other.imag*other.imag);
        T imag_bf = (imag*other.real-real*other.imag)/(other.real*other.real+other.imag*other.imag);
        return Complex<T>(real_bf, imag_bf);
    }
    Complex<T> operator /= (const Complex& other) {                    // Перегрузка оператора /= "complexNum1 /= complexNum2"
        T real_bf = (real*other.real+imag*other.imag)/(other.real*other.real+other.imag*other.imag);
        this->imag = (imag*other.real-real*other.imag)/(other.real*other.real+other.imag*other.imag);
        this->real = real_bf;
        return *this;
    }
    Complex<T>& operator = (const Complex& other) {
        this->real = other.real;
        this->imag = other.imag;                                // теперь можно прописовать конструкции вида "comlex_number1 = complex_number2 = complex_number3"
        return *this;
    }
    T abs() { return sqrt(real*real + imag*imag); }             // Вычисляет модуль комплексного числа.
    T arg()                                                     // Извлекает аргумент из комплексного числа.
    {
        double pi = 3.14159265359;
        if(real > 0) return atan(imag/real);
        else if(real < 0){
            if (imag >= 0) return pi + atan(imag/real);
            else if (imag < 0) return -pi + atan(imag/real);
        }
        else if (real == 0) {
            if (imag > 0) return pi/2;
            else if (imag < 0) return -pi/2;
        
        }
        return -1000;
    }
    Complex<T> pow (const double& n)                            // Вычисляет комплексное число, получаемое в результате возведения основания (комплексного числа) в степень числа
    {
        double pi = 3.14159265359;
        T r = std::pow(this->abs(), n);
        T phi = n*this->arg();
        std::cout << r << " " << phi << std::endl;
        T real_bf = r*cos(phi);
        T imag_bf = r*sin(phi);
        if (std::abs(real_bf) < 1e-10) real_bf = 0;
        if (std::abs(imag_bf) < 1e-10) real_bf = 0;
        return Complex<T>(real_bf, imag_bf);
    }
    bool operator == (const Complex& other)                     // Проверяет на равенство два комплексных числа
    {
        bool res = (this->real == other.real);
        if (!res) return false;

        return res && (this->imag == other.imag);
    }
    bool operator==(const T& other)
    {
        bool res = (real == other);
        return res;
    }
    bool operator != (const Complex& other){
        return !(*this==other);
    }
    bool operator != (const T& other){
        return !(*this==other);
    }
};

template<typename T>
std::ostream& operator << (std::ostream& os, Complex<T>& complexNum)
{
    os << "(" << complexNum.getReal() << "," << complexNum.getImag() << ")";
    return os;
}

template <typename T>
bool operator==(const T& left, Complex<T>& right)               // Перегрузка оператора сравнения на равенства с действительным числом "num == complexNum"
{
    bool res = (left == right.getReal());
    return res;
}

template <typename T>
bool operator==(const int& left, Complex<T>& right)
{
    bool res = (left == right.getReal());
    return res;
}

template<typename T>                                    // Перегрузка оператора сравнения на неравенства с действительным числом "num != complexNum"
bool operator != (const T& left, Complex<T>& right)
{
    return !(left==right);
}

template<typename T>
bool operator != (const int& left, Complex<T>& right)
{
    return !(left==right);
}

template <typename T>                                                   // Прибавление действительного числа слева
Complex<T> operator+(const int& left, Complex<T>& right)
{
    return Complex<T>(right.getReal()+left, right.getImag());
}

template <typename T>
Complex<T> operator+(const T& left, Complex<T>& right)                  
{
    return Complex<T>(right.getReal()+left, right.getImag());
}

template <typename T>
Complex<T> operator * (const T& left, Complex<T>& right)                // Перегрузка оператора умножения на число слева "num * complexNum"
{
    return Complex<T>(right.getReal() * left, right.getImag() * left);
}

template <typename T>
Complex<T> operator * (const int& left, Complex<T>& right)            
{
    return Complex<T>(right.getReal() * left, right.getImag() * left);
}

template <typename T>
Complex<T> operator - (const T& left, Complex<T>& right)                // Перегрузка вычитания из действительного числа "num - complexNum"
{
    return Complex<T>(left - right.getReal(), -right.getImag());
}

template <typename T>
Complex<T> operator - (const int& left, Complex<T>& right)            
{
    return Complex<T>(left - right.getReal(), -right.getImag());
}

template <typename T>
Complex<T> operator / (const T& left, Complex<T>& right) {              // Перегрузка оператора / "num / complexNum"
    Complex<T> bf = left*right.conj();
    bf /= (right.getReal()*right.getReal()+right.getImag()*right.getImag());
    return bf;
}

template <typename T>
Complex<T> operator / (const int& left, Complex<T>& right) {        
    Complex<T> bf = left*right.conj();
    bf /= (right.getReal()*right.getReal()+right.getImag()*right.getImag());
    return bf;
}