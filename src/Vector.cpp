#include "Vector.h"
#include <iostream>
#include <math.h>

Vec2f::Vec2f() { 
	x = 0;
	y = 0;
}

Vec2f::Vec2f( float xInit, float yInit ) { 
	x = xInit;
	y = yInit;
}

Vec2f::Vec2f( const Vec2f& obj) {
	*this = obj;
}

Vec2f& Vec2f::operator=( const Vec2f& obj) {
	if (&obj != this)
	{
		this->x = obj.x;
		this->y = obj.y;
	}
	return (*this);
}

void Vec2f::set( Vec2f& v ) {
	x = v.x;
	y = v.y;
}

void Vec2f::set( float xs, float ys ) {
	x = xs;
	y = ys;
}

Vec2f Vec2f::clone() {
	return Vec2f( x, y );
}

void Vec2f::zero( Vec2f& v ) {
	x = 0;
	y = 0;	
}

void Vec2f::add( Vec2f& v ) {
	x += v.x;
	y += v.y;
}

void Vec2f::subtract( Vec2f& v ) {
	x -= v.x;
	y -= v.y;
}

void Vec2f::multiply( float s ) {
	x *= s;
	y *= s;
}

void Vec2f::divide( float d ) {
	x /= d;
	y /= d;	
}

void Vec2f::normalize() {
	float length = sqrt(x*x+y*y);
	x = x / length;
	y = y / length;
}

float Vec2f::getLength() {	
	return sqrt(x*x+y*y);
}

void Vec2f::setLength( float l ) {
	float length = sqrt(x*x+y*y);
	x = (x / length) * l;
	y = (y / length) * l;
}

float Vec2f::getAngle() {
	return atan2( y, x );
}

float Vec2f::getAngleDeg() {
	return atan2(y,x) * 57.2957;
}

void Vec2f::setAngle( float a ) {
	float length = sqrt(x*x+y*y);
	x = cos(a)*length;
	y = sin(a)*length;
}

void Vec2f::setAngleDeg( float a ) {
	float length = sqrt(x*x+y*y);
	a *= 0.0174532925;
	x = cos(a)*length;
	y = sin(a)*length;
}

void Vec2f::rotateBy( float l ) {
	float angle = getAngle();
	float length = sqrt(x*x+y*y);
	x = cos(l+angle)*length;
	y = sin(l+angle)*length;
}

float Vec2f::dot( const Vec2f& v ) const {
	return x * v.x + y * v.y;
}

float Vec2f::cross( const Vec2f& v ) const {
	return (x * v.y) - (y * v.x);
}

float Vec2f::distanceTo( Vec2f v ) {
	Vec2f distanceVector = Vec2f(v.x - x, v.y - y );
	return distanceVector.getLength();
}	

void Vec2f::lookAt( Vec2f& v ) {
	Vec2f *vectorToTarget = new Vec2f( v.x - x, v.y - y  );
	setAngle( vectorToTarget->getAngle() );
}

//OPERATORS

Vec2f Vec2f::operator+ ( const Vec2f& v ) const {
	return Vec2f( x + v.x, y + v.y );	
}

Vec2f Vec2f::operator- ( const Vec2f& v ) const {
	return Vec2f( x - v.x, y - v.y );	
}

Vec2f Vec2f::operator* ( const float s ) const {
	return Vec2f( x * s, y * s );
}

//dot product
float Vec2f::operator* ( const Vec2f& v ) const {
	return (x * v.x + y * v.y);
}

//cross product	
float Vec2f::operator^ ( const Vec2f& v ) const {
	return (x * v.y) - (y * v.x);
}

Vec2f Vec2f::operator/ ( const float s ) const {
	return Vec2f( x / s, y / s );
}

Vec2f Vec2f::operator/ ( const Vec2f& v ) const {
	return Vec2f( x / v.x, y / v.y );
}

bool Vec2f::operator== ( const Vec2f& v ) const {
	return ( x == v.x && y == v.y );
}

void Vec2f::operator+= ( const Vec2f& v ) {
	x += v.x;
	y += v.y;	
}

void Vec2f::operator-= ( const Vec2f& v ) {
	x -= v.x;
	y -= v.y;	
}

void Vec2f::operator*= ( const float s ) {
	x *= s;
	y *= s;
}

void Vec2f::operator/= ( const float s ) {
	x /= s;
	y /= s;
}

float Vec2f::operator[] ( int i ) {
	if ( i == 0 ) return x;
		else return y;
}

void Vec2f::print( bool includeEndline ) {
	if( includeEndline ) printf( "%s%f%s%f%s", "[" , x , ",", y , "]\n" );
		else printf( "%s%f%s%f%s", "[" , x , ",", y , "]" );
}