/*
 *  Copyright (c) 2023, Sebastian (https://github.com/ProtoSebastian)
 *
 * bases 6, 60, & 360 were very good.
 *
 */

#include "defs.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cinttypes>

/*int compare_int16(const void* pkey, const void* pelem) {
	if     (*(uint16_t*)pkey < *(uint16_t*)pelem) return  1;
	else if(*(uint16_t*)pkey > *(uint16_t*)pelem) return -1;
	else                                          return  0;
}
int rcompare_int48(const void* pkey, const void* pelem) {
	if     ((*(uint64_t*)pkey&0xFFFFFFFFFFFF) > (*(uint64_t*)pelem&0xFFFFFFFFFFFF)) return  1;
	else if((*(uint64_t*)pkey&0xFFFFFFFFFFFF) < (*(uint64_t*)pelem&0xFFFFFFFFFFFF)) return -1;
	else                                          return  0;
}*/

int main(/*int argc, char** argv*/) {
	float val;
	frac dec, sex, bim, sub, sev, doz, deg, idk; // *chef's kiss* best variable names
	char *strbuf0=nullptr;

        // print license
	printf("  Copyright (c) 2023, Sebastian (https://github.com/ProtoSebastian)\n\n");


	/*uint16_t vals=argc-1;
	uint16_t *bases=(uint16_t*)malloc(vals<<1);
	uint32_t *sco=(uint32_t*)malloc(vals<<2);
	uint64_t *len=(uint64_t*)malloc(vals<<3);
	for(int i=0;i<vals;i++) {
		bases[i]=stoi(argv[i+1]);
		sco[i]=((uint32_t)i<<16);
	}*/
	for(float a:{0.1f, 0.2f, 0.3f, 0.7f, 0.75f, 1.0f/3.0f, 1.0f/7.0f, 1.0f/17.0f, (float)M_PI}) { // tests
		val=a;
		printf("test:%f\n", val);

		bim=to_frac_bitmanip(val);
		dec=to_frac_base(val, 10);
		sex=to_frac_seximal(val);
		sub=to_frac_base(val, 17);
		sev=to_frac_base(val, 7);
		doz=to_frac_base(val, 12);
		idk=to_frac_base(val, 60);
		deg=to_frac_base(val, 360);

		printf("-bitman:%s (%f) | ", bim.make_cstring(&strbuf0), bim.to_float());
		bim=bim.simplify();
		printf("%s (%f)\n", bim.make_cstring(&strbuf0), bim.to_float());

		printf("-deciml:%s (%f) | ", dec.make_cstring(&strbuf0), dec.to_float());
		dec=dec.simplify();
		printf("%s (%f)\n", dec.make_cstring(&strbuf0), dec.to_float());

		printf("-seximl:%s (%f) | ", sex.make_cstring(&strbuf0), sex.to_float());
		sex=sex.simplify();
		printf("%s (%f)\n", sex.make_cstring(&strbuf0), sex.to_float());

		printf("-dozenl:%s (%f) | ", doz.make_cstring(&strbuf0), doz.to_float());
		doz=doz.simplify();
		printf("%s (%f)\n", doz.make_cstring(&strbuf0), doz.to_float());

		printf("-subopt:%s (%f) | ", sub.make_cstring(&strbuf0), sub.to_float());
		sub=sub.simplify();
		printf("%s (%f)\n", sub.make_cstring(&strbuf0), sub.to_float());

		printf("-septim:%s (%f) | ", sev.make_cstring(&strbuf0), sev.to_float());
		sev=sev.simplify();
		printf("%s (%f)\n", sev.make_cstring(&strbuf0), sev.to_float());

		printf("-sixtyy:%s (%f) | ", idk.make_cstring(&strbuf0), idk.to_float());
		idk=idk.simplify();
		printf("%s (%f)\n", idk.make_cstring(&strbuf0), idk.to_float());

		printf("-degree:%s (%f) | ", deg.make_cstring(&strbuf0), deg.to_float());
		deg=deg.simplify();
		printf("%s (%f)\n\n", deg.make_cstring(&strbuf0), deg.to_float());

		/*
		for(int i=0;i<vals;i++) {
			you=to_frac_base(val, bases[i]);
			printf("-base-%i:%s (%f) | ", bases[i], you.make_cstring(&strbuf0), you.to_float());
			you=you.simplify();
			printf("%s (%f)\n", you.make_cstring(&strbuf0), you.to_float());
			len[i]=((you.num+you.den)&0xFFFFFFFFFFFF)|((uint64_t)i<<48);
		}
		qsort(len, vals, 8, rcompare_int48);
		printf("base-%i", bases[len[0]>>48]);
		sco[len[0]>>48]++;
		for(int i=1;i<vals&&((len[i]&0xFFFFFFFFFFFF)==(len[i-1]&0xFFFFFFFFFFFF));i++) {
			printf(" & %i", bases[len[i]>>48]);
			sco[len[i]>>48]++;
		}
		printf(" scored well\n");*/
	}
	/*qsort(sco, vals, 4, compare_int16);
	printf("Base-%i", bases[sco[0]>>16]);
	for(uint16_t i=1;i<vals&&((sco[i]&0xFFFF)==(sco[i-1]&0xFFFF));i++) {
		printf(" & %i", bases[sco[i]>>16]);
	}
	printf(" was best\n");
	free(len);
	free(sco);*/
	free(strbuf0);

	return 0;
}
