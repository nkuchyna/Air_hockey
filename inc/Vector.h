#ifndef _Vec2f_
#define _Vec2f_

class Vec2f {
	
	public :
	
	float x, y;
	Vec2f();
	Vec2f( float xInit, float yInit );
	Vec2f( const Vec2f& obj);
	Vec2f& operator=( const Vec2f& obj);
	
	void zero( Vec2f& v );
	void set( Vec2f& v );
	void set( float xs, float ys );
	Vec2f clone();

	void setAngle( float a );
	void setAngleDeg( float a );	
	float getAngle();
	float getAngleDeg();
	void rotateBy( float l );	
	
	void add( Vec2f& v );
	void subtract( Vec2f& v );
	void multiply( float s );
	void divide( float s );
	
	void normalize();
	void setLength( float l );
	float getLength();
	
	float dot( const Vec2f& v ) const;
	float cross( const Vec2f& v ) const;
	float distanceTo( Vec2f v );
	void lookAt( Vec2f& v );
	
	void print( bool includeEndline = true );

	Vec2f operator+ ( const Vec2f& v ) const;
	Vec2f operator- ( const Vec2f& v ) const;
	Vec2f operator* ( const float s ) const;	
	float operator* ( const Vec2f& v ) const; //dot product
	float operator^ ( const Vec2f& v ) const; //cross product	
	Vec2f operator/ ( const float s ) const;
	Vec2f operator/ ( const Vec2f& v ) const;
	bool operator== ( const Vec2f& v ) const;
	void operator+= ( const Vec2f& v );
	void operator-= ( const Vec2f& v );
	void operator*= ( const float s );	
	void operator/= ( const float s );
	float operator[] ( int i );
	
};

#endif