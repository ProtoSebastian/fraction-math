/*
 *  Copyright (c) 2023, Sebastian (https://github.com/ProtoSebastian)
 *
 */

#include "defs.hpp"
#include <iostream>
#include <cstdint>
#include <cinttypes>
#include <cmath>
#include <cstring>
using namespace std;

int main(int argc, char** argv) {
	char *strbuf0=nullptr, *strbuf1=nullptr; // my employment chances dropping to zero:
	
	// print license
	printf("  Copyright (c) 2023, Sebastian (https://github.com/ProtoSebastian)\n");

	printf("argc: %d\n", argc);
	frac a(1,3), b(1,5), na(-1,3), nb(-1,5), c, d(60, 120);
	printf("a=%s (+%f)\nb=%s (+%f)\n", a.make_cstring(&strbuf0), a.to_double(), b.make_cstring(&strbuf1), b.to_double());
	c=a*b;
	printf("a*b=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=a/b;
	printf("a/b=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=b/a;
	printf("b/a=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	printf("pow(a, b)=%+f\n", pow(a, b));
	printf("pow(b, a)=%+f\n", pow(b, a));
	c=pow(a, 2);
	printf("pow(a, 2)=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=pow(b, 2);
	printf("pow(b, 2)=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=pow(a, 3);
	printf("pow(a, 3)=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=pow(b, 3);
	printf("pow(b, 3)=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=a+b;
	printf("a+b=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=a-b;
	printf("a-b=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=b-a;
	printf("b-a=%s (%+f)\n\n\n", c.make_cstring(&strbuf0), c.to_double());
	printf("na=%s (+%f)\nnb=%s (+%f)\n", na.make_cstring(&strbuf0), na.to_double(), nb.make_cstring(&strbuf1), nb.to_double());
	c=na*nb;
	printf("na*nb=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=na/nb;
	printf("na/nb=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=nb/na;
	printf("nb/na=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	printf("pow(na, nb)=%+f\n", pow(na, nb));
	printf("pow(nb, na)=%+f\n", pow(nb, na));
	c=pow(na, 2);
	printf("pow(na, 2)=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=pow(nb, 2);
	printf("pow(nb, 2)=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=pow(na, 3);
	printf("pow(na, 3)=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=pow(nb, 3);
	printf("pow(nb, 3)=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=na+nb;
	printf("na+nb=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=na-nb;
	printf("na-nb=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	c=nb-na;
	printf("nb-na=%s (%+f)\n", c.make_cstring(&strbuf0), c.to_double());
	printf("d=%s (%+f)\n", d.make_cstring(&strbuf0), d.to_double());
	d=d.simplify();
	printf("d (simplified)=%s (%+f)\n", d.make_cstring(&strbuf0), d.to_double());
	printf("GCD(+60, +120): +%" PRIu64 "\n", gcd(60, 120));
	/*uint64_t *primes1=prime_factors(60), *primes2=prime_factors(120), *commprimes;
	if(primes1[0]>1ULL) {
		printf("prime factors of 60 = {");
		for(uint64_t i=1ULL;i<primes1[0];i++) {
			printf("%" PRIu64, primes1[i]);
			if(i!=primes1[0]-1)
				printf(", ");
	if(primes2[0]>1ULL) {
		printf("}\n");
		printf("prime factors of 120 = {");
		for(uint64_t i=1ULL;i<primes2[0];i++) {
			printf("%" PRIu64, primes2[i]);
			if(i!=primes2[0]-1ULL)
				printf(", ");
		}
		printf("}\n");
	}
	if((primes1[0]>1ULL)&&(primes2[0]>1ULL)) {
		commprimes=common_elements(primes1, primes2);
		if(commprimes[0]>1ULL) {
			printf("common prime factors of 60 & 120 = {");
			for(uint64_t i=1ULL;i<commprimes[0];i++) {
				printf("%" PRIu64, commprimes[i]);
				if(i!=commprimes[0]-1ULL)
					printf(", ");
			}
			printf("}\n");
		}
	}
	free(primes1);
	free(primes2);
	free(commprimes);*/
	free(strbuf0);
	free(strbuf1);

	return 0;
}
