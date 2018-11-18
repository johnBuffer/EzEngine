#pragma once

template<class T>
class Vec2
{
public:
    Vec2() = default;
    Vec2(const Vec2&, const Vec2&);
    Vec2(const T& x_, const T& y_);

    void   move(const Vec2<T>& vec);
    double getNorm()  const;
    double getNorm2() const;

    T x, y;
};

using Vec2f = Vec2<double>;

template<class T>
Vec2<T> operator/(const Vec2<T>& v, double d)
{
	double inv = 1.0 / d;
	return { v.x * inv, v.y * inv };
}

template<class T>
Vec2<T> operator-(const Vec2<T>& v1, const Vec2<T>& v2)
{
	return { v1.x - v2.x, v1.y - v2.y };
}

template<class T>
Vec2<T> operator+(const Vec2<T>& v1, const Vec2<T>& v2)
{
	return { v1.x + v2.x, v1.y + v2.y };
}

template<class T>
Vec2<T> operator-(const Vec2<T>&);
template<class T>
Vec2<T> operator*(const Vec2<T>&, double d);

template<class T>
inline Vec2<T>::Vec2(const Vec2& v1, const Vec2& v2) :
	x(v1.x - v2.x),
	y(v1.y - v2.y)
{
}

template<class T>
inline Vec2<T>::Vec2(const T& x_, const T& y_) :
	x(x_),
	y(y_)
{}
