/*
 *  Copyright (c) 2023, Sebastian (https://github.com/ProtoSebastian)
 *
 */

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <stdexcept>
#include <cfloat>
#include <string>
#include <cstring>
/*string print_elems(uint64_t* a) {
	string tmp;
	tmp+='{';
	for(uint64_t i=1;i<a[0];i++) {
		tmp+=to_string(a[i]);
		if(i<a[0]-1)
			tmp+=", ";
	}
	tmp+='}';
	return tmp;
}
int compare_int64(const void* pkey, const void* pelem) {
	if     (*(uint64_t*)pkey < *(uint64_t*)pelem) return -1;
	else if(*(uint64_t*)pkey > *(uint64_t*)pelem) return  1;
	else                                          return  0;
}
int rcompare_int8(const void* pkey, const void* pelem) {
	if     (*(uint8_t*)pkey > *(uint8_t*)pelem) return  1;
	else if(*(uint8_t*)pkey < *(uint8_t*)pelem) return -1;
	else                                          return  0;
}
int compare_int8(const void* pkey, const void* pelem) {
	if     (*(uint8_t*)pkey < *(uint8_t*)pelem) return  1;
	else if(*(uint8_t*)pkey > *(uint8_t*)pelem) return -1;
	else                                          return  0;
}
uint64_t* prime_factors(uint64_t n) {
	uint64_t *tmp=(uint64_t*)malloc(8);
	tmp[0]=1;
	if(n<=1)
		return tmp;
	while((n&1)==0ULL) {
		tmp[0]++;
		tmp=(uint64_t*)realloc(tmp, tmp[0]<<3);
		tmp[tmp[0]-1]=2;
		n>>=1;
	}
	for(uint64_t i=3;i<=(uint64_t)sqrt(n);i+=2) {
		while((n%i)==0) {
			tmp[0]++;
			tmp=(uint64_t*)realloc(tmp, tmp[0]<<3);
			tmp[tmp[0]-1]=i;
			n/=i;
		}
	}
	if(n>1ULL) {
		tmp[0]++;
		tmp=(uint64_t*)realloc(tmp, tmp[0]<<3);
		tmp[tmp[0]-1]=n;
	}
	return tmp;
}
uint64_t pop8(uint64_t* a, uint64_t i) {
	uint64_t elem=a[i];
	for(uint64_t n=i;n<a[0]-1;n++)
		a[n]=a[n+1];
	a[0]--;
	a=(uint64_t*)realloc(a, a[0]<<3);
	return elem;
}
uint64_t* common_elements(uint64_t* a, uint64_t* b) {
	uint64_t *tmp=(uint64_t*)malloc(8), *el;
	tmp[0]=1;
	if((a[0]<1)||(b[0]<1))
		return tmp;
	for(uint64_t i=1;i<a[0];i++) {
		el=(uint64_t*)bsearch(&a[i], &b[1], b[0]-1, 8, compare_int64);
		if(el!=NULL) {
			tmp[0]++;
			tmp=(uint64_t*)realloc(tmp, tmp[0]<<3);
			tmp[tmp[0]-1]=a[i];
			pop8(b, ((uint64_t)el-(uint64_t)b)>>3);
		}
	}

	return tmp;
}*/
uint64_t gcd(uint64_t a, uint64_t b) {
	uint64_t tmp0;
	while(b!=0) {
		tmp0=b;
		b=a%b;
		a=tmp0;
	}
	return a;
}
struct frac {
	uint64_t num, den;
	bool sgn;
	frac() { //uninitialized
		this->num=0;
		this->den=1;
		this->sgn=0;
	}
	frac(int64_t n, int64_t d) {
		sgn=(n<0)^(d<0);
		this->num=llabs(n);
		this->den=llabs(d);
	}
	frac(uint64_t n, uint64_t d, bool sgn) {
		this->num=n;
		this->den=d;
		this->sgn=sgn;
	}
	float to_float() {
		if(this->num==0 || this->den==0) return 0.0f;
		float tmp=(float)this->num/this->den;
		if(this->sgn) return -tmp;
		else return tmp;
	}
	double to_double() {
		if(this->num==0 || this->den==0) return 0.0;
		double tmp=(double)this->num/this->den;
		if(this->sgn) return -tmp;
		else return tmp;
	}
	frac copy() {
		frac tmp(this->num, this->den, this->sgn);

		return tmp;
	}
	/*frac _simplify() { //old simplify
		frac ftmp=this->copy();
		uint64_t *nump=prime_factors(ftmp.num), *denp=prime_factors(ftmp.den);
		uint64_t *commp=common_elements(nump, denp);
		free(nump);
		free(denp);
		for(uint64_t i=1;i<commp[0];i++) {
			ftmp.num/=commp[i];
			ftmp.den/=commp[i];
		}
		free(commp);

		return ftmp;
	}
	void _simplify_self() { //old simplify_self
		uint64_t *nump=prime_factors(this->num), *denp=prime_factors(this->den);
		uint64_t *commp=common_elements(nump, denp);
		free(nump);
		free(denp);
		for(uint64_t i=1;i<commp[0];i++) {
			this->num/=commp[i];
			this->den/=commp[i];
		}
		free(commp);
	}*/
	frac simplify() {
		frac ftmp=this->copy();
		uint64_t gcd0=gcd(this->num, this->den);
		ftmp.num=this->num/gcd0;
		ftmp.den=this->den/gcd0;
		return ftmp;
	}
	frac simplify_self() {
		uint64_t gcd0=gcd(this->num, this->den);
		this->num/=gcd0;
		this->den/=gcd0;
		return *this;
	}
	//unsigned integer definitions
	frac operator*(const uint64_t &v);
	frac operator*=(const uint64_t &v);
	frac operator/(const uint64_t &v);
	frac operator/=(const uint64_t &v);
	frac operator+(const uint64_t &v);
	frac operator+=(const uint64_t &v);
	frac operator-(const uint64_t &v);
	frac operator-=(const uint64_t &v);
	frac operator%(const uint64_t &v);
	frac operator%=(const uint64_t &v);
	//fraction definitions
	frac operator*(const frac &f);
	frac operator*=(const frac &f);
	frac operator/(const frac &f);
	frac operator/=(const frac &f);
	frac operator+(const frac &f);
	frac operator+=(const frac &f);
	frac operator-(const frac &f);
	frac operator-=(const frac &f);
	frac operator%(const frac &f);
	frac operator%=(const frac &f);
	std::string make_string() {
		std::string tmp;
		if(this->sgn) {
			tmp="-";
		} else {
			tmp="+";
		}
		tmp+=std::to_string(this->num);
		if(this->den>1) tmp+=
		#ifdef UNICODE_FRACTION_SEPARATOR
		"⁄"
		#else
		"/"
		#endif
		+std::to_string(this->den); //⁄

		return tmp;
	}
	char* make_cstring(char** dest) { // for printf, writes location to passed C-string so it can be tracked and freed while still being inline.
					  // absolutely disgusting.
		std::string string   = this->make_string();
		const char* c_string = string.c_str();
		size_t      size     = strlen(c_string)+1;
		*dest                = (char*)realloc(*dest, size); // have to copy so it doesn't get deallocated before use
		memcpy(*dest, c_string, size); // unsafe unu
		return *dest;
	}
	std::string make_LaTeX_string() {
		if(this->den>1) {
			return (std::string)(this->sgn?"-":"+")+"\\frac{"+std::to_string(this->num)+"}{"+std::to_string(this->den)+"}";
		} else {
			return (std::string)(this->sgn?"-":"+")+std::to_string(this->num);
		}
	}
	char* make_LaTeX_cstring(char** dest) { // like its cousin, frac::make_cstring()
		std::string string   = this->make_LaTeX_string();
		const char* c_string = string.c_str();
		size_t      size     = strlen(c_string)+1;
		*dest                = (char*)realloc(*dest, size); // have to copy so it doesn't get deallocated before use
		memcpy(*dest, c_string, size); // unsafe unu
		return *dest;
	}
};
//unsigned integer definitions
frac frac::operator*(const uint64_t &v) {
	frac tmp(this->num*v, this->den, this->sgn);
	return tmp.simplify_self();
}
frac frac::operator*=(const uint64_t &v) {
	this->num*=v;
	return this->simplify_self();
}
frac frac::operator/(const uint64_t &v) {
	if(v==0) throw std::logic_error("division by zero!");
	frac tmp(this->num*v, this->den, this->sgn);
	return tmp.simplify_self();
}
frac frac::operator/=(const uint64_t &v) {
	if(v==0) throw std::logic_error("division by zero!");
	this->num*=v;
	return this->simplify_self();
}
frac frac::operator+(const uint64_t &v) {
	frac tmp(this->num+(v*this->den), this->den, this->sgn);
	return tmp.simplify_self();
}
frac frac::operator+=(const uint64_t &v) {
	this->num+=v*this->den;
	return this->simplify_self();
}
frac frac::operator-(const uint64_t &v) {
	uint64_t buf0=v*this->den;
	frac tmp;
	if(this->num>=buf0) {
		tmp.num=this->num-buf0;
		tmp.sgn=this->sgn;
	} else {
		tmp.num=buf0-this->num;
		tmp.sgn=this->sgn^1;
	}
	tmp.den=this->den;
	return tmp.simplify_self();
}
frac frac::operator-=(const uint64_t &v) {
	uint64_t buf0=v*this->den;
	if(this->num>=buf0) {
		this->num-=buf0;
	} else {
		this->num=buf0-this->num;
		this->sgn^=1;
	}
	return this->simplify_self();
}
frac frac::operator%(const uint64_t &v) {
	if(!v) {
		return *this;
	}
	frac tmp;
	tmp.den=this->den;
	tmp.num=this->num%(tmp.den*v);
	if(this->sgn) tmp.num=(tmp.den*v)-tmp.num;

	return tmp.simplify_self();
}
frac frac::operator%=(const uint64_t &v) {
	if(!v) {
		return *this;
	}
	this->num%=this->den*v;
	if(this->sgn) this->num=(this->den*v)-this->num;
	this->sgn=0;

	return this->simplify_self();
}
//fraction definitions
frac frac::operator*(const frac &f) {
	if(f.den==0) throw std::logic_error("division by zero!");
	frac tmp(this->num*f.num, this->den*f.den, this->sgn^f.sgn);
	return tmp.simplify_self();
}
frac frac::operator*=(const frac &f) {
	if(f.den==0) throw std::logic_error("division by zero!");
	this->num*=f.num;
	this->den*=f.den;
	this->sgn^=f.sgn;
	return this->simplify_self();
}
frac frac::operator/(const frac &f) {
	if(f.num==0) throw std::logic_error("division by zero!");
	frac tmp(this->num*f.den, this->den*f.num, this->sgn^f.sgn);
	return tmp.simplify_self();
}
frac frac::operator/=(const frac &f) {
	if(f.num==0) throw std::logic_error("division by zero!");
	this->num*=f.den;
	this->den*=f.num;
	this->sgn^=f.sgn;
	return this->simplify_self();
}
frac frac::operator+(const frac &f) {
	uint64_t buf0=this->num*f.den, buf1=f.num*this->den;
	frac tmp;
	tmp.sgn=this->sgn;
	if(this->sgn^f.sgn) {
		buf0-=buf1;
	} else {
		buf0+=buf1;
	}
	if(buf0&0x8000000000000000) {
		tmp.num=(~buf0)+1;
		tmp.sgn=this->sgn^1;
	} else {
		tmp.num=buf0;
		tmp.sgn=this->sgn;
	}
	tmp.den=this->den*f.den;

	return tmp.simplify_self();
}
frac frac::operator+=(const frac &f) {
	this->num*=f.den;
	if(this->sgn^f.sgn) {
		this->num-=f.num*this->den;
	} else {
		this->num+=f.num*this->den;
	}
	this->den*=f.den;
	if(this->num&0x8000000000000000) {
		this->num =(~this->num)+1;
		this->sgn^=1;
	}
	return this->simplify_self();
}
frac frac::operator-(const frac &f) {
	uint64_t buf0=this->num*f.den, buf1=f.num*this->den;
	frac tmp;
	if(this->sgn^f.sgn) {
		buf0+=buf1;
	} else {
		buf0-=buf1;
	}
	if(buf0&0x8000000000000000) {
		tmp.num=(~buf0)+1;
		tmp.sgn=this->sgn^1;
	} else {
		tmp.num=buf0;
		tmp.sgn=this->sgn;
	}
	tmp.den=this->den*f.den;

	return tmp.simplify_self();
}
frac frac::operator-=(const frac &f) {
	this->num*=f.den;
	if(this->sgn^f.sgn) {
		this->num+=f.num*this->den;
	} else {
		this->num-=f.num*this->den;
	}
	this->den*=f.den;
	if(this->num&0x8000000000000000) {
		this->num =(~this->num)+1;
		this->sgn^=1;
	}
	return this->simplify_self();
}
frac frac::operator%(const frac &f) {
	if(!f.num) {
		return *this;
	}
	frac tmp;
	tmp.num=(this->num*f.den)-(((uint64_t)(this->num*f.den)/(uint64_t)(this->den*f.num))*this->den*f.num);
	if(this->sgn^f.sgn) tmp.num=(this->den*f.num)-tmp.num;
	tmp.sgn=f.sgn;
	tmp.den=this->den*f.den;

	return tmp.simplify_self();
}
frac frac::operator%=(const frac &f) {
	if(!f.num) {
		return *this;
	}
	this->num=(this->num*f.den)-(((uint64_t)(this->num*f.den)/(uint64_t)(this->den*f.num))*this->den*f.num);
	if(this->sgn^f.sgn) this->num=(this->den*f.num)-this->num;
	this->sgn=f.sgn;
	this->den*=f.den;

	return this->simplify_self();
}

frac pow(frac a, uint64_t b) {
	a.num=pow(a.num, b);
	a.den=pow(a.den, b);
	if(!(b&1)) a.sgn=0;
	return a.simplify_self();
}
double pow(frac a, frac b) {
	return pow(pow(a.num, 1.0/b.den), b.num)/pow(pow(a.den, 1.0/b.den), b.num);
}
frac to_frac_seximal(double a) { //<3 seximal
	int16_t exp;
	for(exp=0;fmodf(a, 1)>FLT_EPSILON;exp++,a*=6);
	return {(int64_t)a, (int64_t)pow(6, exp)};
}
frac to_frac_bitmanip(double a) { //</3 float manip
	uint64_t fractional=0;
	int16_t exp;
	memcpy((char*)&fractional+1, &a, 7);
	fractional<<=  3;
	fractional &=0x7FFFFFFFFFFFF800;
	fractional |=0x8000000000000000;
	memcpy(&exp, (char*)&a+6, 2);
	exp=((exp&0x7FF0)>>4)-1086;
	for(;(!(fractional&1))&&(exp<0);fractional>>=1,exp++);
	if((*(uint64_t*)&a)>>63)
		return {(int64_t)(-fractional), 1LL<<(-exp)};
	else
		return {(int64_t)fractional, 1LL<<(-exp)};
}
frac to_frac_binary(double a) { //vanilla binary
	int16_t exp;
	for(exp=0;fmodf(a, 1)>FLT_EPSILON;exp++,a*=2);
	return {(int64_t)a, (int64_t)pow(2, exp)};
}
frac to_frac_base(double a, uint64_t base) {
	int16_t exp;
	for(exp=0;fmodf(a, 1)>FLT_EPSILON;exp++,a*=base);
	return {(int64_t)a, (int64_t)pow(base, exp)};
}
